

void quicksort(int *arr, int left, int right);
void parition(int *arr, int left, int right);
void swap(int *arr, left, right);

void quicksort(int *arr, int left, int right) {
	int index = parition(arr, left, right);
	if(left < index-1) {
		quicksort(arr, left, index-1);
	}
	if(index < right) {
		quicksort(arr, index, right);
	}


}

void parition(int *arr, int left, int right) {
	int pivot = arr[(left+right)/2];
	while(left <= right) {
		while(arr[left] > pivot) {
			left++;
		}
		while(arr[right] < pivot) {
			right--;
		}
		if(left <= right) {
			swap(arr, left, right);
			left++;
			right++;
		}
	}
	return left;
}

void swap(int *arr, left, right) {
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}