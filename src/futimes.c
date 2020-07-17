#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
futimes (int fd, struct timeval tv[2])
{
    struct timespec times[2] = {
        { .tv_sec = tv[0].tv_sec, .tv_nsec = tv[0].tv_usec * 1000 },
        { .tv_sec = tv[1].tv_sec, .tv_nsec = tv[1].tv_usec * 1000 }
    };
    return futimens(fd, times);
}
