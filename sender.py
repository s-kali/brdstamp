import socket
import time

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

msg = b"first message"

while True:
	sock.sendto(msg, ("localhost", 5555))
	time.sleep(3)
