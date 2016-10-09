#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>

#define MAX 10

using namespace std;

typedef struct Node Node;

struct Node{
	int x;
	int y;
	int deep;
};

int chess[MAX][MAX];
int mark[MAX][MAX];
int n;
int squares;
int min_squares;
int cur_squares;
Node *a;

int DFS(int index);

int main(int argc, char const *argv[]){
	int testCase = 0;
	while (1){
		// Init chess board
		squares = 0;
		scanf("%d", &n);
		// printf("n = %d\n", n);
		if (n == 0){
			return 0;
		}
		testCase++;
		int base;
		int offset;
		for (int i = 0; i < MAX; ++i){
			for (int j = 0; j < MAX; ++j){
				chess[i][j] = -1;
			}
		}
		for (int i = 0; i < n; ++i){
			scanf("%d%d", &base, &offset);
			squares += offset;
			offset += base;
			for (int j = base; j < offset; ++j){
				chess[i][j] = 0;
			}
		}
		// chess[0][0] = 0;

		// for (int i = 0; i < MAX; ++i){
		// 	for (int j = 0; j < MAX; ++j){
		// 		printf("%2d ", chess[i][j]);
		// 	}
		// 	puts("");
		// }

		// DFS
		a = (Node*) malloc(squares * sizeof(Node));
		cur_squares = squares;
		min_squares = squares;
		for (int i = 0; i < MAX; ++i){
			for (int j = 0; j < MAX; ++j){
				mark[i][j] = 0;
			}
		}
		mark[0][0] = 1;
		cur_squares--;
		// a[0] = new Node;
		a[0].x = 0;
		a[0].y = 0;
		// puts("start DFS");
		DFS(1);
		// puts("Done DFS");
		free(a);

		// for (int i = 0; i < MAX; ++i){
		// 	for (int j = 0; j < MAX; ++j){
		// 		printf("%2d ", chess[i][j]);
		// 	}
		// 	puts("");
		// }

		// puts("---");
		// for (int i = 0; i < MAX; ++i){
		// 	for (int j = 0; j < MAX; ++j){
		// 		printf("%2d ", mark[i][j]);
		// 	}
		// 	puts("");
		// }
		// puts("---");

		// printf("squares = %d min = %d\n", squares, min_squares);
		if (min_squares == 1){
			printf("Case %d, 1 square can not be reached.\n", testCase);
		}
		else{
			printf("Case %d, %d squares can not be reached.\n", testCase, min_squares);
		}
		// break;
	}
	return 0;
}

int DFS(int index){

	if (index >= squares){
		// puts("OK");
		min_squares = 0;
	}
	else{
		int x = a[index - 1].x;
		int y = a[index - 1].y;
		int canMove = 0;
		for (int j = 0; j < 8; ++j){
			int newX;
			int newY;
			switch (j){
				case 0:
					newX = x - 2;
					newY = y - 1;
					break;
				case 1:
					newX = x - 1;
					newY = y - 2;
					break;
				case 2:
					newX = x + 1;
					newY = y - 2;
					break;
				case 3:
					newX = x + 2;
					newY = y - 1;
					break;
				case 4:
					newX = x + 2;
					newY = y + 1;
					break;
				case 5:
					newX = x + 1;
					newY = y + 2;
					break;
				case 6:
					newX = x - 1;
					newY = y + 2;
					break;
				case 7:
					newX = x - 2;
					newY = y + 1;
					break;
			}
			// printf("after switch: index = %d j = %d\n", index, j);
			if ((newX >= 0) && (newX < MAX) && (newY >= 0) && (newY < MAX) && (chess[newX][newY] == 0) && (mark[newX][newY] == 0)){
				// printf("index = %d j = %d\n", index, j);
				canMove = 1;
				mark[newX][newY] = 1;
				cur_squares--;
				if (min_squares > cur_squares){
					min_squares = cur_squares;
				}
				// puts("---");
				// for (int i = 0; i < MAX; ++i){
				// 	for (int j = 0; j < MAX; ++j){
				// 		printf("%d ", mark[i][j]);
				// 	}
				// 	puts("");
				// }
				// puts("---");
				// Node *newNode = new Node;
				a[index].x = newX;
				a[index].y = newY;
				DFS(index + 1);
				cur_squares++;
				mark[newX][newY] = 0;
			}
			// puts("---");
			// for (int i = 0; i < MAX; ++i){
			// 	for (int j = 0; j < MAX; ++j){
			// 		printf("%d ", mark[i][j]);
			// 	}
			// 	puts("");
			// }
			// puts("---");
		}
		if (!canMove){
			// puts("could not move");
			// min_squares = (min_squares > cur_squares) ? cur_squares : min_squares;
		}
	}
	
}