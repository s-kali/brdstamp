# syntax=docker/dockerfile:1
FROM python:3.10.5-alpine

WORKDIR /app

COPY . .

CMD [ "python", "sender.py" ]
