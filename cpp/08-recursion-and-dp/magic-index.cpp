#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int magicSlow(int *arr, int length);

int magicFastUnique(int *arr, int length);
int magicFastUnique(int *arr, int start, int end);

int magicFastNondistinct(int *arr, int length);
int magicFastNondistinct(int *arr, int start, int end);

int magicSlow(int *arr, int length) {
   for(int i = 0; i < length; i++) {
      if(arr[i] == i) {
         return i;
      }
   }
   return -1;
}


int magicFastUnique(int *arr, int length) {
   return magicFastUnique(arr, 0, length-1);
}

int magicFastUnique(int *arr, int start, int end) {
   if(end < start) {
      return -1;
   }

   int mid = (start + end) / 2;
   if(arr[mid] == mid) {
      return mid;
   }
   else if(arr[mid] > mid) {
      return magicFastUnique(arr, start, mid-1);
   }
   else {
      return magicFastUnique(arr, mid+1, end);
   }
}

int min(int a, int b) {
   return a < b ? a : b;
}

int max(int a, int b) {
   return a > b ? a : b;
}

int magicFastNondistinct(int *arr, int length) {
   return magicFastNondistinct(arr, 0, length-1);
}

int magicFastNondistinct(int *arr, int start, int end) {
   if(end < start) {
      return -1;
   }

   int mid = (start+end) / 2;
   if(arr[mid] == mid) {
      return mid;
   }

   int leftEnd = min(arr[mid], mid-1);
   int leftMagic = magicFastNondistinct(arr, start, leftEnd);
   if(leftMagic > -1) {
      return leftMagic;
   }

   int rightStart = max(arr[mid], mid+1);
   int rightMagic = magicFastNondistinct(arr, rightStart, end);
   return rightMagic;
}

int main() {

   int arr[11] = {-8,-2,-1,1,2,3,5,7,9,12,13};

   printf("Unique:\narr1:  ");
   for(int i = 0; i < 11; i++) {
      printf("%2d ", arr[i]);
   }
   printf("\nindex: ");
   for(int i = 0; i < 11; i++) {
      printf("%2d ", i);
   }
   printf("\n\nmagicSlow()          : %d\n", magicSlow(arr, 11));
   printf("magicFastUnique      : %d\n", magicFastUnique(arr, 11));
   printf("magicFastNondistinct : %d\n\n", magicFastNondistinct(arr, 11));
   
   int arr2[11] = {-8,-2,2,2,2,3,5,8,9,12,13};


   printf("Non-distinct:\narr2:  ");
   for(int i = 0; i < 11; i++) {
      printf("%2d ", arr2[i]);
   }
   printf("\nindex: ");
   for(int i = 0; i < 11; i++) {
      printf("%2d ", i);
   }
   printf("\n\nmagicSlow()          : %d\n", magicSlow(arr2, 11));
   printf("magicFastUnique      : %d\n", magicFastUnique(arr2, 11));
   printf("magicFastNondistinct : %d\n\n", magicFastNondistinct(arr2, 11));
   

  return  0;
}
