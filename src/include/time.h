#ifndef TIME_H
#define TIME_H

//#include <internal/types.h>

typedef long time_t;

struct timespec {
           time_t tv_sec;
           long tv_nsec;
};

int nanosleep(const struct timespec *t1, struct timespec *t2);

#endif
