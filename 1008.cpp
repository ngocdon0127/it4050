/**
 * Đệ quy sinh các phần từ của tổ hợp chập m của n
 * Sinh các phần tử của tổ hợp theo thứ tự tăng dần
 * Mỗi phần tử, chọn sinh trong khoảng phù hợp với vị trí của nó trong mảng a
 *
 * Độ phức tạp O(n * n)
 */

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
	
	Try(1);
	printf("-1");
	
	return 0;
}

int Try(int index){
	if (index > m){
		out();
	}
	else {
		for (int i = a[index - 1] + 1; i <= n - m + index; i++){
			a[index] = i;
			Try(index + 1);
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