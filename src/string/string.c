// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	if (source == NULL)
		return NULL;
	int i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	int n = len;

	int i = 0;
	while (source[i] != '\0' && i < n)
	{
		destination[i] = source[i];
		i++;
	}
    if (i == n){
        while (destination[n] != '\0')
            n++;
        destination[n] = '\0';
    } else {
		destination[i] = '\0';
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	if (source != NULL){
		int i1 = 0;
		while (destination[i1] != '\0')
			i1++;
		int i2 = 0;
		while (source[i2] != '\0')
		{
			destination[i1++] = source[i2++];
		}
		destination[i1] = '\0';
	}
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int n = len;
	if (source != NULL){
		int i1 = 0;
		while (destination[i1] != '\0')
			i1++;
		int i2 = 0;
		while (source[i2] != '\0' && i2 < n)
		{
			destination[i1++] = source[i2++];
		}
		destination[i1] = '\0';
	}
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	if (str1 == NULL)
	return -1;
	if (str2 == NULL)
	return 1;

	int i = 0;
	while (str1[i] != '\0' && str2[i] != '\0'){
		if (str1[i] > str2[i])
		return 1;
		if (str1[i] < str2[i])
		return -1;
		i++;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
		return 0;
	else if (str2[i] == '\0')
		return 1;

	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	int i = 0, n = len;
	if (str1 == NULL)
	return -1;
	if (str2 == NULL)
	return 1;
	while (i < n && str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] > str2[i])
		return 1;
		if (str1[i] < str2[i])
		return -1;
		i++;
	}
	if (i == n)
		return 0;

	if (str2[i] == '\0')
		return 1;

	return -1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	if (str == NULL){
    	return NULL;
	}
    while ((*str) != '\0' && (*str) != c)
    	str++;

    if ((*str) != '\0'){
        return (char *)str;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	if (str == NULL)
    	return NULL;

	int n = 0;
    while ((*str) != '\0'){
        str++;
        n++;
    }

	while(n > 0 && (*str) != c){
        str--;
        n--;
    }

    if ((*str) == c){
        return (char *)str;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	if  (haystack == NULL)
    return NULL;

    while ((*haystack) != '\0' && (*needle) != '\0')
    {
        int poz_mutate = 0;
        while ((*needle) != '\0' && (*haystack) != '\0' && (*haystack) == (*needle))
        {
            needle++;
            haystack++;
            poz_mutate++;
        }
        if ((*needle) == '\0')
        {
            while (poz_mutate > 0)
            {
                haystack--;
                poz_mutate--;
            }
            return (char *)haystack;
        }

        while (poz_mutate > 0)
            {
                needle--;
                haystack--;
                poz_mutate--;
            }

        haystack++;
    }
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	 if  (haystack == NULL)
    return NULL;

    int len_haystack = 0;
    int len_needle = 0;

    while ((*haystack) != '\0')
    {
        haystack++;
        len_haystack++;
    }
    haystack--;
    while ((*needle) != '\0')
    {
        needle++;
        len_needle++;
    }
    needle--;

    while (len_haystack > 0 && len_needle > 0)
    {
        int poz_mutate = 0;
        while (len_needle > 0 && len_haystack > 0 && (*haystack) == (*needle))
        {
            needle--;
            haystack--;
            poz_mutate++;
            len_needle--;
            len_haystack--;
        }

        if (len_needle == 0)
        {
            haystack++;
            return (char *)haystack;
        }

        while (poz_mutate > 0)
            {
                needle++;
                haystack++;
                len_haystack++;
                len_needle++;
                poz_mutate--;
            }

        haystack--;
        len_haystack--;
    }
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	int n = num;
	char *str1 = destination;
	const char *str2 = source;

	int i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *s1 = destination;
	const char *s2 = source;
	size_t i = 0;
	while(i < num)
	{
		s1[i] = s2[i];
		i++;
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	size_t i = 0;
    const char* s1 = ptr1;
    const char* s2 = ptr2;
	while(i < num)
	{
		if (s1[i] < s2[i])
			return -1;
		if (s1[i] > s2[i])
			return 1;
		i++;
	}
	return 0;
	return -1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	size_t i = 0;
	char *s = source;
	while (i < num)
	{
		s[i] = value;
		i++;
	}
	return source;
}
