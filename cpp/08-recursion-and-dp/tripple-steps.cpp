
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int countWays(int n);

int countWaysDP(int n);
int countWaysDP(int n, int *memo);

int main(int argc, char *argv[]) {

   if(argc < 2) {
      printf("[ERROR] Usage: <program name> <number of steps>\n");
      return -1;
   }

   int steps = atoi(argv[1]);

   clock_t begin = clock();

   printf("Recursion:\nSteps = %d\nPossible Ways = %d\n",
          steps, countWays(steps));   
   
   clock_t end = clock();
   
   printf("Execution Time = %f secs\n\n",
         (double)(end-begin) / CLOCKS_PER_SEC);


   begin = clock();
 
   printf("Dynamic Programming:\nSteps = %d\nPossible Ways = %d\n",
          steps, countWaysDP(steps));         
   
   end = clock();
   
   printf("Execution Time = %f secs\n\n",
         (double)(end-begin) / CLOCKS_PER_SEC);


   return 0;
}


int countWays(int n) {
   if(n < 0) {
      return 0;
   }
   else if(n == 0) {
      return 1;
   }
   else {
      return countWays(n-1) + countWays(n-2) + countWays(n-3);
   }
}

int countWaysDP(int n) {
	int *memo = (int *)malloc(sizeof(int) * (n + 1));
	memset(memo, -1, sizeof(int)*(n+1));
   int res = countWaysDP(n, memo);
   free(memo);
	return res;
} 

int countWaysDP(int n, int *memo) {
	if(n < 0) {
		return 0;
	}
	else if(n == 0) {
		return 1;
	}
	else if(memo[n] > -1) {
		return memo[n];
	}
	else {
		memo[n] = countWaysDP(n-1, memo) + countWaysDP(n-2, memo) + countWaysDP(n-3, memo);
		return memo[n];
	}
}