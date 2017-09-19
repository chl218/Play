CC=g++
CFLAGS=-Wall -g

HEADERS=graph.h adjmat.h

ALL=tb_adjlst tb_adjmat tb_search

all: $(ALL)

tb_adjlst: tb_adjlst.o
	$(CC) $(CFLAGS) tb_adjlst.o -o tb_adjlst

tb_adjlst.o: graph_tb.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c graph_tb.cpp -o tb_adjlst.o

tb_adjmat: tb_adjmat.o
	$(CC) $(CFLAGS) tb_adjmat.o -o tb_adjmat

tb_adjmat.o: adjmat_tb.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c adjmat_tb.cpp -o tb_adjmat.o

tb_search: tb_search.o
	$(CC) $(CFLAGS) tb_search.o -o tb_search

tb_search.o: search_tb.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c search_tb.cpp -o tb_search.o

clean:
	rm -rf a.out $(ALL) *.o 2>/dev/null


