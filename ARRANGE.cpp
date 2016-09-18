/**
 * Vì 1 ^ n = 1 nên ta đọc input xem có bao nhiêu số 1, sau đó in ra output số số 1 tương ứng
 * 
 * Ta có a ^ b > b ^ a với b > a > e (2.71)
 *
 * Do đó ta kiểm tra nếu dãy nhập vào chỉ có 2 số 2 và 3 thì in ra 2 3,
 * Ngược lại sắp xếp dãy và in ra theo thứ tự giảm dần
 *
 * Độ phức tạp O(n * log(n))
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]){
	int testCases = 0;
	int n = 0;
	scanf("%d", &testCases);
	for(int i = 0; i < testCases; i++){
		scanf("%d", &n);
		int noOfOnes = 0;
		int *a = (int*) malloc(n * sizeof(int));
		int count = 0;
		int tmp = 0;
		for(int j = 0; j < n; j++){
			scanf("%d", &tmp);
			if (tmp == 1){
				noOfOnes++;
			}
			else{
				a[count++] = tmp;
			}
		}
		sort(a, a + count);
		while (noOfOnes--){
			printf("1 ");
		}
		if ((count == 2) && (a[0] == 2) && (a[1] == 3)){
			printf("2 3");
		}
		else {
			for(int v = count - 1; v >= 0; v--){
				printf("%d ", a[v]);
			}
		}
		puts("");
		free(a);
	}
	return 0;
}