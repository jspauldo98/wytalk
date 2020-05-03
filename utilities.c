/*
 * utilities.c
 * Author: Jared Spaulding
 * Date: Mar 31, 2020
 *
 * COSC 3750, Homework 7
 *
 * Contains all the utility functions for wytalk
 *
 */

#include "utilities.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX 512

void checkHostName(int hostname) 
{ 
  if (hostname == -1) { 
    perror("wytalk: gethostname"); 
    exit(1); 
  } 
}

void checkAccept(int sockfd) {
  if (sockfd == -1) 
    exit(1);
}

void checkSocket(int sockfd) {
  if (sockfd == -1 || sockfd == 1) 
    exit(1);
}

void checkReadWrite(ssize_t out, int sockfd) {
  if (out == -1 || out == 0){
    printf("%s\n", "wytalk: socket closed");
    close(sockfd);
    exit(1);
  }
}

void writeInput(int sockfd) {
  char *buffer = (char*)malloc(MAX*sizeof(char));
  char *out = fgets(buffer, MAX, stdin);
  if (out != NULL){
    ssize_t w = write(sockfd, buffer, strlen(buffer));
    checkReadWrite(w, sockfd);
  } 
}

char *recieveInput(int sockfd) {
  char *buffer = (char*)malloc(MAX*sizeof(char));
  ssize_t r = read(sockfd, buffer, MAX-1);
  checkReadWrite(r, sockfd);
  return buffer;
}

void writeToScreen(char *text) {
  strcat(text, "\n");
  size_t out = fwrite(text, strlen(text), 1, stdout);
  if (out == 0) {
    printf("%s\n", "A write error occured");
  }
}