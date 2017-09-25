#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include <vector>
#include <set>


#define ROW 36
#define COL 36

typedef struct Point {
   int x;
   int y;

   bool operator<(const Point &other) const {
      if(this->x < other.x) return true;
      if(this->x > other.x) return false;

      return this->y < other.y;
   }

} Point;


std::vector<Point> getPath(int maze[ROW][COL]);
bool getPath(int maze[ROW][COL], int r, int c, std::vector<Point> &path);

std::vector<Point> getPathDP(int maze[ROW][COL]);
bool getPathDP(int maze[ROW][COL]
              ,int row
              ,int col
              ,std::vector<Point> &path
              ,std::set<Point> &failedPoints);


int main() {

   srand(time(NULL));

   int maze[ROW][COL];
   for(int r = 0; r < ROW; r++) {
      for(int c = 0; c < COL; c++) {
         maze[r][c] = (rand() % 10) > 6 ? 0 : 1;   // biased rng 5:4
      }
   }
   maze[0][0] = maze[0][1] = maze[1][0] = maze[1][1] = 1;
   maze[ROW-1][COL-1] = maze[ROW-2][COL-2] = 1;
   maze[ROW-2][COL-1] = maze[ROW-1][COL-2] = 1;

   printf("%dx%d Maze:\n", ROW, COL);
   for(int i = 0; i < ROW; i++) {
      for(int j = 0; j < COL; j++) {
         printf("%2d ", maze[i][j]);
      }
      printf("\n");
   }
   clock_t begin = clock();
   std::vector<Point> path = getPath(maze);
   clock_t end = clock();

   std::vector<Point>::iterator b = path.begin();
   std::vector<Point>::iterator e = path.end();
   
   if(b == e) {
      printf("\nNo Solution\n");
   }
   else {
      int count = 1;
      printf("Path:\n");
      while(b != e) {
         printf("(%2d, %2d) ", (*b).x, (*b).y);
         if(count++ % 9 == 0) {
            printf("\n");
         }
         b++;
      }
   }

   printf("\nRecursive Execution Time: %f secs\n\n"
         ,(double)(end-begin) / CLOCKS_PER_SEC);
   

   begin = clock();
   path  = getPathDP(maze);
   end   = clock();
   
   b = path.begin();
   e = path.end();
   if(b == e) {
      printf("\nNo Solution\n");
   }
   else {
      int count = 1;
      printf("Path:\n");
      while(b != e) {
         printf("(%2d, %2d) ", (*b).x, (*b).y);
         if(count++ % 9 == 0) {
            printf("\n");
         }
         b++;
      }
   }

   printf("\nDynamic Programming Execution Time: %f secs\n"
         ,(double)(end-begin) / CLOCKS_PER_SEC);

   return 0;
}



//==============================================================================
//
//==============================================================================
std::vector<Point> getPath(int maze[ROW][COL]) {
   std::vector<Point> path;
   if(getPath(maze, ROW-1, COL-1, path)) {
      return path;
   }
   path.clear();
   return path;
}

bool getPath(int maze[ROW][COL], int r, int c, std::vector<Point> &path) {
   if(r < 0 || c < 0 || !maze[r][c]) {
      return false;
   }

   bool atOrigin = (r == 0) && (c == 0);

   if(atOrigin || getPath(maze, r-1, c, path) || getPath(maze, r, c-1, path)) {
      Point point;
      point.x = r;
      point.y = c;
      path.push_back(point);
      return true;
   }

   return false;
}

//==============================================================================
//
//==============================================================================
std::vector<Point> getPathDP(int maze[ROW][COL]) {
   std::set<Point> failedPoints;
   std::vector<Point> path;

   if(getPathDP(maze, ROW-1, COL-1, path, failedPoints)) {
      return path;
   }

   //path.clear();
   return path;
}



bool getPathDP(int maze[ROW][COL]
              ,int row
              ,int col
              ,std::vector<Point> &path
              ,std::set<Point> &failedPoints) {


   if(row < 0 || col < 0 || !maze[row][col]) {
      return false;
   }

   Point point;
   point.x = row;
   point.y = col;
   std::set<Point>::iterator it = failedPoints.find(point);
   if(failedPoints.find(point) != failedPoints.end()) {
      return false;
   }


   int atOrigin = (row == 0) && (col == 0);
   if(atOrigin || getPathDP(maze, row-1, col, path, failedPoints) ||    
                  getPathDP(maze, row, col-1, path, failedPoints)) {
      path.push_back(point);
      return true;
   }

   failedPoints.insert(point);
   return false;
}
