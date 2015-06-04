CC = g++
CPPFLAGS = -Wall -m64 -g -std=c++11
LDFLAGS = -m64

lab07:			lab07.o clist.o supplied.o

lab07.o:		clist.h

clist.cpp:		clist.h

.PHONY:	x
x:				# clean the directory
				$(info -- cleaning the directory --)
				rm -f clist.o  lab07.o lab07
