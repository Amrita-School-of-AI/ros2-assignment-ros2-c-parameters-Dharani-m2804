#include "rclcpp/rclcpp.hpp"

class ParamNode : public rclcpp::Node
{
public:
    ParamNode() : Node("param_node")
    {
        // Declare parameters with default values
        this->declare_parameter<std::string>("robot_name", "ROS2Bot");
        this->declare_parameter<double>("max_speed", 1.5);
        this->declare_parameter<bool>("enabled", true);

        // Get parameter values
        std::string robot_name = this->get_parameter("robot_name").as_string();
        double max_speed = this->get_parameter("max_speed").as_double();
        bool enabled = this->get_parameter("enabled").as_bool();

        RCLCPP_INFO(this->get_logger(),
                    "Robot: %s, Max Speed: %f, Enabled: %s",
                    robot_name.c_str(),
                    max_speed,
                    enabled ? "true" : "false");
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ParamNode>());
    rclcpp::shutdown();
    return 0;
}

