#include <pluginlib/class_list_macros.h>
#include <nodelet_speed_test/NodeletPubber.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "sensor_msgs/Image.h"
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <ros/ros.h>

#define CV_LOAD_IMAGE_COLOR 1

namespace nodelet_speed_test
{
  void NodeletPubber::publish_images()
  {
    std::string imageNames[10];
    cv::Mat image;
    cv_bridge::CvImage img_bridge;
    std_msgs::Header header;
    header.seq = 1;
    header.stamp = ros::Time::now();
    sensor_msgs::Image img_msgs[10];
    imageNames[0] = "/home/luke/ros/robosub_ws/src/nodelet_speed_test/frame0120.jpg";
    imageNames[1] = "/home/luke/ros/robosub_ws/src/nodelet_speed_test/frame0121.jpg";
    imageNames[2] = "/home/luke/ros/robosub_ws/src/nodelet_speed_test/frame0122.jpg";
    imageNames[3] = "/home/luke/ros/robosub_ws/src/nodelet_speed_test/frame0123.jpg";
    imageNames[4] = "/home/luke/ros/robosub_ws/src/nodelet_speed_test/frame0124.jpg";
    imageNames[5] = "/home/luke/ros/robosub_ws/src/nodelet_speed_test/frame0125.jpg";
    imageNames[6] = "/home/luke/ros/robosub_ws/src/nodelet_speed_test/frame0126.jpg";
    imageNames[7] = "/home/luke/ros/robosub_ws/src/nodelet_speed_test/frame0127.jpg";
    imageNames[8] = "/home/luke/ros/robosub_ws/src/nodelet_speed_test/frame0128.jpg";
    imageNames[9] = "/home/luke/ros/robosub_ws/src/nodelet_speed_test/frame0129.jpg";
    for(int i = 0; i < 10; i++)
      {
	       image = cv::imread(imageNames[i], CV_LOAD_IMAGE_COLOR);
	       img_bridge = cv_bridge::CvImage(header, sensor_msgs::image_encodings::RGB8, image);
	       img_bridge.toImageMsg(img_msgs[i]);
      }
    NODELET_INFO("Loaded images");
    // ros::Rate r(10);
    ros::Duration(5).sleep();
    ros::Time start = ros::Time::now();
    NODELET_INFO("Publishing...");
    for(int j = 0; j < 10; j++)
      {
        pub.publish(img_msgs[j]);
  	    // r.sleep();
      }
    ros::Duration time_taken = ros::Time::now() - start;
    NODELET_INFO("Time taken %f", time_taken.toSec());
  }

  void NodeletPubber::callback(const std_msgs::Bool& start)
  {
    NODELET_INFO("Starting publishings.");
    this->publish_images();
  }
  void NodeletPubber::onInit()
  {
    NODELET_INFO("Initializing the nodelet pubber");
    ros::NodeHandle& n = getMTNodeHandle();
    pub = n.advertise<sensor_msgs::Image>("images", 20);
    sub = n.subscribe("start", 20, &NodeletPubber::callback, this);
    NODELET_INFO("Nodelet Pubber Ready!");
  }
}

PLUGINLIB_EXPORT_CLASS(nodelet_speed_test::NodeletPubber, nodelet::Nodelet);
