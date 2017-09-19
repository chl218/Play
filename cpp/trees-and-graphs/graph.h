#ifndef _GRAPH_H_
#define _GRAPH_H_


#include <stdlib.h>
#include <stdio.h>

#define VERTEX_COUNT 10
#define DEBUG 1

typedef struct Vertex {
   unsigned int value;
   bool visited;
   Vertex *neighbor;
   Vertex *next;
} Vertex;


//==============================================================================
// AdjacencyListGraph
//    private:
//       bool aux_findVertices()
//       bool aux_aux_connected()
//    public:
//       bool contains()
//       bool connected()
//       unsigned int getVertexCount()
//       bool addVertex()
//       bool addEdge()
//       bool removeEdge()
//==============================================================================
class AdjacencyListGraph {

   private:
      bool         directed;
      unsigned int vertexCount;
      Vertex       *vertexList;

      //========================================================================
      // aux_findVertices():
      //    help method to find the src and dst vertex (if it exist) for
      //    addEdge() and removeEdge() methods
      //
      //    assumes no vertex duplication
      //========================================================================
      bool aux_findVertices(unsigned int srcVal, unsigned int dstVal 
                           ,Vertex **srcVertex, Vertex **dstVertex) {
         *srcVertex = NULL;
         *dstVertex = NULL;

         // find the src and dst vertex
         Vertex *list = this->vertexList;
         bool srcFound  = false;
         bool dstFound  = false;
         while(list) {
            if(list->value == srcVal) {
               *srcVertex = list;
               srcFound   = true;
            }
            if(list->value == dstVal) {
               *dstVertex = list;
               dstFound   = true;
            }
            if(srcFound && dstFound) {
               return true;
            }
            list = list->next;        
         }

         return false;
      }

      //========================================================================
      // aux_connected():
      //    help method to check if src and dst is connected
      //========================================================================
      bool aux_connected(unsigned int srcVal, unsigned int dstVal
                        ,Vertex **srcVertex, Vertex **dstVertex) {

         *srcVertex = NULL;
         *dstVertex = NULL;

         // check if vertices exists
         if(!aux_findVertices(srcVal, dstVal, srcVertex, dstVertex)) {
            return false;
         }
         
         // check if directed graph's src and dst vertices are connected
         bool connected = false;
         Vertex *vertex = (*srcVertex)->neighbor;
         while(vertex) {
            if(vertex->value == dstVal) {
               connected = true;
               break;
            }
            vertex = vertex->neighbor;
         }

         // check if undirected graph's src and dst vertices are connected
         if(!this->directed) {
            connected = false;
            vertex    = (*dstVertex)->neighbor;
            while(vertex) {
               if(vertex->value == srcVal) {
                  connected = true;
                  break;
               }
               vertex = vertex->neighbor;
            }
         }

         return connected;
      }

   public:

      //========================================================================
      // AdjacencyListGraph():
      //    constructor, initialize graph
      //========================================================================
      AdjacencyListGraph(bool directed) {
         this->directed    = directed;
         this->vertexCount = 0;
         this->vertexList  = NULL;
      }

      //========================================================================
      // ~AdjacencyListGraph():
      //    destructor, frees allocated memory on heap
      //========================================================================
      ~AdjacencyListGraph() {
         Vertex *tmp = NULL; 
         while(vertexList) {
            Vertex *vertex = vertexList->neighbor;
            while(vertex) {
               tmp = vertex;
               vertex = vertex->neighbor;
               free(tmp);
               
            }
            tmp = vertexList;
            vertexList = vertexList->next;
            free(tmp);
            
         }
      }
      
      //========================================================================
      // contains():
      //    search if graph contains vertex v
      //========================================================================
      bool contains(unsigned int value) {
         Vertex *list = vertexList;
         while(list) {
            if(list->value == value) {
               return true;
            }
            list = list->next;
         }
         return false; 
      }

      //========================================================================
      // contains():
      //    search if src and dst is connected
      //========================================================================
      bool connected(unsigned int src, unsigned int dst) {
         Vertex *tmp1, *tmp2;
         return aux_connected(src, dst, &tmp1, &tmp2);
      }

      //========================================================================
      // getVertexCount()
      //    returns the amount of vertices in the graph
      //========================================================================
      unsigned int getVertexCount() {
         return this->vertexCount;
      }

      //========================================================================
      // addVertex():
      //    add a vertex into the graph
      //========================================================================
      bool addVertex(unsigned int value) {
         if(contains(value)) {
            return false;
         }

         Vertex *vertex = (Vertex*)malloc(sizeof(Vertex));
         
         if(!vertex) {
            return false;
         }
         vertex->value    = value;
         vertex->visited  = false;
         vertex->neighbor = NULL;
         vertex->next     = this->vertexList;
         this->vertexList = vertex;
         this->vertexCount++;
         return true;
      }

      //========================================================================
      // addEdge():
      //    add an edge(s) between src and dst, if src or dst does not exist,
      //    returns false, else returns true on successful edge addition
      //========================================================================
      bool addEdge(unsigned int src, unsigned int dst) {
         Vertex *srcVertex = NULL;
         Vertex *dstVertex = NULL;

         // check if already connected
         if(aux_connected(src, dst, &srcVertex, &dstVertex)) {
            return false;
         }

         // not connected, but one of the two vertex does not exist
         if(!srcVertex || !dstVertex) {
            return false;
         }

         // self loop
         if(srcVertex == dstVertex) {
            Vertex *vertex = (Vertex*)malloc(sizeof(Vertex));
            
            if(!vertex) {
               return false;
            }
            vertex->value       = src;
            vertex->neighbor    = srcVertex->neighbor;
            srcVertex->neighbor = vertex;
            return true;
         }

         // malloc vertex for adjacency list
         Vertex *srcToDst = (Vertex*)malloc(sizeof(Vertex));
         
         if(!srcToDst) {
            return false;
         }

         // add edge from src to dst
         srcToDst->value     = dst;
         srcToDst->neighbor  = srcVertex->neighbor;
         srcVertex->neighbor = srcToDst;
         
         // if graph is undirected, add edge from dst to src
         if(!this->directed) {
            Vertex *dstToSrc = (Vertex*)malloc(sizeof(Vertex));
            
            if(!dstToSrc) {
               return false;
            }
            dstToSrc->value     = src;
            dstToSrc->neighbor  = dstVertex->neighbor;
            dstVertex->neighbor = dstToSrc;
         }

         // return true for successful edge addition
         return true;
      }

      //========================================================================
      // removeEdge():
      //    remove the edge(s) between src and dst, if src or dst does not
      //    exist, returns false, else returns true on successful edge deletion
      //========================================================================
      bool removeEdge(unsigned int src, unsigned int dst) {
         Vertex *srcVertex = NULL;
         Vertex *dstVertex = NULL;

         // check if vertices exists and if they are connected
         if(!aux_connected(src, dst, &srcVertex, &dstVertex)) {
            return false;
         }

         // remove edge from src to dst
         Vertex *q = srcVertex;
         Vertex *p = srcVertex->neighbor;
         while(p) {
            if(p->value == dst) {
               q->neighbor = p->neighbor;
               free(p);
               
               break;
            }
            q = p;
            p = p->neighbor;
         }

         // if undirected graph, remove edge from dst to src
         if(!this->directed) {
            q = dstVertex;
            p = dstVertex->neighbor;
            while(p) {
               if(p->value == src) {
                  q->neighbor = p->neighbor;
                  free(p);
                  
                  break;
               }         
               q = p;
               p = p->neighbor;
            }
         }

         return true;
      }

      //========================================================================
      // printGraph():
      //    prints the adjacency list
      //========================================================================
      void print() {
         Vertex *list = vertexList;
         while(list) {
            printf("%u: ", list->value);
            Vertex *vertex = list->neighbor;
            while(vertex) {
               printf("%u ", vertex->value);
               vertex = vertex->neighbor;
            }
            printf("\n");
            list = list->next;
         }
      }
};


class AdjacencyMatrixGraph {

   private:
      bool directed;
      bool graph[VERTEX_COUNT][VERTEX_COUNT];

};







#endif