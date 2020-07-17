#ifndef LINUX_COMPAT_H
#define LINUX_COMPAT_H

#include <time.h>

int futimes(int, struct timeval *);
time_t timegm(struct tm *);
char *getprogname();
/* the function is in libc.a, but it is not defined in any header file */
int sethostname(char *, int);

#endif
