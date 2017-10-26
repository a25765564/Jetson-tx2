/*
 * pthread.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: passager
 */

#include "pthread.h"

static __inline
int tty_reset(void)
{
        if (tcsetattr(STDIN_FILENO, TCSANOW, &ori_attr) != 0)
                return -1;

        return 0;
}

static __inline
int tty_set(void)
{

        if ( tcgetattr(STDIN_FILENO, &ori_attr) )
                return -1;

        memcpy(&cur_attr, &ori_attr, sizeof(cur_attr) );
        cur_attr.c_lflag &= ~ICANON;
//        cur_attr.c_lflag |= ECHO;
        cur_attr.c_lflag &= ~ECHO;
        cur_attr.c_cc[VMIN] = 1;
        cur_attr.c_cc[VTIME] = 0;

        if (tcsetattr(STDIN_FILENO, TCSANOW, &cur_attr) != 0)
                return -1;

        return 0;
}

static __inline
int kbhit(void)
{

        fd_set rfds;
        struct timeval tv;
        int retval;

        /* Watch stdin (fd 0) to see when it has input. */
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        /* Wait up to five seconds. */
        tv.tv_sec  = 0;
        tv.tv_usec = 0;

        retval = select(1, &rfds, NULL, NULL, &tv);
        /* Don't rely on the value of tv now! */

        if (retval == -1) {
                perror("select()");
                return 0;
        } else if (retval)
                return 1;
        /* FD_ISSET(0, &rfds) will be true. */
        else
                return 0;
        return 0;
}

void *thread(void *arg)
{
    int tty_set_flag;
    tty_set_flag = tty_set();
    while(1) {

        if( kbhit() ) {
            const int key = getchar();
            printf("%c pressed\n", key);
            //检测到'c'则标志位置1
            if(key == 'c')
                flag=1;
            //检测到'q'则退出程序
            if(key == 'q')
                exit(0);
                break;
        } else {
//              fprintf(stderr, "<no key detected>\n");
        }
    }

    if(tty_set_flag == 0)
            tty_reset();
    return 0;
}