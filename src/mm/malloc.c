// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if(ptr != MAP_FAILED){
		mem_list_add(ptr, size);
    	return (void *)ptr;
  }

	return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */

	void *ptr = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if(ptr != MAP_FAILED){
    	return (void *)ptr;
  }
	return NULL;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */

	if (ptr == NULL)
	return;
	struct mem_list *entry = mem_list_find(ptr);
    if (entry) {
        munmap(entry->start, entry->len);
		mem_list_del(entry->start);
	}
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	void *pointer = mmap(ptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if(pointer != MAP_FAILED){
    	return (void *)pointer;
  }
	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	void *pointer = mmap(ptr, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if(pointer != MAP_FAILED){
    	return (void *)pointer;
  }
	return NULL;
}
