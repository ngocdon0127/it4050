#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
//#include <windows.h>
#include <math.h>
//#include "Timer.cpp"

struct Point{
	int x, y;
};

char fname[] = "test10.in";



bool checkPoint(Point *a, int count, int x, int y){
	if (count == 0) return 0;
	for(int i = 0; i< count; i++){
		if (a[i].x == x && a[i].y == y) return 1;
	}
	return 0;
}

void generatePoint(Point a[], int n, int size){	
	FILE *f;
	f = fopen(fname, "a");
	if (f == NULL)
	{
		printf("Khong mo duoc file\n");
		exit(1);
	}
	fprintf(f, "%d %d\n", size, n);
	int count = 0;
	int x; int y;
	x = rand() % size;
	y = rand() % size;	
	for(int i = 0; i < n; i++){
		while(checkPoint(a,i,x,y)){
			x = rand() % size;
			y = rand() % size;
		}
		a[i].x = x;
		a[i].y = y;
		fprintf(f, "%d %d\n", x, y);
	}
	fclose(f);
}


int main(){

		Point *a;
		srand(time(NULL));
		int testCases = rand() % 1000;
		while (testCases--){
			int size = rand() % 4 + 8;
			int n = rand() % size;
			a = (Point*) malloc(n*sizeof(Point));
			generatePoint(a, n, size);
		}
		free(a);
		FILE *f;
		f = fopen(fname, "a");
		fprintf(f, "0 0");
		fclose(f);
//		Sleep(2000);
	return 0;
}

