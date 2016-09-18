/**
 * Tạo 3 cấu trúc dữ liệu stack, queue và priority_queue tương ứng.
 * Đọc input, thực hiện các thao tác tương ứng và đánh dấu nếu cấu trúc dữ liệu nào cho ra output sai
 * Nếu kết thúc có nhiều hơn 1 cấu trúc dữ liệu chưa bị đánh dấu là sai thì output not sure
 * Nếu kết thúc có ít hơn 1 cấu trúc dữ liệu chưa bị đánh dấu là sai thì output impossible
 * Còn lại output ra cấu trúc dữ liệu tương ứng
 *
 * Độ phức tạp O(n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <string.h>


using namespace std;

stack<int> s;
queue<int> q;
priority_queue<int> pq;
int check[3] = {1, 1, 1};
int choices[2][2][2] = {0};

char result[3][50];



int main(int argc, char const *argv[]){
	choices[0][0][1] = 2;
	choices[0][1][0] = 1;
	choices[1][0][0] = 0;
	strcpy(result[0], "stack");
	strcpy(result[1], "queue");
	strcpy(result[2], "priority queue");
	int actions = -1;
	char buff[1000];
	// gets(buff);
	scanf("%d", &actions);
	// puts("finish gets");
	// puts(buff);
	while (actions > 0) {
		// printf("start new loop\n");
		// actions = atoi(buff);
		// printf("testCases: %d\n", actions);
		check[0] = check[1] = check[2] = 1;
		while (!s.empty()) {
			s.pop();
		}
		while (!q.empty()){
			q.pop();
		}
		while (!pq.empty()){
			pq.pop();
		}
		int action = 0;
		int value = 0;
		int s_ = 0;
		int q_ = 0;
		int pq_ = 0;
		for (int i = 0; i < actions; i++){
			// fflush(stdin);
			scanf("%d%d", &action, &value);
			// printf("%d%d", action, value);
			if (action == 1){
				if (check[0]){
					s.push(value);
				}
				if (check[1]){
					q.push(value);
				}
				if (check[2]){
					pq.push(value);
				}
			}
			else{
				if (check[0]){
					if (s.empty()){
						check[0] = 0;
					}
					else{
						s_ = s.top();
						s.pop();
						if (s_ != value){
							check[0] = 0;
						}
					}
					
				}
				if (check[1]){
					if (q.empty()){
						check[1] = 0;
					}
					else{
						q_ = q.front();
						q.pop();
						if (q_ != value){
							check[1] = 0;
						}
					}
				}
				if (check[2]){
					if (pq.empty()){
						check[2] = 0;
					}
					else{
						pq_ = pq.top();
						pq.pop();
						if (pq_ != value){
							check[2] = 0;
						}
					}
					
				}
			}
		}
		int sum = check[0] + check[1] + check[2];
		if (sum <= 0){
			puts("impossible");
		}
		else if (sum > 1){
			puts("not sure");
		}
		else {
			// if (check[0]){
			// 	puts("stack");
			// }
			// else if (check[1]){
			// 	puts("queue");
			// }
			// else {
			// 	puts("priority queue");
			// }
			puts(result[choices[check[0]][check[1]][check[2]]]);
		}
		// buff[0] = 0;
		// fflush(stdin);
		// gets(buff);
		actions = -1;
		scanf("%d", &actions);
	}

	return 0;
}