// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	va_list list;
	va_start(list, flags);

	while (1){
		int flag = va_arg(list, int);
		if (flag == 0) break;
	}
	va_end(list);

	int ret = syscall(__NR_open, filename, flags);

	if (ret >= 0){
		return ret;
	}

	errno = -ret;

	return -1;
}
