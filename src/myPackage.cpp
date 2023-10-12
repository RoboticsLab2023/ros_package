#include "my_package/myPackage.h"

// STD
#include <string>

MyPackage::MyPackage(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
  if (!readParameters()) {
    ROS_ERROR("Could not read parameters.");
    ros::requestShutdown();
  }
  subscriber_ = nodeHandle_.subscribe(subscriberTopic_, 1,
                                      &MyPackage::topicCallback, this);

  ROS_INFO("Successfully launched node.");
}

MyPackage::~MyPackage()
{
}

bool MyPackage::readParameters()
{
  if (!nodeHandle_.getParam("subscriber_topic", subscriberTopic_)) return false;
  return true;
}

void MyPackage::topicCallback(const std_msgs::String& message)
{
  ROS_INFO("I heard: '%s'", message.data.c_str());
}
