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

      std::vector<std::vector<int> > toAppend;
      std::vector<std::vector<int> >::iterator b = allSubsets.begin();
      std::vector<std::vector<int> >::iterator e = allSubsets.end();

      while(b != e) {
         std::vector<int> newSubset;
         newSubset = (*b);
         newSubset.push_back(value);
         toAppend.push_back(newSubset);
         b++;
      }

      b = toAppend.begin();
      e = toAppend.end();
      while(b != e) {
         allSubsets.push_back(*b);
         b++;
      }
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