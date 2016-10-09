#include <stdio.h>
#include <stdlib.h>

#define MAX 8

int a[9][9] = {0};
int mark[9][9] = {0};
int markx[9][9] = {0};
int marky[9][9] = {0};
int markgrid[2][2][9] = {0};
int flag = 0;
int testCases = 0;
int done = 0;


int process(int testCase);
int Try(int x, int y, int testCase);

int main(int argc, char const *argv[]){
	scanf("%d", &testCases);
	for (int i = 0; i < testCases; ++i){
		process(i + 1);
	}
	return 0;
}

int process(int testCase){
	// reset
	for (int i = 0; i <= 8; ++i){
		for (int j = 0; j <= 8; ++j){
			a[i][j] = 0;
			markx[i][j] = 0;
			marky[i][j] = 0;
			mark[i][j] = 0;
		}
	}

	for (int i = 0; i <= 8; ++i){
		markgrid[0][0][i] = 0;
		markgrid[0][1][i] = 0;
		markgrid[1][0][i] = 0;
		markgrid[1][1][i] = 0;
	}

	int check = 1;
	flag = 0;
	done = 0;

	int tmp = 0;

	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			scanf("%d", &tmp);
			if (check){
				if (tmp){
					a[i][j] = tmp;
					mark[i][j] = 1;
					if (markx[i][tmp]){
						check = 0;
					}

					if (marky[j][tmp]){
						check = 0;
					}

					if (markgrid[i / 4][j / 4][tmp] > 1){
						check = 0;
					}
					markx[i][tmp] = 1;
					marky[j][tmp] = 1;
					markgrid[i / 4][j / 4][tmp]++;
				}
				
			}
			else{
				a[i][j] = tmp;
			}
			
		}
	}
	// for (int i = 0; i < 8; ++i){
	// 	for (int j = 0; j < 8; ++j){
	// 		printf("%d ", a[i][j]);
	// 	}
	// 	puts("");
	// }

	// for (int i = 0; i < 8; ++i){
	// 	for (int j = 0; j < 8; ++j){
	// 		printf("%d ", mark[i][j]);
	// 	}
	// 	puts("");
	// }

	// return 0;

	if (!check){
		printf("Test case #%d: NO\n", testCase);
	}
	else{
		Try(0, 0, testCase);
		if (!done){
			printf("Test case #%d: NO\n", testCase);
		}
	}
}

int Try(int i, int j, int testCase){
	if (flag){
		return 0;
	}
	if (mark[i][j] == 1) {
		Try(i, j + 1, testCase);
//		return 0;
	}
	else{
		if (j >= MAX){
			if (i >= MAX - 1){
				printf("Test case #%d: YES\n", testCase);
				for(int k = 0; k < MAX; k++){
					for(int u = 0; u < MAX; u++){
						printf("%d", a[k][u]);
						if (u < MAX - 1){
							printf(" ");
						}
					}
					// if (k == MAX - 1) printf("\n%d\n", ++count);
					puts("");
				}
				flag = 1;
				done = 1;
				// puts("");
				//count++;
				//if (count%1000000==0) printf("%d\n", count);
			}
			else Try(i + 1, 0, testCase);
		}
		else{
			for(int k = 1; k <= MAX; k++){
				if ((markx[i][k] == 1) || (marky[j][k] == 1) || (markgrid[i / 4][j / 4][k] > 1)) {
					continue;
				}
				markx[i][k] = 1;
				marky[j][k] = 1;
				markgrid[i / 4][j / 4][k]++;
				a[i][j] = k;
				Try(i, j + 1, testCase);
				markx[i][k] = 0;
				marky[j][k] = 0;
				markgrid[i / 4][j / 4][k]--;
			}
		}
	}
	return 0;
}