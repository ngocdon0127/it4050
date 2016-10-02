/**
 * Đệ quy sinh tất cả các xâu nhị phân độ dài n
 * Trong quá trình sinh, kiểm tra độ dài của số số 0 liền nhau lớn nhất
 * Chặt đệ quy nếu có k số 0 liền nhau
 *
 * Độ phức tạp thuật toán O(n * n)
 */

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n;
int m;
int k;
int a[10000];
int cur_zero = 0;
int stt = 0;

int Try(int index);
int out(void);

int main(int argc, char const *argv[]){
	scanf("%d%d%d", &n, &k, &m);
	Try(0);
	printf("-1");
	return 0;
}

int Try(int index){
	if (index >= n){
		out();
	}
	else{
		for (int i = 0; i < 2; ++i){
			if (i){
				// s.push(cur_zero);
				int old_zero = cur_zero;
				cur_zero = 0;
				a[index] = i;
				Try(index + 1);
				// cur_zero = s.top();
				cur_zero = old_zero;
				// s.pop();
			}
			else{
				if (cur_zero + 1 < m){
					cur_zero++;
					a[index] = i;
					Try(index + 1);
					cur_zero--;
				}
			}
		}
	}
}

int out(void){
	stt++;
	if (stt == k){
		for (int i = 0; i < n; ++i){
			(i < n - 1) ? printf("%d ", a[i]) : printf("%d", a[i]);
		}
		exit(0);
	}
}