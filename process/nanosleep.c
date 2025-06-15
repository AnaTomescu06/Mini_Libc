
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <internal/syscall.h>


int nanosleep(const struct timespec *time1, struct timespec *time2) {
    return syscall(__NR_nanosleep, time1, time2);
}


