#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void throwError(char *errorString){
  perror(errorString);
  exit(1);
}

void print_ip(unsigned int ip)
{
    unsigned char bytes[4];
    bytes[0] = ip & 0xFF;
    bytes[1] = (ip >> 8) & 0xFF;
    bytes[2] = (ip >> 16) & 0xFF;
    bytes[3] = (ip >> 24) & 0xFF;
    printf("%d.%d.%d.%d\n", bytes[3], bytes[2], bytes[1], bytes[0]);
}

int main(int argc, char *argv[]){

  int sock;

  struct sockaddr_in msgSender;
  socklen_t msgLen = sizeof(msgSender);

  struct sockaddr_in broadcastAddr;
  unsigned short broadcastPort;
  char recvString[20];
  int recvStringLen;

  if(argc < 2){
    fprintf(stderr, "Usage: %s <Broadcast Port>\n", argv[0]);
    exit(1);
  }

  broadcastPort = atoi(argv[1]);

  if((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    throwError("socket() failed");

  memset(&broadcastAddr, 0, sizeof(broadcastAddr));
  broadcastAddr.sin_family = AF_INET;
  broadcastAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  broadcastAddr.sin_port = htons(broadcastPort);

  if(bind(sock, (struct sockaddr *)&broadcastAddr,
	 sizeof(broadcastAddr)) < 0)
    throwError("bind() failed");


  for(;;){
  if((recvStringLen = recvfrom(sock, recvString, 20,
	 0, (struct sockaddr*)&msgSender, &msgLen)) < 0)
    throwError("recvfrom() failed");

  recvString[recvStringLen] = '\0';
  printf("Recieved: %s from ", recvString);
  print_ip(ntohl(msgSender.sin_addr.s_addr));
  }

  close(sock);
  exit(0);
}
