

#ifndef _ADJMAT_H_
#define _ADJMAT_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <queue>

#define SIZE 16

#define UNDIRECTED 1
#define DIRECTED   0

class AdjacencyMatrix {
      
   public:

      bool matrix[SIZE][SIZE];
      bool visited[SIZE];
      bool undirected;     

      AdjacencyMatrix(bool undirected) {
         srand(time(NULL));

         this->undirected = undirected;
         this->clearMatrix();
         this->clearVisited();
      }

      ~AdjacencyMatrix() { }

      void clearMatrix() {
         for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
               this->matrix[i][j] = false;
            }
         }
      }
      
      void clearVisited() {
         for(int i = 0; i < SIZE; i++) {
               this->visited[i] = false;
         }
      }
      
      bool assertBounds(int i) {
         return (i < 0 || i > SIZE-1) ? false : true;
      }

      bool addEdge(int src, int dst) {
         if(!this->assertBounds(src) || !this->assertBounds(dst)) {
            return false;
         }

         this->matrix[src][dst] = true;
         if(this->undirected) {
            this->matrix[dst][src] = true;
         }
         return true;
      }

      bool removeEdge(int src, int dst) {
         if(!this->assertBounds(src) || !this->assertBounds(dst)) {
            return false;
         }

         this->matrix[src][dst] = false;
         if(this->undirected) {
            this->matrix[dst][src] = false;
         }
      }


      void generate(int numEdge) {
         if(numEdge <= 0) {
            return;
         }

         while(numEdge) {
            unsigned int src = rand() % SIZE;
            unsigned int dst = rand() % SIZE;
            bool result = this->addEdge(src, dst);
            if(result) {
               numEdge--;
            }
         }
      }

      void print() {
         printf("   | ");
         for(int i = 0; i < SIZE; i++) {
            printf("%2d ", i);
         }
         printf("\n---+-");
         for(int i = 0; i < SIZE; i++) {
            printf("---");
         }
         printf("\n");

         for(int i = 0; i < SIZE; i++) {
            printf("%2d | ", i);
            for(int j = 0; j < SIZE; j++) {
               printf("%2d ", matrix[i][j]);
            }
            printf("\n");
         }
         printf("\n");
      }

      bool dfs(unsigned int src, unsigned int dst) {
         if(src == dst) {
            return true;
         }

         this->visited[src] = true;
         bool result = false;
         for(int i = 0; i < SIZE; i++) {
            if(this->matrix[src][i] && !(this->visited[i])) {
               result = dfs(i, dst);
               if(result) {
                  break;
               }
            }
         }
         return result;
      }

      bool bfs(unsigned int src, unsigned int dst) {
         std::queue<unsigned int> q;

         this->visited[src] = true;
         q.push(src);

         while(!q.empty()) {
            unsigned int v = q.front();
            q.pop();
            if(v == dst) {
               return true;
            }
            for(int i = 0; i < SIZE; i++) {
               if(this->matrix[v][i] && !this->visited[i]) {
                  this->visited[i] = true;
                  q.push(i);
               }
            }
         }
         return false;
      }
};











#endif
