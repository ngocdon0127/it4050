/**
 * Author : ngocdon0127
 * Date   : 2016-09-08 17 : 22 : 00
 *
 * Giải thuật:
 * Kiểm tra xem bishop có thể đi từ điểm thứ nhất tới điểm thứ hai hay không.
 *
 * Nếu đi được, xảy ra 3 trường hợp:
 * - TH1: Điểm đầu trùng điểm cuối => Output
 * - TH2: Điểm đầu và điểm cuối cùng nằm trên 1 đường chéo
 * - TH3: Số nước cần đi là 2 nước. (startX, startY) => (middleX, middleY) => (finishX, finishY)
 * Với middleX và middleY là nghiệm của hệ phương trình:
 *
 * middleX + middleY = startX + startY và middleX - middleY = finishX - finishY
 *
 * hoặc hệ:
 * 
 * middleX - middleY = startX - startY và middleX + middleY = finishX + finishY
 *
 * Nếu trong 2 nghiệm này có 1 nghiệm nằm ngoài bàn cờ thì cần loại nghiệm đó, ngược lại in ra 1 trong 2 nghiệm
 *
 * Độ phức tạp thuật toán: O(n) với n là số test cases
 */

#include <stdio.h>
#include <stdlib.h>
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
	process();
	return 0;
}

int process(){
	cin >> n;
	for (int i = 0; i < n; ++i){
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
			// - TH1: Điểm đầu trùng điểm cuối
			if ((startX == finishX) && (startY == finishY)){
				printf("0 %c %d\n", startX + 65, startY + 1);
			}
			// - TH2: 2 điểm nằm trên cùng 1 đường chéo
			else if ((startX - startY == finishX - finishY) || (startX + startY == finishX + finishY)){
				printf("1 %c %d %c %d\n", startX + 65, startY + 1, finishX + 65, finishY + 1);
			}
			// - TH3: TH còn lại
			else {
				int middleX = (startX + startY + finishX - finishY) / 2;
				int middleY = middleX - finishX + finishY;

				// If the above coordination is out of range.
				if ((middleX < 0) || (middleX > 7) || (middleY < 0) || (middleY > 7)){
					middleX = (startX - startY + finishX + finishY) / 2;
					middleY = finishX + finishY - middleX;
				}
				printf("2 %c %d %c %d %c %d\n", startX + 65, startY + 1, middleX + 65, middleY + 1, finishX + 65, finishY + 1);
			}
		
		}
		else {
			printf("Impossible\n");
		}
	}
}

int checkCanReach(int x1, int y1, int x2, int y2){
	if (abs(x1 + y1 - x2 - y2) % 2){
		return -1;
	}
	return 0;
}
