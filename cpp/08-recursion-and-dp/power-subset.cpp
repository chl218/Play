#include <stdlib.h>
#include <stdio.h>

#include <vector>


std::vector<std::vector<int> > getSubset(std::vector<int> &set);
std::vector<std::vector<int> > getSubset(std::vector<int> &set, int index);


std::vector<std::vector<int> > getSubset(std::vector<int> &set) {
   return getSubset(set, 0);
}

std::vector<std::vector<int> > getSubset(std::vector<int> &set, int index) {
   std::vector<std::vector<int> > allSubsets;
   if(set.size() == index) {
      std::vector<int> emptySet;
      allSubsets.push_back(emptySet);
   }
   else {

      allSubsets = getSubset(set, index+1);

      int value = set[index];
      // printf("allsubset size: %d index %d value %d\n", allSubsets.size(), index, value);

      std::vector<std::vector<int> > toAppend;

      std::vector<std::vector<int> >::iterator b = allSubsets.begin();
      std::vector<std::vector<int> >::iterator e = allSubsets.end();

      // printf("before:\n");
      // for(std::vector<std::vector<int> >::iterator it = allSubsets.begin(); it != allSubsets.end(); it++) {
      //    printf("{ ");
      //    for(std::vector<int>::iterator itt = (*it).begin(); itt != (*it).end(); itt++) {
      //       printf("%d ", *itt);
      //    }
      //    printf("}\n");
      // }
      // printf("\n");

      while(b != e) {
         // printf("old  subset { ");
         // for(std::vector<int>::iterator it = (*b).begin(); it != (*b).end(); it++) {
         //    printf("%d ", *it);
         // }
         // printf("}\n");

         std::vector<int> newSubset;
         newSubset = (*b);
         // printf("pushing back: %d\n", value);    
         newSubset.push_back(value);

         // printf("new subset: { ");
         // for(std::vector<int>::iterator it = newSubset.begin(); it != newSubset.end(); it++) {
         //    printf("%d ", *it);
         // }
         // printf("}\n\n");

         toAppend.push_back(newSubset);
         b++;
      }

      b = toAppend.begin();
      e = toAppend.end();

      while(b != e) {
         allSubsets.push_back(*b);
         b++;
      }

      // printf("after:\n");
      // for(std::vector<std::vector<int> >::iterator it = allSubsets.begin(); it != allSubsets.end(); it++) {
      //    printf("{ ");
      //    for(std::vector<int>::iterator itt = (*it).begin(); itt != (*it).end(); itt++) {
      //       printf("%d ", *itt);
      //    }
      //    printf("}\n");
      // }
      // printf("\n");
   }

   return allSubsets;


}


int main(int argc, char *argv[]) {

   if(argc < 2) {
      printf("[ERROR] Usage: ./<program> <set size>\n");
      return -1;
   }

   int size = atoi(argv[1]);
   std::vector<int> set;

   printf("Set: { ");
   for(int i = 0; i < size; i++) {
      set.push_back(i);
      printf("%d ", i);
   }
   printf("}\n\n");

   std::vector<std::vector<int> > result = getSubset(set);

   std::vector<std::vector<int> >::iterator b = result.begin();
   std::vector<std::vector<int> >::iterator e = result.end();

   int count = 0;
   printf("Power Set: \n");
   while(b != e) {
      std::vector<int> subset = *b;
      std::vector<int>::iterator bb = subset.begin(); 
      std::vector<int>::iterator ee = subset.end();
      printf("{ ");
      while(bb != ee) {
         printf("%d ", *bb);
         bb++;
      }
      printf("} ");
      b++;

      count++;
      if(count % 5 == 0) {
         printf("\n");
         count = 1;
      }
   }
   printf("\n");

}