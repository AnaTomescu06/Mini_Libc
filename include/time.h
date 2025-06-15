/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __TIME_H__
#define __TIME_H__

#include <stddef.h>

typedef long time_t;
struct timespec {
    time_t tv_sec;
    time_t tv_nsec;
} timespec;

int nanosleep(const struct timespec *time1, struct timespec *time2);
unsigned int sleep(unsigned int seconds);

#endif
