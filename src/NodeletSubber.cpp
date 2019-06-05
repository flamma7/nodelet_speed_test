#include <pluginlib/class_list_macros.h>
#include <nodelet_speed_test/NodeletSubber.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "sensor_msgs/Image.h"
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <ros/ros.h>

namespace nodelet_speed_test
{
  void NodeletSubber::callback(const sensor_msgs::Image& image) // maybe add const ptr here?
  {
    NODELET_INFO("Received Image!");
  }

  void NodeletSubber::onInit()
  {
    NODELET_INFO("Initializing the nodelet subber");
    ros::NodeHandle& n = getMTNodeHandle();
    sub = n.subscribe("images", 20, &NodeletSubber::callback, this);
    NODELET_INFO("Nodelet Subber Ready");
  }
}
PLUGINLIB_EXPORT_CLASS(nodelet_speed_test::NodeletSubber, nodelet::Nodelet);
