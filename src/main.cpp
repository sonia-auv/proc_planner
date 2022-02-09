#include "ros/ros.h"
#include<thread>
#include "proc_planner.h"

void threadFunction(void)
{
    proc_planner();
    ros::shutdown();
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "proc_planner");
    ros::NodeHandlePtr MLROSNodePtr = ros::NodeHandlePtr(new ros::NodeHandle);
    std::thread threadObj(threadFunction);

    ros::spin();
    threadObj.join();

    return 0;
}
