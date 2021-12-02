# linux_compat

linux_compat is a set of function to make porting of Linux applications to AIX
a little bit easier.

## Installation

You need gcc and gmake to build the library.

```
$ gmake
$ sudo gmake install
```

### Building with IBM Open XL C 17.1

To build the library with IBM Open XL C 17.1 you must change several lines in Makefile.

CC should point to IBM's compiler:

```
CC=/opt/IBM/openxlC/17.1.0/bin/ibm-clang_r
```

IBM Open XL C 17.1 options to specify 32- or 64-bit compilation modes are ```-m32``` and
```-m64``` respectively. GCC options are ```-maix32``` and ```-maix64```. You must change
all occurrencies of ```-maix``` to just ```-m```:

```
recompile32 : CFLAGS=-O -m32
recompile64 : CFLAGS=-O -m64
```

## Functions

### getopt_long

### getprogname

### futimes

### timegm

### vasprintf

### asprintf

### pthread_getthreadid_np
