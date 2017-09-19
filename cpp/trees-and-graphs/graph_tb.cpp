#include "graph.h"


#define DIRECTED   1
#define UNDIRECTED 0

int main() {

   AdjacencyListGraph graph(DIRECTED);

   printf("Vertex count: %u\n", graph.getVertexCount());
   graph.print();

   for(int j = 0; j < 2; j++) {
      for(int i = 0; i < 10; i++) {
         printf("Adding vertex: [%2d] ", i);
         printf("%s\n", graph.addVertex(i) ? "[SUCCESS]" : "[FAILED]");
      }
      printf("\n");
   }

   printf("Vertex count: %u\n", graph.getVertexCount());
   graph.print();
   
   

   printf("Adding edge (2,6) [%s]\n", graph.addEdge(2, 6) ? "SUCCESS" : "FAILED");
   printf("Adding edge (2,3) [%s]\n", graph.addEdge(2, 3) ? "SUCCESS" : "FAILED");
   printf("Adding edge (2,3) [%s]\n", graph.addEdge(2, 3) ? "SUCCESS" : "FAILED");
   printf("Adding edge (2,2) [%s]\n", graph.addEdge(2, 0) ? "SUCCESS" : "FAILED");
   printf("Adding edge (11,12) [%s]\n", graph.addEdge(11, 12) ? "SUCCESS" : "FAILED");
   graph.print();

   printf("Removing edge (0,0) [%s]\n", graph.removeEdge(0,0) ? "SUCCESS" : "FAILED");
   printf("Removing edge (2,3) [%s]\n", graph.removeEdge(2,3) ? "SUCCESS" : "FAILED");
   printf("Removing edge (2,3) [%s]\n", graph.removeEdge(2,3) ? "SUCCESS" : "FAILED");
   printf("Removing edge (11,12) [%s]\n", graph.removeEdge(11,12) ? "SUCCESS" : "FAILED");
   graph.print();


   printf("Connected (2,0) [%s]\n", graph.connected(2,0) ? "YES" : "NO");
   printf("Connected (2,2) [%s]\n", graph.connected(2,2) ? "YES" : "NO"); 
   printf("Connected (2,6) [%s]\n", graph.connected(2,6) ? "YES" : "NO");
   printf("Connected (11,12) [%s]\n", graph.connected(11,12) ? "YES" : "NO"); 


   printf("Contains 0 [%s]\n", graph.contains(0) ? "YES" : "NO");
   printf("Contains 1 [%s]\n", graph.contains(1) ? "YES" : "NO");
   printf("Contains 2 [%s]\n", graph.contains(2) ? "YES" : "NO");
   printf("Contains 11 [%s]\n", graph.contains(11) ? "YES" : "NO");
   return 0;
}