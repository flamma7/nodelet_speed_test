#ifndef NODELET_PUBBER_CLASS_SRC_NODELET_PUBBER_CLASS_H_
#define NODELET_PUBBER_CLASS_SRC_NODELET_PUBBER_CLASS_H_

#include <nodelet/nodelet.h>
#include <ros/ros.h>
#include <std_msgs/Bool.h>

namespace nodelet_speed_test
{
  class NodeletPubber : public nodelet::Nodelet
  {
  public:
    virtual void onInit();
  private:
    void callback(const std_msgs::Bool& start);
    void publish_images();
    ros::Publisher pub;
    ros::Subscriber sub;
  };
}

#endif
