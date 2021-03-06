/**
 * Ý nghĩa các biến:
 * Mảng cols: b[i] = 1 nghĩa là cột  i có 1 quân hậu
 * Mảng c và mảng d có ý nghĩa tương tự.
 * c: mảng ứng với các đường chéo có tổng i + j cố định
 * d: mảng ứng với các đường chéo có hiệu i - j cố định
 *
 * Các hole có chess[i][j] = -1
 * Đệ quy quay lui, thử chèn mỗi hàng 1 quân hậu
 * cập nhật các giá trị của mảng b, c, d
 * Nếu điền được n quân hậu thì tăng biến đếm lên 1 đơn vị
 *
 * Độ phức tạp O(n!)
 */

#include <stdio.h>
#include <stdlib.h>

int *a;
int *b;
int *c;
int *d;
int *chess;
int holes = 0;
int n;
int count = 0;
int queens = 0;

void set(int i);
void output(void);

int main(void){
	while (1){
		count = 0;
		queens = 0;
		scanf("%d", &n);
		if (n == 0){
			return 0;
		}
		scanf("%d", &holes);
		int x;
		int y;
		chess = (int*) calloc(n * n, sizeof(int));
		for(int i = 0; i < holes; i++){
			scanf("%d%d", &x, &y);
			chess[x * n + y] = -1;
		}
		b = (int*) calloc(n + 1 , sizeof(int));
		
		c = (int*) calloc(2 * n + 1, sizeof(int));
		
		d = (int*) calloc(2 * n + 1, sizeof(int));
		
		set(1);
		
		printf("%d\n", count);
		free(b);
		free(c);
		free(d);
		free(chess);
	}
	
}

void set(int i){
	int j;
	if (i > n){
		output();
	}
	else {
		for(j = 1; j <= n; j++){
			if ((chess[(i - 1) * n + j - 1] == -1) || (b[j]) || (c[i - j + n - 1]) || (d[i + j])){
		
				continue;
			}
			b[j] = 1;
			c[i - j + n - 1] = 1;
			d[i + j] = 1;

			set(i + 1);

			b[j] = 0;
			c[i - j + n- 1] = 0;
			d[i + j] = 0;
		}
	}
}

void output(){
	// if (queens == n){
		count++;
	// }
	// int i;
	// for(i = 1; i <= n; i++)
	// 	printf("{%i,%i} ", i, a[i]);
	// puts("");
	return;
}