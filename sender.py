import socket
import time


sock = socket.socket(
	socket.AF_INET,
	socket.SOCK_DGRAM,
	socket.IPPROTO_UDP
	)

sock.setsockopt(
	socket.SOL_SOCKET,
	socket.SO_BROADCAST,
	1
	)


while True:
	timestamp = str(int(time.time())).encode()

	sock.sendto(
		timestamp,
		("255.255.255.255", 5555)
		)

	time.sleep(3)
