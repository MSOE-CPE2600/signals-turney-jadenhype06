CFLAGS=-c -g -Wall -Werror
CC=gcc

all: recv_signal send_signal signal_handler signal_segfault signal_alarm signal_sigaction

recv_signal: recv_signal.o
	$(CC) -o recv recv_signal.o

send_signal: send_signal.o
	$(CC) -o send send_signal.o

signal_handler: signal_handler.o
	$(CC) -o handler signal_handler.o

signal_segfault: signal_segfault.o
	$(CC) -o segfault signal_segfault.o

signal_alarm: signal_alarm.o
	$(CC) -o alarm signal_alarm.o

signal_sigaction: signal_sigaction.o
	$(CC) -o sigaction signal_sigaction.o

clean:
	rm -f *.o info pinfo finfo pmod

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<
