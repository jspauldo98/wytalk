/*
 * utilities.h
 * Author: Jared Spaulding
 * Date: Mar 31, 2020
 *
 * COSC 3750, Homework 9
 *
 * Header for utilities.c
 * Contains all the utility functions needed
 *
 */

#ifndef _UTILITIES_H
#define _UTILITIES_H

#include <sys/types.h>

extern void checkHostName(int hostname);
/*
 * Given a hostname check for errors.
 */

extern void checkAccept(int sockfd);
/*
 * Given a sockfd check for accept errors 
 */

extern void checkSocket(int sockfd);
/*
 * Given a sockfd check for socket errors.
 */

extern void checkReadWrite(ssize_t out, int sockfd);
/*
 * Given read/write return value, and sockfd check for errors.
 */

extern void writeInput(int sockfd);
/*
 * Given a sockfd write input to socket.
 */

extern char *recieveInput(int sockfd);
/*
 * Return input given a sockfd.
 */

extern void writeToScreen(char* text);
/*
 * Write text to screen and error check.
 */

#endif
