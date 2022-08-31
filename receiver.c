#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uinstd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void throwError(char *errorString){
  perror(errorString);
  exit(1);
}

int main(int argc, char *argv[]){

  int sock;
  struct sockaddr_in broadcastAddr;
  unsigned short broadcastPort;
  char recvString[20];
  int recvStringLen;

  if(argc < 2){
    fprintf(stderr, "Usage: %s <Broadcast Port>\n", argv[0]);
    exit(1);
  }

  broadcastPort = atoi(argv[1]);

}
