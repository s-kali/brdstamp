#include <stdio.h>
#include <stdlib.h>
#include <sys/socker.h>
#include <arpa/inet.h>

throwError(string *errorString){
  perror(errorString);
  exit(1);
}

int main(int argc, char *argv[]){
  int sock;
  struct sockaddr_in broadcastAddr;
  char *broadcastIP;
  int broadcastPermission;
  unsigned int timestampLen;

  if(argc < 3){
    fprintf(stderr, "Usage: %s <IP Address> <Port> \n", argv[0])
    exit(1);
  }

  broadcastIP = argv[1];
  broadcastPort = atoi(argv[2]);

  /* socket(int domain, int type, int protocol);
   * domain -> Communications domain in which a socket is to be created
   * type -> Type of socket DGRAM\ send/recieve point for packet delivery service
   * protocol -> Protocol of socket(TCP, UDP, 0 for default)
  */
  sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)

  if(sock<0)
  throwError("socker() failed!");

  /* setsockopt(int socket, int level, int option_name,
   *    const void *option_value, sockklen_t option_len);
   * level -> SOL_SOCKET\ access at socket level, not protocol level
   * option_name -> socket option SO_BROADCAST\ sending broadcast messages
   */
  if(setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (void *) &broadcastPermission, sizeof(broadcastPermission)) < 0)
  throwError("setsockopt() failed!")

  memset()

}
