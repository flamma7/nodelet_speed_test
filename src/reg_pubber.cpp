/* 
Loads 10 images
Initialize subs and pubs, publish queue_size should be 10
publish the 10 images

CONCLUSION:
Basically if there's no delay in the loop, the pipe is too big too quick, so nothing gets through

 */

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ros/ros.h"
#include "ros/console.h"
#include "sensor_msgs/Image.h"
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>



using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pubber");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<sensor_msgs::Image>("images", 20);

  string imageNames[10];
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

  Mat image;
  cv_bridge::CvImage img_bridge;
  std_msgs::Header header;
  header.seq = 1;
  header.stamp = ros::Time::now();
  sensor_msgs::Image img_msgs[10];
  
  ROS_INFO("Starting Regular Publisher Node");

  for(int i = 0; i < 10; i++)
    {
      image = imread(imageNames[i], CV_LOAD_IMAGE_COLOR);
      img_bridge = cv_bridge::CvImage(header, sensor_msgs::image_encodings::RGB8, image);
      img_bridge.toImageMsg(img_msgs[i]);
    }
  ROS_INFO("Loaded images");
  
  // namedWindow( "Display window", WINDOW_AUTOSIZE );
  // imshow( "Display window", image);
  // waitKey(0);

  ros::Time start = ros::Time::now();
  // ros::Rate r(10);
  for(int j = 0; j < 10; j++)
    {
      pub.publish(img_msgs[j]);
      // r.sleep();
    }
  ros::Duration time_taken = ros::Time::now() - start;
  ROS_INFO("Time taken %f", time_taken.toSec());

  // Load the 10 images into an array
  // Cycle through the 10 images and publish them
  // enter a delay in between publishing

  ROS_INFO("Exiting Publisher Node");
  return 0;
}
