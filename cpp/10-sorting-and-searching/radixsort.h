

void radixsort(int *arr, int length);
void radixsort(int *arr, int length, int exp);


int maxDigit(int *arr, int length) {
   int max = arr[0];
   for(int i = 1; i < length; i++) {
      if(arr[i] > max) {
         max = arr[i];
      }
   }
   return max;
}

void radixsort(int *arr, int length) {
   int m = maxDigit(arr, length);
   // for each decimal position
   for(int exp = 1; m/exp > 0; exp *= 10) {
      radixsort(arr, length, exp);
   }
}

void radixsort(int *arr, int length, int exp) {
   int *output = (int *)malloc(sizeof(int) * length);
   int count[10] = {0};

   // Count frequencies
   for(int i = 0; i < length; i++) {
      count[(arr[i]/exp) % 10]++;
   }

   // Compute cumulates
   for(int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
   }

   // Move records
   for(int i = 0; i < length; i++) {
      int index = --count[(arr[i]/exp) % 10];
      output[index] = arr[i];
   }

   // copy back
   for(int i = 0; i < length; i++) {
      arr[i] = output[i];
   }
}