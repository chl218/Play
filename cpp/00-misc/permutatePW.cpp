/*
 * Password Munged  - 
 *    Because I keep on forgetting my KeePass password! >:[
 *
 *    Given an all alphebetical password phrase, mangle it with replacements
 *    from replacement key-value pair input file.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <string>
#include <map>

typedef std::vector<std::string> VecStr;
typedef std::map<char, std::string> MapCharStr;

void permutate(MapCharStr &map, VecStr &list, std::string str, int start) {
   // for each index, generate a permutation of the text
   for(int i = start; i < str.length(); i++) {
      // if current character have a potential replacement
      if(map.find(str[i]) != map.end()) {
         // get the list of replacements
         std::string replacements = map[str[i]];
         // replace the character with the replacement, recurse the next index
         for(int j = 0; j < replacements.length(); j++) {
            std::string newStr = str;
            newStr[i] = replacements[j];
            list.push_back(newStr);
            permutate(map, list, newStr, i+1);
         }
      }
   }
}

VecStr permutatePW(char *s, FILE *fp) {
   char key;
   char value[256];
   MapCharStr map;
   printf("Replacement Map:\n");

   // read the replacement map from file
   while(fscanf(fp, "%c %s\n", &key, value) == 2) {
      std::string val(value);
      map[key] = val;
      printf("%c -> ", key);
      for(int i = 0; i < val.length(); i++) {
         printf("%c ", val[i]);
      }
      printf("\n");
   }
   printf("\n");

   std::string str(s);
   VecStr list;

   list.push_back(str);
   permutate(map, list, str, 0);

   return list;
}


int main(int argc, char *argv[]) {

   if(argc < 3) {
      printf("[ERROR] Usage: ./<program> <password guess> <replacement map>\n");
      return -1;
   }

   FILE *fp = fopen(argv[2], "r");
   if(!fp) {
      printf("[ERROR] Unable to read file\n");
      return -2;
   }

   VecStr permutations = permutatePW(argv[1],  fp);

   VecStr::iterator b = permutations.begin();
   VecStr::iterator e = permutations.end();

   int count = 0;
  
   printf("Permutations:\n");
   while(b != e) {
      printf("%s   ", b->c_str());
      b++;
      count++;
      if(count % 6 == 0) {
         count = 0;
         printf("\n");
      }
   }
   printf("\n%d permutations to: %s\n", (int)permutations.size()-1, argv[1]);

   return 0;
}
