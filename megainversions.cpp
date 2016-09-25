/**
 * Sử dụng cây Fenwick Tree (BIT) để tính số inversions trong dãy
 *
 * Mảng a ban đầu có n phần tử, mỗi phần tử có giá trị từ 1 đến 100000.
 * Ta sẽ dùng 1 mảng arr[100000] để đánh dấu, trong đó
 * với arr[i] = j nghĩa là trong mảng ban đầu có j phần tử có giá trị là i
 * Dùng cây Fenwick để tính prefix sum của mảng arr. (Không cần lưu mảng arr)
 *
 * Duyệt a[] từ đầu tới cuối, cập nhật BIT và tính tổng các phần tử từ arr[a[i] + 1] đến arr[100000]
 * ta sẽ được số phần tử nằm trước a[i] và có giá trị lớn hơn a[i], lưu vào bigger[i]
 *
 * Reset tất cả các phần tử của BIT về 0.
 *
 * Duyệt a[] từ cuối lên đầu, cập nhật BIT và tính tổng các phần tử từ arr[0] đến arr[i - 1]
 * ta sẽ được số phần từ nằm sau a[i] và có giá trị nhỏ hơn a[i], lưu và smaller[i]
 *
 * Tính tổng smaller[i] * bigger[i] (với i chạy từ 1 đến n) sẽ được kết quả là số Mega Inversions.
 *
 * Độ phức tạp thuật toán O(n * log(n))
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100100

int fenwick[MAX] = {0};
int n = 0;
long long int smaller[MAX] = {0};
long long int bigger[MAX] = {0};


long long int sum(int index){
	long long int result = 0;
	while (index > 0){
		result += fenwick[index];
		index -= index & (-index);
	}
	return result;
}

int update(int index, int val){
	while (index <= n){
		fenwick[index] += val;
		index += index & (-index);
	}
}

int main(int argc, char const *argv[]){
	scanf("%d", &n);


	int *a = (int*) malloc((n + 1) * sizeof(int));

	for (int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}


	// count smaller
	for(int i = n; i >= 1; i--){
		smaller[i] = sum(a[i] - 1);
		update(a[i], 1);
	}


	// reset Fenwick
	for (int i = 0; i < MAX; ++i){
		fenwick[i] = 0;
	}


	// count bigger
	for (int i = 1; i <= n; ++i){
		bigger[i] = sum(n) - sum(a[i]);
		update(a[i], 1);
	}

	
	long long int result = 0;
	for (int i = 1; i <= n; ++i){
		result += smaller[i] * bigger[i];
	}

	printf("%lld", result);

	return 0;
}