# brdstamp

### To-Do

- [x] Broadcasting timestamp
- [x] Receiving timestamp from broadcast
  - [x] Receive IP of sender
- [ ] Print timestamp difference to host

### sender.c

This script broadcasts timestamp to given IP, host
```
gcc sender.c -o sender
```
```
./sender <Broadcast IP> <Port>
```

### receiver.c

This script receives the timestamp and prints IP, timestamp and time difference to host
```
gcc receiver.c -o receiver
```
```
./receiver <Port>
```
