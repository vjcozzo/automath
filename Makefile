CXX=gcc
CFLAGS = -g -Wall -Werror -pedantic-errors \
	-Wshadow -O0 -Wwrite-strings 

all: chinese-remainder-solver.exe

clean:
	@rm -f *.o a.out

chinese-remainder-solver.exe: chinese-remainder-theorem.o
	$(CC) $(CFLAGS) -o chinese-remainder-solver.exe chinese-remainder-theorem.o

chinese-remainder-theorem.o: chinese-remainder-theorem.c
	$(CC) $(CFLAGS) -c chinese-remainder-theorem.c


#chinese-remainder-theorem.c
