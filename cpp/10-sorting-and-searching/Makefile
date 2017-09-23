CC=g++
CFLAGS=-Wall -g

HEADERS=mergesort.h

ALL=tb_sort

all: $(ALL)

tb_sort: tb_sort.o
	$(CC) $(CFLAGS) tb_sort.o -o tb_sort

tb_sort.o: sort_tb.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c sort_tb.cpp -o tb_sort.o

clean:
	rm -rf a.out $(ALL) *.o 2>/dev/null


