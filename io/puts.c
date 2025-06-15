// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>
#include <stdio.h>


int puts(const char *str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }

    ssize_t bytes_written = syscall(__NR_write, 1, str, count);

    if (bytes_written != count) {
        return -1;
    }

    char newline = '\n';
    bytes_written = syscall(__NR_write, 1, &newline, 1);

    if (bytes_written != 1) {
        return -1;
    }

    return count;
}
