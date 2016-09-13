#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int testCases = 0;
int n = 0;

typedef unsigned long long int mytype;

mytype mergeSort(int *a, int left, int right);
mytype merge(int *a, int left, int mid, int right);

int main(int argc, char const *argv[]){
	scanf("%d", &testCases);
	for(int i = 0; i < testCases; i++){
		scanf("%d", &n);
		// printf("n = \n", n);
		int *a = (int*) malloc(n * sizeof(int));
		for(int j = 0; j < n; j++){
			scanf("%d", a + j);
		}
		int count = 0;
		printf("%llu\n", mergeSort(a, 0, n - 1));
	}
	return 0;
}

mytype mergeSort(int *a, int left, int right){
	// printf("merge sort left %d right %d\n", left, right);
	if (left < right){
		int mid = (left + right) / 2;
		return mergeSort(a, left, mid) + mergeSort(a, mid + 1, right) + merge(a, left, mid, right);
	}
	return 0;
}

mytype merge(int *a, int left, int mid, int right){
	int count = right - left + 1;
	int *tmp = (int*) malloc(count * sizeof(int));
	int i = left;
	int j = mid + 1;
	mytype result = 0;
	for (int k = 0; k < count; k++){
		if (i > mid){
			tmp[k] = a[j];
			j = j + 1;
		}
		else if (j > right){
			tmp[k] = a[i];
			i = i + 1;
		}
		else if (a[i] < a[j]){
			tmp[k] = a[i];
			i = i + 1;
		}
		else{
			tmp[k] = a[j];
			result = result + (mytype) (mid - i + 1);
			// printf("i %d j %d a[i] %ld a[j] %ld Mid %d i %d inc %d\n", i, j, a[i], a[j], mid, i, mid - i + 1);
			j = j + 1;
		}
	}
	for (int k = 0; k < count; k++){
		a[k + left] = tmp[k];
	}
	// free(tmp);
	return result;
}
