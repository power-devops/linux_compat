#include <pthread.h>

int pthread_getthreadid_np(void) {
        struct __pthrdsinfo buf;
        pthread_t thr;
        int rc;
        int regsiz = 0;

        thr = pthread_self();
        rc = pthread_getthrds_np(&thr, PTHRDSINFO_QUERY_TID, &buf, sizeof(struct __pthrdsinfo), NULL, &regsiz);
        if (!rc) {
                return buf.__pi_tid;
        }
        return -1;
}

