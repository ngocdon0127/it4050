#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int n;
int a[MAX], b[MAX], dd[MAX]={0}, kc[MAX][MAX];
int time1=0, time2=0;
int min = 1000000, check=0;
int dis = 0;

int Try(int i);
int in(void);

int main(void){
	// FILE *f;
	int i, j;
	// f=fopen("Nguoi_Du_Lich.txt", "rt");
	// if (f==NULL){
	// 	printf("Khong the mo file Nguoi_Du_Lich.txt.");
	// 	getch();
	// 	return 0;
	// }
	// fscanf(f, "%i", &n);
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if ((i == 0) || (j == 0)){
				kc[i][j] = 0;
			}
			else{
				kc[i][j] = -1;
			}
		}
	}
	int c1, c2, price;
	for (int i = 0; i < m; ++i){
		scanf("%d%d%d", &c1, &c2, &price);
		kc[c1][c2] = price;
		kc[c2][c1] = price;
	}
	// for(i=0; i<=n; i++)
	// 	for(j=0; j<=n; j++)
	// 		fscanf(f, "%i", *(kc+i)+j);	
	// fclose(f);
	//time1=time(NULL);
	Try(1);
	//time2=time(NULL);
	// for(i=1; i<n+2; i++) printf("%i ", b[i]);
	// printf("\nkc=%i", min);
	printf("%d", min);
	//printf("\ntime=%i", time2-time1);
	return 0;
}

int Try(int i){
	int j;
	if (i>n) {
		in();
	}
	else{
		for(j=1; j<=n; j++){
			if ((dd[j]==0) && (kc[a[i]][a[i - 1]] != -1)) {
				a[i]=j;
				dis+=kc[a[i]][a[i-1]];
				//printf("dis=%i check1=%i\n", dis, check1);
				if (dis>=min) {
					dis-=kc[a[i]][a[i-1]];
					continue;
				}
				dd[j]=1;
				Try(i+1);
				dis-=kc[a[i]][a[i-1]];
				dd[j]=0;	//Tra de quy
			}
		}
	}
	return 0;
}

// int in(void){
// 	int i;
// 	int dis=0;
// 	a[n+1]=a[1];
// 	for(i=1; i<=n; i++) {
// 		if (kc[a[i]][a[i + 1]] == -1){
// 			return 0;
// 		}
// 		dis += kc[a[i]][a[i + 1]];
// 	}
// 	if ((check==0) || (min>dis)) {
// 		min = dis;
// 		// for(i=1; i<n+2; i++) b[i]=a[i];
// 	}
// 	check=1;
// 	return 0;
// }

int in(void){
	int i;
	/*dis=0;
	a[n+1]=a[1];
	for(i=1; i<n; i++) dis+=kc[a[i]][a[i+1]];*/
	if (kc[a[n]][a[1]] == -1){
		return 0;
	}
	dis+=kc[a[n]][a[1]];
	//if (kc[a[n]][a[1]] == 1000) printf("dis = %i a[n]= %i a[1] = %i kc = %i\n", dis, a[n], a[1], kc[a[n]][a[1]]);
	//printf("kc=%i\n", dis);
	//min=min>dis?dis:min;
	if (min > dis){
		min = dis;
		// for(i = 1; i <= n; i++)
		// 	b[i] = a[i];
		// b[n + 1] = a[1];
	}
	//dis=0;
	dis-=kc[a[n]][a[1]];
	return 0;
}