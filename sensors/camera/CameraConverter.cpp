#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>  // replace this with actual ROS 2 Camera message
#include <boost/asio.hpp>
#include <proto_messages/CameraSensor.pb.h>  // assuming this is your Protobuf message

using boost::asio::ip::tcp;

class CameraConverter : public rclcpp::Node {
private:
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription;
    boost::asio::io_service io_service;
    tcp::socket socket;

public:
    CameraConverter() : Node("camera_converter"), socket(io_service) {
        subscription = this->create_subscription<sensor_msgs::msg::Image>(
            "camera_topic",
            10,
            std::bind(&CameraConverter::listenerCallback, this, std::placeholders::_1)
        );
        
        tcp::resolver resolver(io_service);
        boost::asio::connect(socket, resolver.resolve("localhost", "5000"));
    }

    void listenerCallback(const sensor_msgs::msg::Image::SharedPtr msg) {
        proto_messages::CameraSensor cameraProto;
        
        // Convert data
        // Set the actual config object here
        cameraProto.set_frame_number(std::stoi(msg->header.frame_id));  // assuming frame_number maps to frame_id
        cameraProto.set_pixels(msg->data.data(), msg->data.size());  // assuming pixels map to data

        RCLCPP_INFO(this->get_logger(), "Converted Camera message: %s", cameraProto.DebugString().c_str());

        // Sending the message over socket
        std::string data = cameraProto.SerializeAsString();
        boost::asio::write(socket, boost::asio::buffer(data));
    }
};

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CameraConverter>());
    rclcpp::shutdown();
    return 0;
}
