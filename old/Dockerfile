# syntax=docker/dockerfile:1
FROM frolvlad/alpine-gcc

COPY sender.c sender.c
COPY receiver.c receiver.c

CMD [ "gcc", "-o", "sender", "sender.c" ]
