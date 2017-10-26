/*
 * common.hpp
 *
 *  Created on: Oct 26, 2017
 *      Author: passager
 */

#ifndef _COMMON_H_
#define _COMMON_H_

#ifdef __cplusplus
extern "C"{
#endif
#include <unistd.h>
#include <error.h>
#include <fcntl.h>
#include <pthread.h>
#include <termios.h>
#include <linux/videodev2.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
};
#endif

#include <iostream>
#include <iomanip>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

#endif /*_COMMON_H_ */