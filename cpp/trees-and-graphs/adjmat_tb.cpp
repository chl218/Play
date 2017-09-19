#include "adjmat.h"

#define EDGE_AMT 50

int main() {
	AdjacencyMatrix graph(UNDIRECTED);

	graph.generate(EDGE_AMT);
	graph.print();

	return 0;

}
