#ifndef LINUX_COMPAT_H
#define LINUX_COMPAT_H

#include <sys/time.h>
#include <time.h>
#include <stdarg.h>

/*
 * Structure initializations for 'fake' FILE objects.
 */
#define	FAKE_FILE {				\
	._file = -1,				\
}

int futimes(int, struct timeval *);
time_t timegm(struct tm *);
char *getprogname();
/* the function is in libc.a, but it is not defined in any header file */
int sethostname(char *, int);
int vasprintf(char **, const char *, va_list);
int asprintf(char ** __restrict, char const * __restrict, ...);

#endif
