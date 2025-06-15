#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <internal/syscall.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec time1, time2;

    time1.tv_sec = seconds;
    time1.tv_nsec = 0;

    if (nanosleep(&time1, &time2) == -1) {
        return time2.tv_sec;
    }

    return 0;
}

