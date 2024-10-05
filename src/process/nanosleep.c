#include <time.h>
#include <errno.h>
#include <internal/syscall.h>


int nanosleep(const struct timespec *t1, struct timespec *t2){
    int ret = syscall(__NR_nanosleep, t1, t2);

	if (ret != -1){
		return ret;
	}

	return -1;
}
