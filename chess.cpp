/**
 * Author : ngocdon0127
 * Date   : 2016-09-02 17 : 22 : 00
 *
 * Cấu trúc dữ liệu:
 * Node chứa 2 tọa độ x, y phạm vi từ 0 đến 7, ứng với mỗi ô trên bàn cờ
 * Node m chứa con trỏ parent trỏ đến Node n ý nghĩa là từ n, bishop có thể đi trực tiếp tới m bằng 1 nưóc đi hợp lê
 * Node chứa số nguyên deep ý nghĩa Từ vị trí ban đầu có thể tới vị trí hiện tại bằng deep nước đi hợp lệ
 *
 * Giái thuật:
 * Dùng thuật toán BFS để tìm đường đi ngắn nhất từ vị trí ban đầu tới vị trí đích
 * 
 * Ý nghĩa các biến:
 * Queue q: Hàng đợi phục vụ BFS
 * Mảng chess[i][j]: Mảng đánh dấu phục vụ BFS
 * Set s: Tập hợp tất cả các Node được sinh ra, dùng để giải phóng bộ nhớ
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <set>
#include <iostream>
#include <ctype.h>

using namespace std;

typedef struct Node Node;

struct Node {
	int x;
	int y;
	int deep;
	Node* parent;
};

int chess[8][8] = {0};
queue<Node*> q;
set<Node*> s;
int n = 0;
char startX = '1';
char finishX = '1';
int startY = 0;
int finishY = 0;


int init();
int process();
int reset();
int release();
int printNode(Node *node);
int checkCanReach(int x1, int y1, int x2, int y2);
int checkFinish(Node *node, int finishX, int finishY);
int printSolution(Node *node);


int main(int argc, char **argv){
	init();
	process();
	release();
	return 0;
}

int init(){
	s.clear();
	reset();
}


int reset(){
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			chess[i][j] = 0;
		}
	}
	while (!q.empty()){
		q.pop();
	}
}

int process(){
	cin >> n;
	for (int i = 0; i < n; ++i){
		reset();
		cin >> startX >> startY >> finishX >> finishY;
		startX = toupper(startX);
		finishX = toupper(finishX);
		if ((startX < 'A') || (startX > 'H')){
			printf("Impossible\n");
			continue;
		}

		if ((finishX < 'A') || (finishX > 'H')){
			printf("Impossible\n");
			continue;
		}

		if ((startY < 1) || (startY > 8)){
			printf("Impossible\n");
			continue;
		}

		if ((finishY < 1) || (finishY > 8)){
			printf("Impossible\n");
			continue;
		}

		startX -= 65;
		finishX -= 65;
		startY -= 1;
		finishY -= 1;
		if (checkCanReach(startX, startY, finishX, finishY) != -1){
			Node *start = new Node;
			start->x = startX;
			start->y = startY;
			start->deep = 0;
			start->parent = NULL;
			q.push(start);
			chess[startX][startY] = 1;
			s.insert(start);
			while (!q.empty()){
				Node *node = q.front();
				q.pop();
				if (checkFinish(node, finishX, finishY)){
					// puts("Found");
					if (node->deep > 4){
						printf("Impossible");
					}
					else {
						printf("%d", node->deep);
						printSolution(node);
					}
					
					while (!q.empty()){
						q.pop();
					}
				}
				else {
					for (int k = 0; k < 8; ++k){
						for (int j = 0; j < 8; ++j){
							if ((node->x - node->y == k - j) || (node->x + node->y == k + j)){
								if (!chess[k][j]){
									Node *newNode = new Node;
									newNode->x = k;
									newNode->y = j;
									newNode->parent = node;
									newNode->deep = node->deep + 1;
									chess[k][j] = 1;
									q.push(newNode);
									s.insert(newNode);
								}
							}
							
						}
					}
				}
			}
		}
		else {
			printf("Impossible");
		}
		puts("");
	}
}

int release(){
	for(set<Node*>::iterator it = s.begin(); it != s.end(); it++){
		Node *node = *it;
		delete node;
	}
	s.clear();
	return 0;
}

int checkCanReach(int x1, int y1, int x2, int y2){
	if (abs(x1 + y1 - x2 - y2) % 2){
		return -1;
	}
	return 0;
}

int checkFinish(Node *node, int finishX, int finishY){
	if ((node->x == finishX) && (node->y == finishY)){
		return 1;
	}
	return 0;
}

int printNode(Node *node){
	printf("Node %c %d %d\n", node->x + 65, node->y + 1, node->parent == NULL);
	return 0;
}

int printSolution(Node *node){
	// printNode(node);
	if (node->parent){
		printSolution(node->parent);
		printf(" %c %d", node->x + 65, node->y + 1);
	}
	else {
		printf(" %c %d", node->x + 65, node->y + 1);
	}
}
