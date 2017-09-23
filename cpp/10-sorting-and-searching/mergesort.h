#include <stdlib.h>
#include <stdio.h>

void mergesort(int *arr, int length);
void mergesort(int *arr, int *aux, int low, int high);
void merge(int *arr, int *aux, int low, int mid, int high);


void mergesort(int *arr, int length) {
    int *aux = (int*)malloc(sizeof(int)*length);
    mergesort(arr, aux, 0, length-1);
    free(aux);
}

void mergesort(int *arr, int *aux, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, aux, low, mid);
        mergesort(arr, aux, mid+1, high);
        merge(arr, aux, low, mid, high);
    }
}

void merge(int *arr, int *aux, int low, int mid, int high) {
    for(int i = low; i <= high; i++) {
        aux[i] = arr[i];
    }

    int left  = low;
    int right = mid+1;
    int curr  = low;

    while(left <= mid && right <= high) {
        if(aux[left] <= aux[right]) {
            
            arr[curr] = aux[left];
            left++;
        }
        else {
            
            arr[curr] = aux[right];
            right++;
        }
        curr++;
    }

    int remaining = mid - left;
    for(int i = 0; i <= remaining; i++) {
        arr[curr + i] = aux[left + i];
    }
}
