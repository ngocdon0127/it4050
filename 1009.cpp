/**
 * Đệ quy quay lui, liệt kê tất cả các hoán vị độ dài n
 * Đếm và đưa ra hoán vị thứ k
 *
 * Độ phức tạp O(n * n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

int n = 0;
int k = 0;
int *a = NULL;
int *mark = NULL;
int stt = 0;

int Try(int index);
int in(void);

int main(int argc, char const *argv[]){
	scanf("%d%d", &n, &k);
	mark = (int*) calloc(n + 1, sizeof(int));
	if (!mark){
		return 0;
	}
	a = (int*) calloc(n, sizeof(int));
	if (!a){
		return 0;
	}
	Try(0);
	printf("-1");
	return 0;
}

int Try(int index){
	if (index >= n){
		in();
	}
	else {
		for(int i = 1; i <= n; i++){
			if (!mark[i]){
				a[index] = i;
				mark[i] = 1;
				Try(index + 1);
				mark[i] = 0;
			}
		}
	}
}

int in(void){
	stt++;
	if (stt == k){
		for (int i = 0; i < n; ++i){
			printf("%d ", a[i]);
		}
		free(a);
		free(mark);
		exit(0);
	}
}