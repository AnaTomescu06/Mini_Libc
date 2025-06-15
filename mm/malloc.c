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
	if (size == 0) {
        return NULL;
    }

    void* memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (memory == MAP_FAILED) {
        return NULL;
    }

    mem_list_add(memory, size);
    return memory;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total_size = nmemb * size;
    void* ptr = malloc(total_size);

    if (ptr != NULL) {
        memset(ptr, 0, total_size);
    }

    return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr != NULL) {
        struct mem_list *block = mem_list_find(ptr);

        if (block != NULL) {
            size_t block_size = block->len;
            mem_list_del(ptr);

            munmap(ptr, block_size);
        }
    }
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    void* new_ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (new_ptr == MAP_FAILED) {
        return NULL;
    }

    memcpy(new_ptr, ptr, size);
    munmap(ptr, 0);

    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t total_size = nmemb * size;
    return realloc(ptr, total_size);
}
