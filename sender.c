#include <stdio.h>
#include <stdlib.h>
#include <sys/socker.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
  int sock;
  struct sockaddr_in broadcastIP;
  char *broadcastIP;
  int broadcastPermission;
  unsigned int timestampLen;

  if(argc < 3){
    fprintf(stderr, "Usage: %s <IP Address> <Port> \n", argv[0])
    exit(1);
  }

  broadcastIP = argv[1];
  broadcastPort = atoi(argv[2]);

  sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)

  if(sock<0){
    perror("socket() failed");
    exit(1);
  }

 
}
