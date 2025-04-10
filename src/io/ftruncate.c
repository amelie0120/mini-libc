// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	int ret = syscall(__NR_ftruncate, fd, length);

	if (ret >= 0){
		return ret;
	}

	errno = -ret;
	return -1;
}
