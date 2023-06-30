#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>  // replace this with actual ROS 2 GPS message
#include <boost/asio.hpp>
#include <proto_messages/GPSSensor.pb.h>  // assuming this is your Protobuf message

using boost::asio::ip::tcp;

class GPSConverter : public rclcpp::Node {
private:
    rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr subscription;
    boost::asio::io_service io_service;
    tcp::socket socket;

public:
    GPSConverter() : Node("gps_converter"), socket(io_service) {
        subscription = this->create_subscription<sensor_msgs::msg::NavSatFix>(
            "gps_topic",
            10,
            std::bind(&GPSConverter::listenerCallback, this, std::placeholders::_1)
        );
        
        tcp::resolver resolver(io_service);
        boost::asio::connect(socket, resolver.resolve("localhost", "5000"));
    }

    void listenerCallback(const sensor_msgs::msg::NavSatFix::SharedPtr msg) {
        proto_messages::GPSSensor gpsProto;
        
        // Convert data. This process depends on how you define your NavSatFix and GPSSensor messages.
        gpsProto.set_latitude(msg->latitude);
        gpsProto.set_longitude(msg->longitude);
        
        // Setting some random values as course, position, speed and config, adjust it based on your actual use case.
        gpsProto.set_course(0.0);
        auto* position = gpsProto.mutable_position();
        position->set_x(msg->latitude);
        position->set_y(msg->longitude);
        position->set_z(0.0);
        gpsProto.set_speed(0.0);
        // Set the actual config object here

        RCLCPP_INFO(this->get_logger(), "Converted GPS message: %s", gpsProto.DebugString().c_str());

        // Sending the message over socket
        std::string data = gpsProto.SerializeAsString();
        boost::asio::write(socket, boost::asio::buffer(data));
    }
}

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GPSConverter>());
    rclcpp::shutdown();
    return 0;
}
