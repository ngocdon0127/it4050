/**
 * Sử dụng BFS
 * 2 trạng thái mới được sinh ra nếu có 2 pebble liền nhau
 * Với mỗi trạng thái không có trạng thái con, tính số pebble còn lại
 * Cập nhật biến count
 *
 * Độ phức tạp thuật toán O(N)
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<string, int> mark;
queue<string> q;

int N = 23;

int main(int argc, char const *argv[]){
	int testCases = 0;
	scanf("%d", &testCases);

	while (testCases--){
		string start;
		cin >> start;

		mark.clear();
		while (!q.empty()){
			q.pop();
		}

		mark[start] = 1;
		q.push(start);
		int count = 100;

		// BFS
		while (!q.empty()){
			string s = q.front();
			q.pop();

			int canMove = 0;
			string tmp = s;
			for (int i = 0; i < N - 1; ++i){ // i < N - 1 not N - 2
				if ((s.at(i) == 'o') && (s.at(i + 1) == 'o')) {
					if ((i + 2 < N) && (s.at(i + 2) == '-')) {
						s.at(i) = '-';
						s.at(i + 1) = '-';
						s.at(i + 2) = 'o';
						if (!mark[s]){
							mark[s] = 1;
							q.push(s);
							
						}
						s = tmp; // recovery s
						canMove = 1;
					}
					if ((i > 0) && (s.at(i - 1) == '-')){
						s.at(i) = '-';
						s.at(i + 1) = '-';
						s.at(i - 1) = 'o';
						if (!mark[s]){
							mark[s] = 1;
							q.push(s);
							
						}
						s = tmp; // recovery s
						canMove = 1;
					}
				}
			}

			// Can not make a move
			// Count the number of pebbles
			if (!canMove){
				int c = 0;
				for (int i = 0; i < tmp.size(); ++i){
					if (tmp.at(i) == 'o'){
						c++;
					}
				}
				if (c < count){
					count = c;
				}
			}

		}
		printf("%d\n", count);
	}
	return 0;
}