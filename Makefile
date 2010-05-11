CC=gcc
CFLAGS=-Wall -D NUMBER_OF_MODEMS=1

all: encode

encode:	encode.o pdu.o
	$(CC) $(CFLAGS) encode.o pdu.o -o encode

encode2: encode.o pdu.o charset.o logging.o extras.o stats.o locking.o alarm.o modeminit.o
	$(CC) $(CFLAGS) encode.o pdu.o charset.o logging.o extras.o stats.o locking.o alarm.o modeminit.o -o encode

encode.o: encode.c
	$(CC) $(CFLAGS) -c encode.c

pdu.o:	pdu.c
	$(CC) $(CFLAGS) -c pdu.c

charset.o: charset.c
	$(CC) $(CFLAGS) -c charset.c

logging.o: logging.c
	$(CC) $(CFLAGS) -c logging.c

extras.o: extras.c
	$(CC) $(CFLAGS) -c extras.c

stats.o: stats.c
	$(CC) $(CFLAGS) -c stats.c

locking.o: locking.c
	$(CC) $(CFLAGS) -c locking.c

alarm.o: alarm.c
	$(CC) $(CFLAGS) -c alarm.c

modeminit.o: modeminit.c
	$(CC) $(CFLAGS) -c modeminit.c

clean:
	rm *.o
	rm encode
