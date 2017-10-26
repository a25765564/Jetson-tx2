/*
 * pthread.h
 *
 *  Created on: Oct 26, 2017
 *      Author: passager
 */

#ifndef PTHREAD_H_
#define PTHREAD_H_

#include "common.hpp"

static __inline
int tty_reset(void);

static __inline
int tty_set(void);

static __inline
int kbhit(void);

void *thread(void *arg);

static struct termios ori_attr, cur_attr;

extern uchar flag;

#endif /* PTHREAD_H_ */