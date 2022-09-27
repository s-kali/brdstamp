# brdstamp

This scripts are used to observe timezones between servers, containers etc.

### How to

#### Sender

You can execute sender script to send timestamp as broadcast message

```
python sender.py
```

#### Receiver

You can execute receiver script to receive timestamp of senders and print time difference as timestamp

```
python receiver.py
```

## Test environment

You can simply use Compose to build 4 Alpine containers that sends broadcast message using sender script

```
docker-compose up -d
```

You can use receiver script by executing interactive shell on a container

```
docker exec -ti <CONTAINER> sh
```

```
python receiver.py
```
<sub>
PS: containers run on same environment so there is no time diff, this test is not really realistic
</sub>
