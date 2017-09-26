#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <vector>


void generate(std::vector<std::string> &list, char *pattern
             ,int leftRem ,int rightRem ,int index) {

   if(leftRem < 0 || rightRem < leftRem) {
      return;
   }

   if(leftRem == 0 && rightRem == 0) {
      std::string str(pattern);
      list.push_back(str);
   }
   else {
      pattern[index] = '(';
      generate(list, pattern, leftRem-1, rightRem, index+1);

      pattern[index] = ')';
      generate(list, pattern, leftRem, rightRem-1, index+1);
   }
}


std::vector<std::string> generateParens(int count) {
   int length = (sizeof(char) * count * 2) + 1;
   char *pattern = (char*) malloc(length);
   pattern[length-1] = '\0';

   std::vector<std::string> list;
   generate(list, pattern, count, count, 0);
   free(pattern);
   return list;
}


int main(int argc, char *argv[]) {

   if(argc < 2) {
      printf("[ERROR] Usage: ./<program> <n pairs>\n");
      return -1;
   }

   std::vector<std::string> parens = generateParens(atoi(argv[1]));

   std::vector<std::string>::iterator b = parens.begin();
   std::vector<std::string>::iterator e = parens.end();
   
   while(b != e) {
      printf("%s  ", b->c_str());
      b++;
   }
   printf("\n");

   return 0;
}