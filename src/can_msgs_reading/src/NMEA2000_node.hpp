
#include <cmath>
#include <iomanip>
#include <rclcpp/rclcpp.hpp>
#include "custom_msgs/msg/isobus.hpp" 
#include "std_msgs/msg/string.hpp"
#include <std_msgs/msg/header.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <geometry_msgs/msg/quaternion.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>


#define FAST_PACKET_DATA_SIZE 256

struct FastPacketData
{
    unsigned char	data[FAST_PACKET_DATA_SIZE];
    unsigned int	lenght;
    unsigned int	frame;
    unsigned int	seq;
};
using std::placeholders::_1;

class NMEA2000Parser : public rclcpp::Node
{
  public:
    NMEA2000Parser() : Node("NMEA2000")
    {
        IMU_publisher_ = this->create_publisher<sensor_msgs::msg::Imu>("Imu_messages", 10);
        GNSS_publisher_ = this->create_publisher<sensor_msgs::msg::NavSatFix>("GNSS_messages", 10);
        // GNSS Position Data
        PositionDate = 0;
        PositionTime = 0;
        latitude = 0;
        longitude = 0;
        altitude = 0;
        GPSType = 0;
        GPSFix = 0;
        satellites = 0;
        HDOP = 0;
        PDOP = 0;
        GeoidalSeparation = 0;

        // GNSS Pseudo Noise Statistics
        RMS_uncertainty = 0;
        STD_of_Major = 0;
        STD_of_Minor = 0;
        Orientation_of_Major = 0;
        STD_lat = 0;
        STD_lon = 0;
        STD_alt = 0;

        // COG & SOG, Rapid Update
        compass_rad = 0;
        speed_ms = 0;

        // Attidue (IMU)
        Yaw = 0;
        Pitch = 0;
        Roll = 0;

        GPS_OK = false;
        int incre = 0;
        // FastPacketData
        GNSS_Position_Data.lenght = 0;
        GNSS_Position_Data.frame = 0;
        GNSS_Position_Data.seq = 0;

        GNSS_PseudoNoiseStatistics.lenght = 0;
        GNSS_PseudoNoiseStatistics.frame = 0;
        GNSS_PseudoNoiseStatistics.seq = 0;

        //std::cout << "jee meni tähän" << std::endl;

        //subscription_ = this->create_subscription<custom_msgs::msg::Isobus>(
        //              "Isobus", 10, std::bind(&NMEA2000Subscriber::topic_callback, this, _1));


    }

  
    void Nmea2000_parser(custom_msgs::msg::Isobus msg)
    {
        switch(msg.pgn)
        {
            case 0xF119:	// Attitude
                    // Retrieve the timestamp from the header
                //int64_t timestamp_sec = msg.header.stamp.sec;
                //int64_t timestamp_nsec = msg.header.stamp.nanosec;

                // Print the timestamp
                printf("Timestamp: %ld seconds, %ld nanoseconds\n", msg.header.stamp.sec, msg.header.stamp.nanosec);

                //for(int i=0; i < (msg.data).size(); i++) {
                //    std::cout << "data[" << i << "] = " << static_cast<int>(msg.data[i]) << std::endl;
                //}
                Parse_Attitude((uint8_t*)msg.data.data(), msg.header);
                break;

            case 0xF801:	// Position, Rapid update
                Parse_PositionRapidUpdate((uint8_t*)msg.data.data(), msg.header);
                break;

            case 0xF802:	// COG & SOG, Rapid Update
                Parse_COG_SOG_RapidUpdate((uint8_t*)msg.data.data(), msg.header);
                break;

            case 0xF805:	// GNSS Position Data
                //std::cout << msg.pgn << std::endl;
                if (Parse_FastPacketProtocol((uint8_t*)msg.data.data(), &GNSS_Position_Data))
                    Parse_GNSS_Position(&GNSS_Position_Data, msg.header);
                break;

            case 0xFA06:	// GNSS Pseudo Noise Statistics
                //std::cout << msg.pgn << std::endl;
                if( Parse_FastPacketProtocol((uint8_t*)msg.data.data(), &GNSS_PseudoNoiseStatistics))
                    Parse_GNSS_PseudoNoiseStats(&GNSS_PseudoNoiseStatistics, msg.header);
                break;

            //default:
                //std::cout << msg.pgn << std::endl;
                //std::cout << "PNG not in switch case" << std::endl;;

        }
        #ifdef BERRYBOT
        if(integrity == 1 && GPSFix >= 4)
        #else
        if(GPSFix >= 4)
        #endif /* BERRYBOT */
        {
            if(!GPS_OK) {
                GPS_OK = true;
                std::cout << "NMEA2000: GPS signal OK" << std::endl;
                //cUIHandler::GetInstance().print(QString("NMEA2000: GPS signal OK"), UIHandler::INFO);
            }
        }
        else
        {
            if(GPS_OK) {
                GPS_OK = false;
                std::cout << "NMEA2000: GPS signal not accurate" << std::endl;
                //UIHandler::GetInstance().print(QString("NMEA2000: GPS signal is not accurate"), UIHandler::WARNING);
            }
        }

    }
    
    private:

    FastPacketData GNSS_Position_Data;
    FastPacketData GNSS_PseudoNoiseStatistics;



    int Parse_FastPacketProtocol(uint8_t*  msgData, struct FastPacketData *data) {
        unsigned int SeqCount = msgData[0] >> 5;
        unsigned int FrameCount = msgData[0] & 0x1F;
        incre = incre + 1;
        //std::cout << FrameCount << std::endl;
        //std::cout << data->frame << std::endl;
        //std::cout << incre << std::endl;
        if (FrameCount == 0)
        {
            data->seq = SeqCount;
            data->frame = 1;
            data->lenght = msgData[1];

            if(data->lenght > FAST_PACKET_DATA_SIZE)
            {
                //std::cout << "Error packet too big" << std::endl;
                // Error packet too big!
                data->lenght = 0;
            }
            else
            {
                //std::cout << "meni for" << std::endl;
                for(int i=0; i<6; i++)
                    data->data[i] = msgData[2+i];
            }
        }
        else if (data->frame > 0)
        {
            //std::cout << "meni else if" << std::endl;
            if( data->frame != FrameCount || data->seq != SeqCount)
            {
                std::cout << "Error frame dropped or seq mismathc" << std::endl;
                // Error frame dropped or seq mismathc
                data->frame = 0;
                data->lenght = 0;
            }
            else
            {
                for(int i=0; i<7; i++)
                {
                    unsigned int pos = 6 + (data->frame - 1) * 7 + i;
                    if (pos < data->lenght)
                        data->data[pos] = msgData[1+i];
                }
                //std::cout << data->lenght << std::endl;
                //std::cout << (13 + (data->frame - 1) * 7) << std::endl;
                if( (13 + (data->frame - 1) * 7) >= data->lenght)
                {
                    //std::cout << "returnaa1" << std::endl;
                    data->frame = 0;
                    return 1;
                }

                data->frame++;
            }
        }
        //std::cout << "meni tänne" << std::endl;
        return 0;
    }

    void Parse_GNSS_Position(struct FastPacketData *data, std_msgs::msg::Header headeri) {
        //std::cout << "parse" << std::endl;

        if(data->lenght < 43)
        {
            std::cout << "WRONG SIZE PACKET" << std::endl;
            // ERROR WRONG SIZE PACKET
            return;
        }

        // GNSS_SID = data->data[0]

        PositionDate = (int)(data->data[1] | (data->data[2] << 8));
        PositionTime = (double)(data->data[3] | (data->data[4] << 8) | (data->data[5] << 16) | (data->data[6] << 24)) * 1e-4;

        unsigned long long lat = 0;
        for (int i = 0; i < 8; i++)
            lat += ((unsigned long long)data->data[7 + i]) << (8 * i);

        latitude = (double)lat * 1e-16;

        unsigned long long lon = 0;
        for (int i = 0; i < 8; i++)
            lon += ((unsigned long long)data->data[15 + i]) << (8 * i);

        longitude = (double)lon * 1e-16;

        unsigned long long alt = 0;
        for (int i = 0; i < 8; i++)
            alt += ((unsigned long long)data->data[23 + i]) << (8 * i);

        altitude = (double)alt * 1e-6;

        GPSType = data->data[31] & 0xF;
        GPSFix = data->data[31] >> 4;

        #ifdef BERRYBOT
            integrity = data->data[32] & 0x03;

        #endif /* BERRYBOT */
        satellites = data->data[33];

        HDOP = (double)(data->data[34] | (data->data[35] << 8)) * 1e-2;
        PDOP = (double)(data->data[36] | (data->data[37] << 8)) * 1e-2;

        GeoidalSeparation = (double)(data->data[38] | (data->data[39] << 8) | (data->data[40] << 16) | (data->data[41] << 24)) * 1e-2;

        // REF STATIONS..
        //Implementoi GNSS publishus
        //Create sensor_msgs/Imu message
        sensor_msgs::msg::NavSatFix gnss_msg;
        gnss_msg.header.stamp = headeri.stamp;
        gnss_msg.latitude = latitude;
        gnss_msg.longitude = longitude;
        gnss_msg.altitude = altitude;

        GNSS_publisher_->publish(gnss_msg);

        std::cout << std::setprecision(13) << latitude << std::endl;
        std::cout << "GPS, longitude "<< longitude << std::endl;
        std::cout << "GPS, latitude "<< latitude << std::endl;
        std::cout << "GPS, altitude "<< altitude << std::endl;
        std::cout << "GPS, GPSType "<< GPSType << std::endl;
        std::cout << "GPS, GPSFix "<< GPSFix << std::endl;
        std::cout << "GPS, HDOP "<< HDOP << std::endl;
        std::cout << "GPS, PDOP "<< PDOP << std::endl;
    }

    void Parse_PositionRapidUpdate(uint8_t*  data, std_msgs::msg::Header stamp) {
        unsigned long long lat = 0;
        for (int i = 0; i < 4; i++)
            lat += ((unsigned long long)data[0 + i]) << (8 * i);

        unsigned long long lon = 0;
        for (int i = 0; i < 4; i++)
            lon += ((unsigned long long)data[4 + i]) << (8 * i);

        latitude = ((double)lat) * 1e-7;
        longitude = ((double)lon) * 1e-7;

        std::cout <<"GPS rapid " << std::endl;
        std::cout <<"GPS, latitude " << latitude << std::endl;
        std::cout << std::setprecision(13) << latitude << std::endl;
        std::cout <<"GPS, longitude " << longitude << std::endl;
    }

    void Parse_GNSS_PseudoNoiseStats(struct FastPacketData *data, std_msgs::msg::Header stamp) {
        if(data->lenght < 15)
        {
            // ERROR WRONG SIZE PACKET
            return;
        }

        // GNSS_SID = data->data[0]

        RMS_uncertainty = (double)(data->data[1] | (data->data[2] << 8)) * 1e-2;
        STD_of_Major = (double)(data->data[3] | (data->data[4] << 8)) * 1e-2;
        STD_of_Minor = (double)(data->data[5] | (data->data[6] << 8)) * 1e-2;
        Orientation_of_Major = (double)(data->data[7] | (data->data[8] << 8)) * 1e-4;
        STD_lat = (double)(data->data[9] | (data->data[10] << 8)) * 1e-2;
        STD_lon = (double)(data->data[11] | (data->data[12] << 8)) * 1e-2;
        STD_alt = (double)(data->data[13] | (data->data[14] << 8)) * 1e-2;
    }

    void Parse_COG_SOG_RapidUpdate(uint8_t* data, std_msgs::msg::Header stamp) {
        compass_rad = ((double)((unsigned short)(data[2] | (data[3] << 8)))) * 1e-4;
        speed_ms =((double)((unsigned short)(data[4] | (data[5] << 8)))) * 1e-2;
        std::cout <<"GPS rapid " << std::endl;
        std::cout << "GPS, compass_rad " <<  compass_rad << std::endl;
        std::cout << "GPS, speed_ms " << speed_ms << std::endl;


    }

    void Parse_Attitude(uint8_t* data, std_msgs::msg::Header headeri) {
        //GNSS_SID = data[0];
        std::cout << data[7] << std::endl;
        Yaw = (short)((data[1] << 0) | (data[2] << 8)) * 0.0001;
        Pitch = (short)((data[3] << 0) | (data[4] << 8)) * 0.0001;
        Roll = (short)((data[5] << 0) | (data[6] << 8)) * 0.0001;

        #ifdef BERRYBOT
        // Fix Yaw measurement to zero pointing east and position rotation is counter clockwise
        Yaw = -Yaw + M_PI/2;
        if(Yaw > M_PI)
        Yaw -= M_PI*2;
        #endif /* BERRYBOT */
        std::cout << "GPS , Yaw " << Yaw <<std::endl;
        std::cout << "GPS , Pitch " << Pitch <<std::endl;
        std::cout << "GPS , Roll " << Roll <<std::endl;
        // Create tf2::Quaternion object and set roll, pitch, yaw
        tf2::Quaternion quaternion;
        quaternion.setRPY(Roll, Pitch, Yaw);

        // Convert tf2::Quaternion to geometry_msgs/Quaternion
        geometry_msgs::msg::Quaternion ros_quaternion;
        tf2::convert(quaternion, ros_quaternion);

        // Print the resulting quaternion
        //RCLCPP_INFO(get_logger(), "Quaternion: x=%f, y=%f, z=%f, w=%f",
        //ros_quaternion.x, ros_quaternion.y, ros_quaternion.z, ros_quaternion.w);

        // Implementoi IMU publishus
        // Create sensor_msgs/Imu message
        sensor_msgs::msg::Imu imu_msg;
        imu_msg.header.stamp = headeri.stamp;
        imu_msg.orientation = ros_quaternion;
        IMU_publisher_->publish(imu_msg);

        //DVAR("GPS","Pitch",Pitch);
        //DVAR("GPS","Roll",Roll);
    }

    // GNSS Position Data
    int PositionDate;
    double PositionTime;
    double latitude;
    double longitude;
    double altitude;
    char GPSType;
    char GPSFix;
    #ifdef BERRYBOT
    char integrity;
    #endif /* BERRYBOT */
    int satellites;
    double HDOP;
    double PDOP;
    double GeoidalSeparation;

    // GNSS Pseudo Noise Statistics
    double RMS_uncertainty;
    double STD_of_Major;
    double STD_of_Minor;
    double Orientation_of_Major;
    double STD_lat;
    double STD_lon;
    double STD_alt;
    int incre;
    // COG & SOG, Rapid Update
    double compass_rad;
    double speed_ms;

    // Attidue (IMU)
    double Yaw;
    double Pitch;
    double Roll;

    bool GPS_OK;

    //rclcpp::Subscription<custom_msgs::msg::Isobus>::SharedPtr subscription_;
    rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr IMU_publisher_;
    rclcpp::Publisher<sensor_msgs::msg::NavSatFix>::SharedPtr GNSS_publisher_;

};
