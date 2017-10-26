/*
 * v4l2cap.h
 *
 *  Created on: Oct 26, 2017
 *      Author: passager
 */

#ifndef V4L2CAP_H_
#define V4L2CAP_H_

#include "common.hpp"

#define CLEAR(x) memset(&(x), 0, sizeof(x))

#define TRUE 1
#define FALSE 0

class V4L2Capture {
public:
    V4L2Capture(char *devName, int width, int height, int width_cap, int height_cap);
    virtual ~V4L2Capture();

    int openDevice();
    int closeDevice();
    int initDevice();
    int initDeviceCap();
    int startCapture();
    int stopCapture();
    int freeBuffers();
    int getFrame(void **,size_t *);
    int backFrame();
    int pre2cap();
    int cap2pre();
    int preBegin();
    int preEnd();

    int initBuffers();

    struct cam_buffer
    {
        void* start;
        unsigned int length;
    };
    char *devName;
    int widthCap;
    int heightCap;
    int width;
    int height;
    int fd_cam;
    cam_buffer *buffers;
    unsigned int n_buffers;
    int frameIndex;
};

#endif /* V4L2CAP_H_ */