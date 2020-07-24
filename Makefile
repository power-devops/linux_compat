recompile32 : CFLAGS=-O -maix32
recompile64 : CFLAGS=-O -maix64

CC=gcc

OBJS=src/err.o src/futimes.o src/getopt_long.o src/getprogname.o src/timegm.o src/vasprintf.o src/asprintf.o
OBJS32=lib32/err.o lib32/futimes.o lib32/getopt_long.o lib32/getprogname.o lib32/timegm.o lib32/vasprintf.o lib32/asprintf.o
OBJS64=lib64/err.o lib64/futimes.o lib64/getopt_long.o lib64/getprogname.o lib64/timegm.o lib64/vasprintf.o lib64/asprintf.o

all: liblinux_compat.a

install:
	cp liblinux_compat.a $(DESTDIR)/usr/lib/
	cp src/getopt.h $(DESTDIR)/usr/include/
	cp src/linux_compat.h $(DESTDIR)/usr/include/

clean: cleanobj
	rm -f liblinux_compat.a
	rm -f liblinux_compat*.so.1
	rm -rf lib32
	rm -rf lib64

cleanobj:
	rm -f $(OBJS)

mkdirs:
	mkdir -p lib32
	mkdir -p lib64

recompile32: cleanobj $(OBJS)

liblinux_compat32.so.1: cleanobj $(OBJS)
	$(MAKE) recompile32
	mv src/*.o lib32/

recompile64: cleanobj $(OBJS)

liblinux_compat64.so.1: cleanobj $(OBJS)
	$(MAKE) recompile64
	mv src/*.o lib64/

liblinux_compat.a: mkdirs liblinux_compat32.so.1 liblinux_compat64.so.1
	$(CC) -shared -o liblinux_compat.so.1 $(OBJS32) -lc
	ar qv liblinux_compat.a liblinux_compat.so.1
	rm -f liblinux_compat.so.1
	$(CC) -maix64 -shared -o liblinux_compat.so.1 -lc $(OBJS64)
	ar -X64 qv liblinux_compat.a liblinux_compat.so.1

.c.o:
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

.PHONY: clean cleanobj
