import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

sock.bind(("", 5555))

while True:
	data, addr = sock.recvfrom(1024)
	print("received ", data.decode(), " from ", addr[0])
