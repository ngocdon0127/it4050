/**
 * Đọc từng dòng input 
 * Sắp xếp 3 giá trị đầu vào thành dãy không giảm
 * In ra giá trị thứ 2
 *
 * Độ phức tạp thuật toán: O(n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
#include <ctype.h>

using namespace std;

int n = 0;

int middle(int a, int b, int c){
	if (a < b){
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (b < c){
		int tmp = b;
		b = c;
		c = tmp;
	}
	if (a < b){
		int tmp = a;
		a = b;
		b = tmp;
	}
	return b;
}

int main(int argc, char **argv){
	cin >> n;
	int p1, p2, p3;
	for (int i = 0; i < n; ++i){
		cin >> p1 >> p2 >> p3;
		cout << "Case " << i + 1 << ": " << middle(p1, p2, p3) << endl;
	}
	return 0;
}