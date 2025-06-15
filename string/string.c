// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *dest = destination;
    while ((*dest++ = *source++))
		;

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
    long unsigned int i;
    char *temp;
    temp = destination;
    for (i = 1; i <= len; i++)
        *destination++ = *source++;
    return temp;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *dest = destination;
    while (*dest)
        dest++;
    while ((*dest++ = *source++))
        ;

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *dest = destination;
    while (*dest)
        dest++;
    while (len-- > 0)
    {
        if ((*dest++ = *source++) == '\0')
            break;
    }
    *dest = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	 while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return (unsigned char)*str1 - (unsigned char)*str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	 while (len > 0 && *str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
        len--;
    }

    if (len == 0 || (*str1 == *str2))
        return 0;
    else
        return (unsigned char)*str1 - (unsigned char)*str2;
}

size_t strlen(const char *str)
{
	size_t len = 0;
    while (*str != '\0') {
        str++;
        len++;
    }
    return len;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while (*str != '\0') {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *last_occurrence = NULL;
    while (*str != '\0') {
        if (*str == (char)c) {
            last_occurrence = (char *)str;
        }
        str++;
    }
    return last_occurrence;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	size_t needle_len = strlen(needle);
    while (*haystack != '\0') {
        if (strncmp(haystack, needle, needle_len) == 0) {
            return (char *)haystack;
        }
        haystack++;
    }
    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *last_occurrence = NULL;
    size_t needle_len = strlen(needle);
    while (*haystack != '\0') {
        if (strncmp(haystack, needle, needle_len) == 0) {
            last_occurrence = (char *)haystack;
        }
        haystack++;
    }
    return last_occurrence;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination;
    const char *src = (const char *)source;
    while (num--) {
        *dest = *src;
        dest++;
        src++;
    }
    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
    const char *src = (const char *)source;
    if (dest > src) {
        while (num--) {
            dest[num] = src[num];
        }
    } else if (dest < src) {
        while (num--) {
            *dest = *src;
            dest++;
            src++;
        }
    }
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;

    while (num--)
    {
        if (*p1 != *p2)
            return (*p1 - *p2);
        p1++;
        p2++;
    }

    return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *p = (unsigned char *)source;
    unsigned char v = (unsigned char)value;

    while (num--)
    {
        *p = v;
        p++;
    }

    return source;
}
