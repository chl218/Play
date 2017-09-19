#include <stdio.h>
#include <stdlib.h>

#include "adjmat.h"

int main() {
   AdjacencyMatrix graph(UNDIRECTED);

   graph.addEdge(1,2);
   graph.addEdge(2,3);
   graph.addEdge(2,5);
   graph.addEdge(5,7);
   graph.addEdge(7,1);
   graph.generate(16);
   graph.print();


   unsigned int src;
   unsigned int dst;

   //===========================================================================
   src = 1; dst = 7;
   printf("dfs: src=%2d, dst=%2d, path=%s\n"
         ,src, dst, graph.dfs(src, dst) ? "Yes" : "No");
   graph.clearVisited();

   src = 7; dst = 1;
   printf("dfs: src=%2d, dst=%2d, path=%s\n"
         ,src, dst, graph.dfs(src, dst) ? "Yes" : "No");
   graph.clearVisited();

   src = 0; dst = 15;
   printf("dfs: src=%2d, dst=%2d, path=%s\n"
         ,src, dst, graph.dfs(src, dst) ? "Yes" : "No");
   graph.clearVisited();

   //===========================================================================
   src = 1; dst = 7;
   printf("bfs: src=%2d, dst=%2d, path=%s\n"
          ,src, dst, graph.bfs(src, dst) ? "Yes" : "No");
   graph.clearVisited();

   src = 7; dst = 1;
   printf("bfs: src=%2d, dst=%2d, path=%s\n"
          ,src, dst, graph.bfs(src, dst) ? "Yes" : "No");
   graph.clearVisited();

   src = 0; dst = 15;
   printf("bfs: src=%2d, dst=%2d, path=%s\n"
          ,src, dst, graph.bfs(src, dst) ? "Yes" : "No");
   graph.clearVisited();

   return 0;
}