CC := gcc
CFLAGS = -std=c99 -O0 -g 
LFLAGS = -lpthread
TARGET = download crawSeq crawThread
LFILES = ../net.c http.c

all: $(TARGET)

download: download.c $(LFILES)
	$(CC) $(CFLAGS) $^ -o $@

crawSeq: crawSeq.c $(LFILES)
	$(CC) $(CFLAGS) $^ -o $@

crawThread: crawThread.c $(LFILES)
	$(CC) $(CFLAGS) $^ $(LFLAGS) -o $@

clean:
	rm -f *.o *.exe $(TARGET)
