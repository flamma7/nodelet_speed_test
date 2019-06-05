/*
Initialize the sub, queue size of 10
Record the time of the first image
Record time of last image, print out the difference

I should try sending the full image first, then try just sending the pointer??
 */
#include "ros/ros.h"
#include "ros/console.h"
#include "sensor_msgs/Image.h"

int num_images;
ros::Time start;
ros::Time end;

void callback(const sensor_msgs::Image& image)
{
  if(num_images == 0)
  {
    start = ros::Time::now();
  }else if(num_images == 10)
  {
    ros::Duration time_taken = ros::Time::now() - start;
    ROS_INFO("Received 10 images!");    
    ROS_INFO("Time taken: %f", time_taken.toSec());
  }
  num_images++;
  ROS_INFO("Received image");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "subber");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("images", 20, callback);
  num_images = 0;
  ROS_INFO("Starting Regular Subscription Node");

  ros::spin();
  return 0;
}
