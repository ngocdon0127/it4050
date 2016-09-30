#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

int m, n, k;
int *a;
int *mark;
int stt = 0;

int inc(int index);
int Try(int index);
int out(void);

int main(int argc, char const *argv[]){
	scanf("%d%d%d", &n, &m, &k);
	a = (int*) calloc(m + 1, sizeof(int));
	mark = (int*) calloc(m + 2, sizeof(int));
	// for (int i = 1; i <= m; ++i){
	// 	a[i] = i;
	// }
	// while (k--){
	// 	inc(m);
	// }
	Try(1);
	printf("-1");
	// printf("stt = %d\n", stt);
	return 0;
}

int inc(int index){
	int i = a[index];
	while (mark[i]){
		i++;
	}
	if (i < index + 1){
		mark[a[index]] = 0;
		mark[i] = 1;
		a[index] = i;
		return 1;
	}
	else{

	}
}

int Try(int index){
	if (index > m){
		out();
	}
	else {
		for (int i = a[index - 1] + 1; i <= n - m + index; i++){
			a[index] = i;
			// if (i > n){
			// 	printf("i = %d n = %d m = %d\n", i, n, m);
			// }
			Try(index + 1);
			// if (!mark[i]){
			// 	a[index] = i;
			// 	mark[i] = 1;
			// 	Try(index + 1);
			// 	mark[i] = 0;
			// }
		}
	}
}

int out(void){
	stt++;
	if (stt == k){
		for (int i = 1; i <= m; ++i){
			printf("%d ", a[i]);
		}
		exit(0);
	}
}