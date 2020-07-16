#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
futimes (int fd, struct timespec times[2])
{
    return futimens(fd, times);
}
