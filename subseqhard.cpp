/**
 * Dùng map m để thể hiện map[i] = j nghĩa là có j dãy con trong mảng ban đầu có tổng là i
 *
 * Duyệt mảng ban đầu, lưu trữ tổng các phần tử từ đầu dãy đến phần tử hiện tại vào biến sum
 * Số dãy con thỏa mãn đề bài sẽ tăng thêm 1 lượng là m[sum - 47]
 *
 * Độ phức tạp thuật toán O(n * m) với m là số test case
 */

#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int testCases = 0;
int n = 0;
map<long long int, int> m;
int x = 0;
long long int count = 0;
long long int sum = 0;

int main(int argc, char const *argv[]){
	scanf("%d", &testCases);
	while (testCases--) {
		count = 0;
		sum = 0;
		scanf("%d", &n);
		m.clear();
		m[0] = 1;
		while (n--) {
			scanf("%d", &x);
			sum += x;
			m[sum]++;
			count += m[sum - 47];
		}
		printf("%lld\n", count);
	}
	return 0;
}