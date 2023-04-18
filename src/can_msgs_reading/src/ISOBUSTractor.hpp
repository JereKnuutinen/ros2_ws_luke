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

using std::placeholders::_1;

class IsobusTractor : public rclcpp::Node
{

  public:

    IsobusTractor() : Node("Isobus_Tractor")
    {
        groundspeed = 0;
        grounddistance = 0;

    }

    void Isobus_parser(custom_msgs::msg::Isobus msg) {
        if (msg.pgn == 0xFE49) {
             // ground speed
                std::cout<< "on menossaground speed parseriin" << std::endl;
                Parse_Ground_Speed((uint8_t*)msg.data.data(), msg.header);
        }
    }

    // ground speed
    void Parse_Ground_Speed(uint8_t* data, std_msgs::msg::Header headeri) {
        double temp;
        temp = ((data[0] << 0) | (data[1] << 8)) * 0.001;
        groundspeed = temp;
        //if ((imsg.data[7] & 0x03) == 0x01)
        //else if ((imsg.data[7] & 0x03) == 0x00)
            // groundspeed = -temp;
        //else
            // groundspeed = Double.NaN;

        temp = ((data[2] << 0) | (data[3] << 8) | (data[4] << 16) | (data[5] << 24)) * 0.001;
        grounddistance = temp;
        std::cout << "groundspeed: "<< groundspeed << std::endl;
        std::cout << "ground dis: "<< grounddistance << std::endl;

    }
      private:
        double groundspeed;
        double grounddistance;

};