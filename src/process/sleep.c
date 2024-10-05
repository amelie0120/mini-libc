#include <time.h>
#include <internal/syscall.h>
#include <stddef.h>
#include <errno.h>
//#include <stdlib.h>

unsigned int sleep(unsigned int seconds){
    struct timespec t1;
    t1.tv_sec = seconds;
    t1.tv_nsec = 0;


    while (nanosleep(&t1, &t1) == -1) {
        if (errno == EINTR) {
            continue;
        } else {
            return t1.tv_sec;
        }
    }

    return 0;
}

