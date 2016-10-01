#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int n;
int a[MAX], b[MAX], dd[MAX]={0}, kc[MAX][MAX];
int time1=0, time2=0;
int min = 100000000, check=0;
int dis = 0;

int Try(int i);
int in(void);

int main(void){
	// FILE *f;
	// int i, j;
	// f=fopen("Nguoi_Du_Lich.txt", "rt");
	// if (f==NULL){
	// 	printf("Khong the mo file Nguoi_Du_Lich.txt.");
	// 	getch();
	// 	return 0;
	// }
	// fscanf(f, "%i", &n);
	// printf("116220");
	// return 0;
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= n; ++j){
			kc[i][j] = -1;
		}
	}
	for (int i = 0; i <= n; ++i){
		kc[0][i] = kc[i][0] = 0;
	}
	int c1, c2, price;
	for (int i = 0; i < m; ++i){
		scanf("%d%d%d", &c1, &c2, &price);
		kc[c1][c2] = price;
		// if (kc[c2][c1] > 0){
		// 	printf("Hehe %d %d\n", c1, c2);
		// }
		// kc[c2][c1] = price;

	}
	// for(i=0; i<=n; i++)
	// 	for(j=0; j<=n; j++)
	// 		fscanf(f, "%i", *(kc+i)+j);	
	// fclose(f);
	//time1=time(NULL);
	a[1] = 1;
	dd[1] = 1;
	Try(2);
	//time2=time(NULL);
	// for(i=1; i<n+2; i++) printf("%i ", b[i]);
	// printf("\nkc=%i", min);
	printf("%d", min);
	//printf("\ntime=%i", time2-time1);
	return 0;
}

int Try(int i){
	int j;
	if (i > n) {
		in();
	}
	else{
		for(j = 1; j <= n; j++){
			if ((dd[j] == 0) && (kc[a[i - 1]][j] != -1)) {
				dis += kc[a[i - 1]][j];
				//printf("dis=%i check1=%i\n", dis, check1);
				if (dis >= min) {
					dis -= kc[a[i - 1]][j];
					continue;
				}
				a[i] = j;
				dd[j] = 1;
				Try(i + 1);
				dis -= kc[a[i - 1]][j];
				dd[j] = 0;	//Tra de quy
			}
		}
	}
	return 0;
}

int in(void){
	int i;

	if (kc[a[n]][a[1]] == -1){
		return 0;
	}
	dis += kc[a[n]][a[1]];
	if (min > dis){
		min = dis;
		// for(i = 1; i <= n; i++)
		// 	b[i] = a[i];
		// b[n + 1] = a[1];
	}
	//dis=0;
	dis -= kc[a[n]][a[1]];
	return 0;
}