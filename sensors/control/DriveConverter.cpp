#include <rclcpp/rclcpp.hpp>
#include <eufs_msgs/msg/chassis_command.hpp>  // replace this with actual ROS 2 Chassis Command message
#include <boost/asio.hpp>
#include <proto_messages/ActualDriveInstructions.pb.h>  // assuming this is your Protobuf message
#include "DriveConverter.hpp"

using boost::asio::ip::tcp;


    DriveConverter::DriveConverter() : Node("drive_converter"), acceptor(io_service, tcp::endpoint(tcp::v4(), 5000)), socket(io_service) {
        publisher = this->create_publisher<eufs_msgs::msg::ChassisCommand>("chassis_topic", 10);
        acceptor.accept(socket);
    }

    void DriveConverter::listen() {
        for (;;) {
            char buf[128];
            boost::system::error_code error;
            size_t len = socket.read_some(boost::asio::buffer(buf), error);
            if (!error) {
                proto_messages::ActualDriveInstructions driveProto;
                if (driveProto.ParseFromArray(buf, len)) {
                    // Convert protobuf to ROS 2 message and publish it
                    auto msg = std::make_shared<eufs_msgs::msg::ChassisCommand>();
                    msg->throttle = driveProto.actual_gas(); // assuming actual_gas maps to throttle
                    msg->front_brake = driveProto.actual_brakes(); // assuming actual_brakes maps to front_brake
                    msg->steering = driveProto.actual_steering(); // assuming actual_steering maps to steering
                    publisher->publish(*msg);

                    RCLCPP_INFO(this->get_logger(), "Published ChassisCommand message: %s", msg->to_string().c_str());
                }
            }
        }
    }

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DriveConverter>();
    node->listen();
    rclcpp::shutdown();
    return 0;
}
