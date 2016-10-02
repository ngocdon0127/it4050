/**
 * Sinh các hoán vị của n thành phố
 *
 * Người du lịch xuất phát từ thành phố thứ nhất
 * Trong khi sinh hoán vị, cập nhật tổng chi phí đã đi tới thành phố thứ i
 * Nếu chi phí lớn hơn chi phí của hành trình nhỏ nhất đang được lưu lại thì hành trình đang xét không phái là hành trình tối ưu,
 * => chặt đệ quy
 *
 * Độ phức tạp O(n!)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int n;
int a[MAX], b[MAX], dd[MAX]={0}, kc[MAX][MAX];
int time1=0, time2=0;
int min = 100000000, check=0;
int dis = 0;

int Try(int i);
int in(void);

int main(void){
	int m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= n; ++j){
			kc[i][j] = -1;
		}
	}
	for (int i = 0; i <= n; ++i){
		kc[0][i] = kc[i][0] = 0;
	}
	int c1, c2, price;
	for (int i = 0; i < m; ++i){
		scanf("%d%d%d", &c1, &c2, &price);
		kc[c1][c2] = price;
	}
	a[1] = 1;
	dd[1] = 1;
	Try(2);
	printf("%d", min);
	return 0;
}

int Try(int i){
	int j;
	if (i > n) {
		in();
	}
	else{
		for(j = 1; j <= n; j++){
			if ((dd[j] == 0) && (kc[a[i - 1]][j] != -1)) {
				dis += kc[a[i - 1]][j];
				//printf("dis=%i check1=%i\n", dis, check1);
				if (dis >= min) {
					dis -= kc[a[i - 1]][j];
					continue;
				}
				a[i] = j;
				dd[j] = 1;
				Try(i + 1);
				dis -= kc[a[i - 1]][j];
				dd[j] = 0;	//Tra de quy
			}
		}
	}
	return 0;
}

int in(void){
	int i;

	if (kc[a[n]][a[1]] == -1){
		return 0;
	}
	dis += kc[a[n]][a[1]];
	if (min > dis){
		min = dis;
	}
	dis -= kc[a[n]][a[1]];
	return 0;
}