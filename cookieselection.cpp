#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <list>

#define MAX 600000

// int a[MAX];
list<int> a;
int len = 0;

int merge(int*, int, int, int);
int mergeSort(int*, int, int);
int swap(int*, int, int);
int arrive(int d);
int send(void);

int main(void){
	char buff[100];
	gets(buff);
	while (strlen(buff)){
		if (strcmp(buff, "#") == 0){
			// puts("#");
			send();
		}
		else{
			// printf(":%d\n", atoi(buff));
			arrive(atoi(buff));
		}
		buff[0] = 0;
		gets(buff);
	}
	return 0;
}

int arrive(int d){
	if (!len){
		// a[len++] = d;
		a.push_back(d)
		return 0;
	}
	list<int>::iterator it = a.begin()
	while ((*it < d) && (it != a.end())){
		it++;
	}
	a.insert(it, d);
	// int left = 0;
	// while ((a[left] < d) && (left < len)){
	// 	left++;
	// }
	// for(int i = len; i > left; i--){
	// 	a[i] = a[i - 1];
	// }
	// a[left] = d;
	
	// len++;
}

int send(){
	// mergeSort(a, 0, len - 1);
	int index = 0;
	int len = a.size();
	if (len % 2 == 1){
		index = (len - 1) / 2;
	}
	else{
		index = len / 2;
	}
	list<int>::iterator it = a.begin();
	for(int i = 0; i < index; i++){
		it++;
	}
	printf("%d\n", *it);
	// for (int i = index; i < len; ++i){
	// 	a[index] = a[index + 1];
	// }
	// len--;
}

int mergeSort(int *a, int left, int right){
	if (left < right){
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
	return 0;
}

int merge(int *a, int left, int mid, int right){
	int count = right - left + 1;
	int *tmp = (int*) calloc(count, sizeof(int));
	int i = left;
	int j = mid + 1;
	int k;

	for(k = 0; k < count; k++){
		if (i > mid){
			tmp[k] = a[j];
			j++;
		}
		else if (j > right){
			tmp[k] = a[i];
			i++;
		}
		else if (a[i] < a[j]){
			tmp[k] = a[i];
			i++;
		}
		else{
			tmp[k] = a[j];
			j++;
		}
	}
	for(k = 0; k < count; k++)
		a[left + k] = tmp[k];
	free(tmp);
}

int swap(int *a, int i, int j){
	int tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
	return 0;
}