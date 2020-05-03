/*
 * wytalkD.c
 * Author: Jared Spaulding
 * Date: Mar 30, 2020
 *
 * COSC 3750, Homework 7
 *
 * Acts as the "server" process for wytalk
 *
 */

#include <socketfun.h>
#include <utilities.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  char hostbuffer[256];

  // Get local hostname
  int hostname = gethostname(hostbuffer, sizeof(hostbuffer)); 
  checkHostName(hostname);

  // Open port for client to listen to
  int sockfd = serve_socket(hostbuffer, 51100);
  checkSocket(sockfd);
  int newSocket = accept_connection(sockfd);
  checkAccept(newSocket);

  while (!feof(stdin)){
    // Recieve input
    char *input = recieveInput(newSocket);
    writeToScreen(input);
  
    // Send input
    writeInput(newSocket);
  }

  close(newSocket);
  close(sockfd);
  return 0;
}