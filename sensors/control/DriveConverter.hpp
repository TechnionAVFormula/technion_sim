#ifndef DRIVE_CONVERTER_HPP
#define DRIVE_CONVERTER_HPP

#include <rclcpp/rclcpp.hpp>
#include <eufs_msgs/msg/chassis_command.hpp>  // replace this with actual ROS 2 Chassis Command message
#include <boost/asio.hpp>
#include <proto_messages/ActualDriveInstructions.pb.h>  // assuming this is your Protobuf message

using boost::asio::ip::tcp;

class DriveConverter : public rclcpp::Node {
private:
    rclcpp::Publisher<eufs_msgs::msg::ChassisCommand>::SharedPtr publisher;
    boost::asio::io_service io_service;
    tcp::acceptor acceptor;
    tcp::socket socket;

public:
    DriveConverter();

    void listen();
};

#endif // DRIVE_CONVERTER_HPP
