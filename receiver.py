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

sock.bind(("", 5555))

while True:
	data, addr = sock.recvfrom(1024)
	print("Timestamp on", addr[0], "is", data.decode(), "time diff =", int(time.time())-int(data.decode()))
