CXX=gcc
CFLAGS = -g -Wall -Werror -pedantic-errors \
	-Wshadow -O0 -Wwrite-strings 

all: chinese-remainder-solver find-order

clean:
	@rm -f *.o a.out

chinese-remainder-solver: chinese-remainder-theorem.o
	$(CC) $(CFLAGS) -o chinese-remainder-solver.exe chinese-remainder-theorem.o

chinese-remainder-theorem.o: chinese-remainder-theorem.c
	$(CC) $(CFLAGS) -c chinese-remainder-theorem.c

find-order: find-order.o
	$(CC) $(CFLAGS) -o find-order.exe find-order.o

find-order.o: find-order.c
	$(CC) $(CFLAGS) -c find-order.c

#chinese-remainder-theorem.c
