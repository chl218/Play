#include <set>

#include <stdio.h>
#include <stdlib.h>



typedef struct Point {
   int x;
   int y;


   bool operator<(const Point &other) const {
      //printf("lhs (%d, %d)  ", this->x, this->y);
      //printf("rhs (%d, %d)\n", other.x, other.y);
      //printf("res %d\n", this->x < other.x);
      
      if(this->x < other.x) return true;
      if(this->x > other.x) return false;

      return this->y < other.y;

   }

} Point;



int main() {

   std::set<Point> set;

   Point p1;
   p1.x = 1;
   p1.y = 2;

   Point p2;
   p2.x = 1;
   p2.y = 0;

   set.insert(p1);

   std::set<Point>::iterator it = set.find(p1);
   if(it != set.end()) {
      printf("found (%d, %d)\n", it->x, it->y);
   }
   else {
      printf("nope\n");
   }

   it = set.find(p2);
   if(it != set.end()) {
      printf("(%d, %d)\n", it->x, it->y);
   }
   else {
      printf("nope\n");
   }

   set.insert(p2);

   it = set.find(p2);
   if(it != set.end()) {
      printf("found (%d, %d)\n", it->x, it->y);
   }
   else {
      printf("nope\n");
   }


   return 0;
}
