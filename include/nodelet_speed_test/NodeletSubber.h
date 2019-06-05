#ifndef NODELET_SUBBER_CLASS_SRC_NODELET_SUBBER_CLASS_H_
#define NODELET_SUBBER_CLASS_SRC_NODELET_SUBBER_CLASS_H_

#include <nodelet/nodelet.h>
#include "sensor_msgs/Image.h"
#include <sensor_msgs/image_encodings.h>
#include <ros/ros.h>

namespace nodelet_speed_test
{
  class NodeletSubber : public nodelet::Nodelet
  {
  public:
    virtual void onInit();
    void callback(const sensor_msgs::Image& image);
  private:
    ros::Subscriber sub;
  };
}

#endif
