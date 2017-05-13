CXX=gcc
CFLAGS = -g -Wall -Werror -pedantic-errors \
	-Wshadow -O0 -Wwrite-strings 

all: chinese-remainder-solver find-order factorial-composites
	@rm -f *.o a.out
#
#clean:
#	@rm -f *.o a.out

chinese-remainder-solver: chinese-remainder-theorem.o
	$(CC) $(CFLAGS) -o chinese-remainder-solver.exe chinese-remainder-theorem.o

chinese-remainder-theorem.o: chinese-remainder-theorem.c
	$(CC) $(CFLAGS) -c chinese-remainder-theorem.c

find-order: find-order.o
	$(CC) $(CFLAGS) -o find-order.exe find-order.o

find-order.o: find-order.c
	$(CC) $(CFLAGS) -c find-order.c

#chinese-remainder-theorem.c
factorial-composites:
	$(CC) -o factorial-composites.exe -lm $(CFLAGS) factorial-composites.c

factorial-composies.o:
	$(CC) -c -lm $(CFLAGS) factorial-composites.c


