###############################################################################
# Makefile 
# Jared Spaulding
# COSC 3750, SP 2020
# Homework 7
# Mar. 30, 2020
# 
# Makefile to complile wytalk
###############################################################################

CC=gcc
CFLAGS=-ggdb -Wall
RM=/bin/rm -f

.PHONY: tidy clean

wytalk: wytalkC.c wytalkD.c utilities.c socketfun.c
	$(CC) $(CFLAGS) wytalkC.c utilities.c socketfun.c -o wytalkC -I $(CURDIR)
	$(CC) $(CFLAGS) wytalkD.c utilities.c socketfun.c -o wytalkD -I $(CURDIR)

tidy:
	$(RM) *.o

clean: tidy
	$(RM) wytalkC
	$(RM) wytalkD
	$(RM) core.*