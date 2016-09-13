#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]){
	int testCases = 0;
	int n = 0;
	scanf("%d", &testCases);
	for(int i = 0; i < testCases; i++){
		scanf("%d", &n);
		int noOfOnes = 0;
		int *a = (int*) malloc(n * sizeof(int));
		int count = 0;
		int tmp = 0;
		for(int j = 0; j < n; j++){
			scanf("%d", &tmp);
			if (tmp == 1){
				noOfOnes++;
			}
			else{
				a[count++] = tmp;
			}
		}
		sort(a, a + count);
		while (noOfOnes--){
			printf("1 ");
		}
		if ((count == 2) && (a[0] == 2) && (a[1] == 3)){
			printf("2 3");
		}
		else {
			for(int v = count - 1; v >= 0; v--){
				printf("%d ", a[v]);
			}
		}
		puts("");
		free(a);
	}
	return 0;
}