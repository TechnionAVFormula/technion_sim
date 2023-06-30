import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from eufs_msgs.msg import ChassisCommand

class ChassisCommandPublisher(Node):
    def __init__(self):
        super().__init__('chassis_command_publisher')
        self.publisher_ = self.create_publisher(ChassisCommand, 'chassis_command', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        msg = ChassisCommand()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "chassis_command_frame"
        msg.sender = "example_sender"
        msg.throttle = 0.5
        msg.steering = 0.1
        msg.front_brake = 0.0
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.sender)

def main(args=None):
    rclpy.init(args=args)

    chassis_command_publisher = ChassisCommandPublisher()

    rclpy.spin(chassis_command_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    chassis_command_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
