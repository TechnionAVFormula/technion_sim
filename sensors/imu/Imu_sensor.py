import asyncio
import rclpy
from rclpy.node import Node
from proto import sesnsors_pb2 as sensors
from proto import common_pb2 as common # replace this with your proto messages Python module
import socket

from tf.transformations import euler_from_quaternion

class IMUSensor(Node):
    def __init__(self):
        super().__init__('IMUSensor')
        self.subscription = self.create_subscription(
            sensors.Imu,
            'imu_topic',
            self.imu_callback,
            10)
        self.subscription  # prevent unused variable warning

        # Network parameters
        self.HOST = '127.0.0.1'
        self.PORT = 12345  # replace with your port

        # Create a asyncio's loop and create a connection
        self.loop = asyncio.get_event_loop()
        self.loop.run_until_complete(self.create_connection())

    async def create_connection(self):
        self.reader, self.writer = await asyncio.open_connection(self.HOST, self.PORT)

    def imu_callback(self, ros_msg):
            # Create protobuf IMUSensor message
        proto_msg = IMUSensor()

        # Set IMUConfig in proto_msg
        proto_msg.config.sensor_id = 1  # replace 1 with actual sensor id

        # Set IMUMeasurments in proto_msg
        proto_msg.imu_measurments.acceleration.x = ros_msg.linear_acceleration.x
        proto_msg.imu_measurments.acceleration.y = ros_msg.linear_acceleration.y
        proto_msg.imu_measurments.acceleration.z = ros_msg.linear_acceleration.z

        proto_msg.imu_measurments.angular_velocity.x = ros_msg.angular_velocity.x
        proto_msg.imu_measurments.angular_velocity.y = ros_msg.angular_velocity.y
        proto_msg.imu_measurments.angular_velocity.z = ros_msg.angular_velocity.z

        proto_msg.imu_measurments.orientation.x = ros_msg.orientation.x
        proto_msg.imu_measurments.orientation.y = ros_msg.orientation.y
        proto_msg.imu_measurments.orientation.z = ros_msg.orientation.z

        # Assuming heading is in radians and equivalent to the yaw component in Quaternion form
        # Use conversion from quaternion to euler to get the yaw component
        _, _, yaw = euler_from_quaternion([ros_msg.orientation.x, ros_msg.orientation.y, ros_msg.orientation.z, ros_msg.orientation.w])
        proto_msg.imu_measurments.heading = yaw


        # Write to socket
        self.loop.run_until_complete(self.write_to_socket(proto_msg.SerializeToString()))

    async def write_to_socket(self, data):
        self.writer.write(data)
        await self.writer.drain()

    async def close_connection(self):
        self.writer.close()
        await self.writer.wait_closed()


def main(args=None):
    rclpy.init(args=args)
    imu_sensor = IMUSensor()

    try:
        rclpy.spin(imu_sensor)
    except KeyboardInterrupt:
        imu_sensor.loop.run_until_complete(imu_sensor.close_connection())
    finally:
        imu_sensor.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
