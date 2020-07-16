#ifndef LINUX_COMPAT_H
#define LINUX_COMPAT_H

#include <time.h>

int futimes(int, struct timespec *);
time_t timegm(struct tm *);
char *getprogname();

#endif
