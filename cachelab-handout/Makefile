# Version number
VERSION = 1

# Where the different the lab should be copied to when handed in.
HANDINDIR = /users/groups/cs224ta/cachelab/

#
# Student makefile for Cache Lab
# Note: requires a 64-bit x86-64 system 
#
CC = gcc
CFLAGS = -g -Wall -Werror -std=c99 -m64

all: test-trans tracegen
	# Generate a handin tar file each time you compile
	-tar -cvf ${USER}-handin-${VERSION}.tar trans.c 

test-trans: test-trans.c trans.o cachelab.c cachelab.h
	$(CC) $(CFLAGS) -o test-trans test-trans.c cachelab.c trans.o 

tracegen: tracegen.c trans.o cachelab.c
	$(CC) $(CFLAGS) -O0 -o tracegen tracegen.c trans.o cachelab.c

trans.o: trans.c
	$(CC) $(CFLAGS) -O0 -c trans.c

handin:
	 install -m660 ${USER}-handin-${VERSION}.tar $(HANDINDIR)/${USER}-handin-${VERSION}.tar 

#
# Clean the src dirctory
#
clean:
	rm -rf *.o
	rm -f *.tar
	rm -f csim
	rm -f test-trans tracegen
	rm -f trace.all trace.f*
	rm -f .csim_results .marker
