/**
 * Đọc dữ liệu, lưu các vị trí dirty tile và vị trí xuất phát của robot vào 1 tập v
 * Dùng BFS tính toán khoảng cách ngắn nhất từ mỗi đỉnh trong tập v tới các đỉnh còn lại,
 * sau khi kết thúc ta được đồ thị gồm:
 * Các cạnh là các dirty tile và vị trí xuất phát của robot
 * Các cạnh là khoảng cách ngắn nhất từ mỗi đỉnh tới các đỉnh còn lại
 * 
 * Bài toán trở thành bài toán TSP
 *
 * Độ phức tạp O(V * (V + E) + V!) ~ O(V * V + V!) với V là số dirty tile, E
 */

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>

#define MAX 20 // Set MAX too large will got TLE
#define UPPER_MIN 1000000000

using namespace std;

typedef struct Node Node;

struct Node{
	int x;
	int y;
	int deep;
};

int maxs = MAX * MAX;
int floor[MAX][MAX];
int cost[MAX * MAX][MAX * MAX];
int markBFS[MAX * MAX][MAX * MAX];
int w;
int h;
int x0;
int y0;
int name0;
vector<Node*> v;
int size = 0; // size of v <=> number of dirty tiles

int a[MAX * MAX];
int min_dis = UPPER_MIN;
int dis = 0;
int dd[MAX * MAX];
int check = true;

int pos = 0;
int posX = 0;
int posY = 0;
int newX;
int newY;
int x;
int y;

int initGraph(void);
int TSP(void);

int Try(int i);
int in(void);

int main(int argc, char const *argv[]){
	double graphTime = 0;
	double tspTime = 0;
	char garbage[10];
	while (1){
		v.clear();
		size = 0;
		scanf("%d%d\n", &w, &h);
		if (!w && !h){
			break;
		}
		char tmp;
		for (int i = 0; i < h; ++i){
			for (int j = 0; j < w; ++j){
				scanf("%c", &tmp);
				floor[i][j] = tmp;
				if ((tmp == 'o') || (tmp == '*')){
					if (tmp == 'o'){
						// Robot
						x0 = i;
						y0 = j;
						name0 = size;
						floor[i][j] = '*'; // consider robot is a vertex in Dirty tiles' graph
					}
					Node *node = new Node;
					node->x = i;
					node->y = j;
					node->deep = 0;
					// node->parent = NULL;
					// node->name = v.size();
					v.push_back(node);
					size++;
				}
			}
			// scanf("%c%c", &tmp, &tmp); // Remove \r\n in the end of line
			gets(garbage);
		}

		// Print data
		// for (int i = 0; i < h; ++i){
		// 	for (int j = 0; j < w; ++j){
		// 		printf("%c", floor[i][j]);
		// 	}
		// 	puts("");
		// }

		// puts("Position of dirty titles:");
		// for (int i = 0; i < v.size(); ++i){
		// 	printf("(%d, %d) ", v[i]->x, v[i]->y);
		// }

		// puts("");

		// Init Graph using BFS
		// printf("Initing graph for test case w = %d h = %d\n", w, h);
		// Timer ti;
		initGraph();
		// graphTime += ti.getElapsedTime();

		// TSP
		// Timer ti1;
		TSP();
		// tspTime += ti1.getElapsedTime();
	}

	// printf("graphTime %.5f\ntspTime %.5f\n", graphTime, tspTime);
	
	return 0;
}

int initGraph(void){
	// size = v.size();
	for (int i = 0; i < maxs; ++i){
		for (int j = 0; j < maxs; ++j){
			cost[i][j] = -1;
		}
	}

	for(int i = 0; i < size; i++){
		// printf("BFS for %d\n", i);
		for (int k = 0; k < maxs; ++k){
			for (int j = 0; j < maxs; ++j){
				markBFS[k][j] = 0;
			}
		}
		queue<Node*> q;
		Node *start = v[i];
		q.push(start);
		markBFS[start->x][start->y] = 1;
		while (!q.empty()){
			Node *node = q.front();
			x = node->x;
			y = node->y;
			q.pop();
			if (floor[x][y] == '*'){
				// Dirty title
				
				for(pos = 0; pos < size; pos++){
					posX = v[pos]->x;
					posY = v[pos]->y;
					// printf("pos %d x %d y %d startX %d startY %d posX %d posY %d\n", pos, x, y, start->x, start->y, posX, posY);
					if (((x != start->x) || (y != start->y)) && (x == posX) && (y == posY)){
						break;
					}
				}
				// printf("reach %d %d pos = %d\n", x, y, pos);
				if (pos < size){
					cost[i][pos] = node->deep;
				}
				// cost[pos][start->name] = node->deep;
			}
			// printf("Clean tile %d %d\n", x, y);
			// Clean title

			// Up
			newX = x - 1;
			newY = y;
			if ((newX >= 0) && (newX < h) && (floor[newX][newY] != 'x') && (!markBFS[newX][newY])){
				Node *up = new Node;
				up->x = newX;
				up->y = newY;
				up->deep = node->deep + 1;
				// up->parent = node;
				q.push(up);
				markBFS[newX][newY] = 1;
				// printf("Pushing %d %d\n", newX, newY);
			}

			// Down
			newX = x + 1;
			newY = y;
			if ((newX >= 0) && (newX < h) && (floor[newX][newY] != 'x') && (!markBFS[newX][newY])){
				Node *down = new Node;
				down->x = newX;
				down->y = newY;
				down->deep = node->deep + 1;
				// down->parent = node;
				q.push(down);
				markBFS[newX][newY] = 1;
				// printf("Pushing %d %d\n", newX, newY);
			}

			// Left
			newX = x;
			newY = y - 1;
			if ((newY >= 0) && (newY < w) && (floor[newX][newY] != 'x') && (!markBFS[newX][newY])){
				Node *left = new Node;
				left->x = newX;
				left->y = newY;
				left->deep = node->deep + 1;
				// left->parent = node;
				q.push(left);
				markBFS[newX][newY] = 1;
				// printf("Pushing %d %d\n", newX, newY);
			}

			// Right
			newX = x;
			newY = y + 1;
			if ((newY >= 0) && (newY < w) && (floor[newX][newY] != 'x') && (!markBFS[newX][newY])){
				Node *right = new Node;
				right->x = newX;
				right->y = newY;
				right->deep = node->deep + 1;
				// right->parent = node;
				q.push(right);
				markBFS[newX][newY] = 1;
				// printf("Pushing %d %d\n", newX, newY);
			}
		}

		// puts("Cost:");
		// for (int i = 0; i < size; ++i){
		// 	for (int j = 0; j < size; ++j){
		// 		printf("%d ", cost[i][j]);
		// 	}
		// 	puts("");
		// }
	}
	// puts("Cost:");
	// for (int i = 0; i < size; ++i){
	// 	for (int j = 0; j < size; ++j){
	// 		printf("%d ", cost[i][j]);
	// 	}
	// 	puts("");
	// }
}

int TSP(void){
	check = true;
	min_dis = UPPER_MIN;
	for (int i = 0; i < maxs; ++i){
		dd[i] = 0;
	}
	dis = 0;
	a[1] = name0;
	dd[name0] = 1;
	Try(2);
	(min_dis == UPPER_MIN) ? (min_dis = -1) : 1;
	printf("%d\n", min_dis);
}

int Try(int i){
	if (i > size) {
		in();
	}
	else{
		for(int j = 0; j < size; j++){
			if ((dd[j] == 0) && (cost[a[i - 1]][j] != -1)) {
				dis += cost[a[i - 1]][j];
				//printf("dis=%i check1=%i\n", dis, check1);
				if (dis >= min_dis) {
					dis -= cost[a[i - 1]][j];
					continue;
				}
				a[i] = j;
				dd[j] = 1;
				Try(i + 1);
				dis -= cost[a[i - 1]][j];
				dd[j] = 0;	//Tra de quy
			}
		}
	}
	return 0;
}

int in(void){

	if (min_dis > dis){
		min_dis = dis;
	}
	return 0;
}