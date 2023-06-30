#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "boost/asio.hpp"

using boost::asio::ip::tcp;

class IMUSensor : public rclcpp::Node, public SensorInterface<proto_messages::IMUSensor> {
private:
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr m_subscriber;
  boost::asio::io_service io_service;
  tcp::socket socket;

public:
  IMUSensor() : Node("IMUSensor"), SensorInterface(SensorType::IMU), socket(io_service) {
    m_subscriber = this->create_subscription<sensor_msgs::msg::Imu>(
        "imu_topic",
        10,
        std::bind(&IMUSensor::imuCallback, this, std::placeholders::_1));

    tcp::resolver resolver(io_service);
    boost::asio::connect(socket, resolver.resolve("127.0.0.1", "your_port"));
  }

  virtual ~IMUSensor() = default;

  void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg) {
    proto_messages::IMUSensor imuSensorData;

    // Convert ROS2 IMU message to protobuf...

    // Write to socket
    boost::asio::write(socket, boost::asio::buffer(imuSensorData.SerializeAsString()));

    // Notify newData
    newData(imuSensorData);
  }
};
