#include <stdio.h>
#include <stdlib.h>
#include <queue>
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
int n = 0;
char fnamein[] = "chess-input.txt";
char fnameout[] = "chess-output.txt";
FILE *fin = NULL;
FILE *fout = NULL;
char startX = 'A';
char finishX = 'A';
int startY = 0;
int finishY = 0;
int steps = 0;


int init();
int process();
int convertX(char ch);
int convertY(int y);
int reset();
int release();
int checkCanReach(int x1, int y1, int x2, int y2);
int printNode(Node *node);
int checkFinish(Node *node, int finishX, int finishY);
int printSolution(Node *node);
int printSolutionToFile(Node *node);


int main(int argc, char **argv){
	if (init() == -1){
		puts("Error while opening files.");
		return 0;
	}
	process();
	release();
	return 0;
}


int init(){
	// fin = fopen(fnamein, "r");
	// if (!fin){
	// 	return -1;
	// }
	// fout = fopen(fnameout, "w");
	// if (!fout){
	// 	return -1;
	// }
	return 0;
}

int reset(){
//	n = 0;
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			chess[i][j] = 0;
		}
	}
	while (!q.empty()){
		q.pop();
	}
	steps = 0;
}

int process(){
	// fscanf(fin, "%d\n", &n);
	// int scanResult = scanf("%d", &n);
	cin >> n;
//	printf("n = %d\n", n);
	for (int i = 0; i < n; ++i){
		reset();
		// fscanf(fin, "%c %d %c %d\n", &startX, &startY, &finishX, &finishY);
		// fflush(stdin);
		// scanResult = scanf("%c %d %c %d", &startX, &startY, &finishX, &finishY);
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
		// printf("%c %d %c %d\n", startX + 65, startY + 1, finishX + 65, finishY + 1);
		if (checkCanReach(startX, startY, finishX, finishY) != -1){
			Node *start = new Node;
			start->x = startX;
			start->y = startY;
			start->deep = 0;
			start->parent = NULL;
			q.push(start);
			chess[startX][startY] = 1;
			while (!q.empty()){
				Node *node = q.front();
				q.pop();
				// printf("checking %c %d...\n", node->x + 65, node->y + 1);
				if (checkFinish(node, finishX, finishY)){
					// puts("Found");
					// printf("%c %d, ", startX + 65, startY + 1);
					if (node->deep > 4){
						printf("Impossible");
					}
					else {
						printf("%i", node->deep);
						printSolution(node);
					}
					
					// printSolutionToFile(node);
					// printf("%c %d\n", finishX + 65, finishY + 1);
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
								}
							}
							
						}
					}
				}
			}
		}
		else {
			// fprintf(fout, "Impossible");
			printf("Impossible");
		}
//		if (i < n - 1){
			// fprintf(fout, "\n");
			puts("\n");
//		}
	}
}

int convertX(char ch){
	return ch - 65;
}

int convertY(int y){
	return y - 1;
}

int release(){
	// fclose(fin);
	// fclose(fout);
	return 0;
}

int checkCanReach(int x1, int y1, int x2, int y2){
	if ((abs(x1 + y1 - x2 - y2) % 2) && (abs(x1 - y1 - x2 + y2) % 2)){
		return -1;
	}
	return 0;
}

int checkFinish(Node *node, int finishX, int finishY){
	if (node->x == finishX && (node->y == finishY)){
		return 1;
	}
	return 0;
	if (((node->x - node->y) == (finishX - finishY)) || ((node->x + node->y) == (finishX + finishY))){
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
		// steps++;
		printSolution(node->parent);
		printf(" %c %d", node->x + 65, node->y + 1);
	}
	else {
		printf(" %c %d", node->x + 65, node->y + 1);
	}
}

int printSolutionToFile(Node *node){
	// printNode(node);
	// if (node->parent){
	// 	steps++;
	// 	printSolutionToFile(node->parent);
	// 	fprintf(fout, " %c %d", node->x + 65, node->y + 1);
	// }
	// else {
	// 	fprintf(fout, "%d %c %d", steps, node->x + 65, node->y + 1);
	// }
}
