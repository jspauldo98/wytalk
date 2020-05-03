/*
 * wytalkC.c
 * Author: Jared Spaulding
 * Date: Mar 30, 2020
 *
 * COSC 3750, Homework 7
 *
 * Client version for wytalk
 *
 */

#include <socketfun.h>
#include <utilities.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  // Must have one argument of hostname
  if (argc < 2) {
    printf("%s\n", "wytalk: must include hostname");
    exit(1);
  } else {
    // Connect to server
    int sockfd = request_connection(argv[1], 51100);
    checkSocket(sockfd);

    while (!feof(stdin)){
      // Send line of user input
      writeInput(sockfd);
  
      // Recieve input
      char *input = recieveInput(sockfd);
      writeToScreen(input);

    }
    close(sockfd);
  }

  return 0;
}