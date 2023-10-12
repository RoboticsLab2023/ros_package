// ROS
#include <ros/ros.h>
#include "std_msgs/String.h"


/*!
 * Main class for the node to handle the ROS interfacing.
 */
class MyPackage
{
 public:
  /*!
   * Constructor.
   * @param nodeHandle the ROS node handle.
   */
  MyPackage(ros::NodeHandle& nodeHandle);

  /*!
   * Destructor.
   */
  virtual ~MyPackage();

 private:
  /*!
   * Reads and verifies the ROS parameters.
   * @return true if successful.
   */
  bool readParameters();

  /*!
   * ROS topic callback method.
   * @param message the received message.
   */
  void topicCallback(const std_msgs ::String& message);

  //! ROS node handle.
  ros::NodeHandle& nodeHandle_;

  //! ROS topic subscriber.
  ros::Subscriber subscriber_;

  //! ROS topic name to subscribe to.
  std::string subscriberTopic_;
  
};