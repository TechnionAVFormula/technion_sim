#include "boost/asio.hpp"

using boost::asio::ip::tcp;

class SocketSensorInterface : public SensorInterface<proto_messages::IMUSensor> {
private:
  boost::asio::io_service io_service;
  tcp::acceptor acceptor;
  tcp::socket socket;
  proto_messages::IMUSensor latest_data;

public:
  SocketSensorInterface() : SensorInterface(SensorType::IMU), acceptor(io_service, tcp::endpoint(tcp::v4(), "your_port")), socket(io_service) {
    acceptor.accept(socket);
  }

  virtual ~SocketSensorInterface() = default;

  void listen() {
    for (;;) {
      char buf[128];
      boost::system::error_code error;
      size_t len = socket.read_some(boost::asio::buffer(buf), error);
      if (!error) {
        proto_messages::IMUSensor imuSensorData;
        if (imuSensorData.ParseFromArray(buf, len)) {
          latest_data = imuSensorData;
        }
      }
    }
  }

  proto_messages::IMUSensor querySensorData() override {
    return latest_data;
  }
};
