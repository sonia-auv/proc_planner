// Copyright 2020 The MathWorks, Inc.
#ifndef _MLROSCPP_SUB_H_
#define _MLROSCPP_SUB_H_

#include <iostream>
#include <ros/ros.h>
#include "ros_structmsg_conversion.h" // For msg2struct()

template <class MLCoderSubscriber, class MsgType, class StructType>
class MATLABSubscriber {
public:
    MATLABSubscriber(MLCoderSubscriber* mlSubPtr, MsgType* msgPtr, StructType* structPtr): mlSubPtr_(mlSubPtr), structPtr_(structPtr) {}
            
    void createSubscriber(const char* mlTopic, size_t mlTopicSize, uint32_t queueSize) {
        std::string topic(mlTopic, mlTopicSize);
        ros::NodeHandle nh;
        
        // Subscribe to given topic and set callback
        sub_ = nh.subscribe(topic, queueSize, &MATLABSubscriber::subscriberCallback, this, ros::TransportHints().tcpNoDelay(true));
    }
            
    void subscriberCallback(const boost::shared_ptr<MsgType const>& msgPtr) {
        mlSubPtr_->lock();
        lastMsgPtr_ = msgPtr; // copy the shared_ptr 
        msg2struct(structPtr_, lastMsgPtr_.get());
        mlSubPtr_->unlock();
        mlSubPtr_->callback(); // Call rossubscriber callback function
    }
            
private:
    MLCoderSubscriber* mlSubPtr_;
    StructType *structPtr_;
    ros::Subscriber sub_;
    boost::shared_ptr<MsgType const> lastMsgPtr_;
};


// Maker function to create a MATLABSubscriber object using CTAD 
template <class MLCoderSubscriber, class MsgType, class StructType>
MATLABSubscriber<MLCoderSubscriber, MsgType, StructType>* make_subscriber(MLCoderSubscriber* mlSubPtr, MsgType* msgPtr, StructType* structPtr)
{
    return(new MATLABSubscriber<MLCoderSubscriber, MsgType, StructType>(mlSubPtr, msgPtr, structPtr));
};

/**
* Function to get status text.
*/
void getStatusText(bool status, char* mlStatusText) {
    if(status) {
        const char* cStatusText_ = "success";
        size_t mlStatusTextLen = strlen(cStatusText_);
        std::strncpy(mlStatusText, cStatusText_, mlStatusTextLen);
        mlStatusText[mlStatusTextLen] = 0;

    } else {
        const char* cStatusText_ = "timeout";
        size_t mlStatusTextLen = strlen(cStatusText_);
        std::strncpy(mlStatusText, cStatusText_, mlStatusTextLen);
        mlStatusText[mlStatusTextLen] = 0;
    }
}

#endif
