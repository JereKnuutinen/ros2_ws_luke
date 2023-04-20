#include <cstring>
#include <iostream>
#include <string>

#include <rclcpp/rclcpp.hpp>

#include <string>
#include <linux/can.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <cstring> 
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can/raw.h>
//#include <libsocketcan.h>
#include <linux/can/bcm.h>
#include <linux/sockios.h>

#include "std_msgs/msg/string.hpp"
#include "custom_msgs/msg/isobus.hpp" 
#include "ISOBUSframe.hpp"
#include "NMEA2000_node.hpp"
#include "ISOBUSTractor.hpp"

struct CanFrame {
  uint32_t id = 0;
  uint8_t len = 0;
  uint8_t flags = 0;
  uint8_t data[8];
};

class Can : public rclcpp::Node {

 public: 
  Can() : Node("minimal_publisher") {
    publisher_ = this->create_publisher<custom_msgs::msg::Isobus>("Isobus", 10);
    NMEA2000_parser_ = std::make_shared<NMEA2000Parser>();
    Isobus_parser_ = std::make_shared<IsobusTractor>();

  }

  bool init(const std::string& dev) {
    m_socket = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (m_socket < 0) {
      std::cout << "eka error" << std::endl;
      perror("Failed to create CAN socket");
      return false;
    }

    // const char* cmd = "sudo ip link set vcan0 type can bitrate 250000";
    // int ret = system(cmd);
    // if (ret == -1) {
    //   perror("Failed to set bitrate");
    //   return false;
    // }

    struct sockaddr_can addr;
    struct ifreq ifr;

    std::strcpy(ifr.ifr_name, dev.c_str());

    if (ioctl(m_socket, SIOCGIFINDEX, &ifr) == -1) {
      std::cout << "toka error" << std::endl;

      perror("Failed to get CAN interface index");
      close(m_socket);
      return false;
    }

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    if (bind(m_socket, reinterpret_cast<struct sockaddr*>(&addr), sizeof(addr)) == -1) {
            std::cout << "kolmas error" << std::endl;

      perror("Failed to bind CAN socket to interface");
      close(m_socket);
      return false;
    }

    return true;
  }

  bool processReceivedFrames(CanFrame& msg) {
    // struct canfd_frame frame;
    // //struct can_frame frame;
    // auto nbytes = read(m_socket, &frame, sizeof(struct canfd_frame));
    // struct timeval tv;
    // ioctl(m_socket, SIOCGSTAMP, &tv);
    struct sockaddr_can addr;
    struct ifreq ifr;
    socklen_t len = sizeof(addr);
    struct can_frame frame;

    auto nbytes = recvfrom(m_socket, &frame, sizeof(struct can_frame),
                      0, (struct sockaddr*)&addr, &len);

    /* get interface name of the received CAN frame */
    ifr.ifr_ifindex = addr.can_ifindex;
    ioctl(m_socket, SIOCGIFNAME, &ifr);
    //printf("Received a CAN frame from interface %s", ifr.ifr_name);

    struct timeval tv;
    ioctl(m_socket, SIOCGSTAMP, &tv);
    //printf("Timestamp can: %ld seconds, %ld microseconds\n", tv.tv_sec, tv.tv_usec);
    //RCLCPP_INFO_STREAM(get_logger(), "  rclcpp::Clock{RCL_SYSTEM_TIME}.now() sec: " << rclcpp::Clock{RCL_SYSTEM_TIME}.now().seconds());  // Get the current time using rclcpp::Clock
    //RCLCPP_INFO_STREAM(get_logger(), "  rclcpp::Clock{RCL_SYSTEM_TIME}.now() nao: " << rclcpp::Clock{RCL_SYSTEM_TIME}.now().nanoseconds());  // Get the current time using rclcpp::Clock

    if (nbytes < 0) {
      std::cout << "nwljäs error" << std::endl;

      perror("can raw socket read");
      return false;
    }

    if (nbytes < sizeof(struct can_frame)) {
      std::cout << "viies error" << std::endl;

      fprintf(stderr, "read: incomplete CAN frame\n");
      return false;
    }

    ISOBUSFrame iframe(frame.can_id, frame.data, sizeof(frame.data));
    //Idea how to publish
    //your_package_name::ISOBUSFrameMsg isobus_frame_msg;
    // isobus_frame_msg.priority = iframe.priority;
    // isobus_frame_msg.page = iframe.page;
    // isobus_frame_msg.PGN = iframe.PGN;
    // isobus_frame_msg.SA = iframe.SA;
    // isobus_frame_msg.PF = iframe.PF;
    // isobus_frame_msg.PS = iframe.PS;
    // memcpy(isobus_frame_msg.data.data(), iframe.data, sizeof(iframe.data));
    // pub.publish(isobus_frame_msg);
    auto isobus_frame_msg = custom_msgs::msg::Isobus();

    // Populate the timestamp fields in the custom ROS 2 message header
    isobus_frame_msg.header.stamp.sec = tv.tv_sec; // seconds
    isobus_frame_msg.header.stamp.nanosec = tv.tv_usec * 1000; // convert microsecods to nano 
    isobus_frame_msg.priority = iframe.priority;
    isobus_frame_msg.page = iframe.page;
    isobus_frame_msg.pgn = iframe.PGN;
    isobus_frame_msg.sa = iframe.SA;
    isobus_frame_msg.pf = iframe.PF;
    isobus_frame_msg.ps = iframe.PS;
    memcpy(isobus_frame_msg.data.data(), iframe.data, sizeof(iframe.data));

    msg.id = frame.can_id;
    // msg.len = frame.len;
    //msg.flags = frame.flags;
    //memcpy(msg.data, frame.data, len);
    NMEA2000_parser_->Nmea2000_parser(isobus_frame_msg);
    Isobus_parser_->Isobus_parser(isobus_frame_msg);
    return true;
  }

  ~Can() { 
   close(m_socket); 
  }

 private:
  int m_socket = -1;
  rclcpp::Publisher<custom_msgs::msg::Isobus>::SharedPtr publisher_;



  std::shared_ptr<NMEA2000Parser> NMEA2000_parser_;
  std::shared_ptr<IsobusTractor> Isobus_parser_;
};

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);

  auto node = rclcpp::Node::make_shared("can_subscriber");

  Can sockat_can;
  sockat_can.init("can0");
  CanFrame fr;

  while (rclcpp::ok()) {
    //std::cout << "pyörii" << std::endl;
    if (sockat_can.processReceivedFrames(fr)) {
      //std::cout << "pyörii2" << std::endl;
      //RCLCPP_INFO(node->get_logger(), "len %d byte, id: %d, data: %02x %x %02x %02x %02x %02x %02x %02x", fr.len,
        //           fr.id, fr.data[0], fr.data[1], fr.data[2], fr.data[3], fr.data[4], fr.data[5], fr.data[6], fr.data[7]);

    }
    rclcpp::spin_some(node);
        //loop_rate.sleep();

  }

  rclcpp::shutdown();
  return 0;
}
