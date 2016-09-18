#include <stdio.h>
#include <stdlib.h>

int testCases = 0;
int n = 0;
int *heights = NULL;
int *tallers = NULL;

int process();
int order(int *heights, int *tallers, int index, int count);

int main(int argc, char const *argv[]){
	scanf("%d", &testCases);
	for(int i = 0; i < testCases; i++){
		process();
	}
	return 0;
}

int process(){
	scanf("%d", &n);
	heights = (int*) malloc(n * sizeof(int));
	tallers = (int*) malloc(n * sizeof(int));
	for(int i = 0; i < n; i++){
		scanf("%d", heights + i);
	}

	for(int i = 0; i < n; i++){
		scanf("%d", tallers + i);
	}

	for (int i = 0; i < n; ++i){
		order(heights, tallers, i, n);
	}

	for (int i = 0; i < n; ++i){
		printf("%d ", heights[i]);
	}
	free(heights);
	free(tallers);
	printf("\n");
}

int order(int *heights, int *tallers, int index, int count){
	int minIndex = 0;
	for (int i = index; i < count; ++i){
		if (!tallers[i]){
			minIndex = i;
			break;
		}
	}

	for(int i = index + 1; i < count; i++){
		if (!tallers[i] && (heights[i] < heights[minIndex])){
			minIndex = i;
		}
	}

	int tmp = heights[minIndex];
	heights[minIndex] = heights[index];
	heights[index] = tmp;

	tmp = tallers[minIndex];
	tallers[minIndex] = tallers[index];
	tallers[index] = tallers[minIndex];

	for(int i = index; i < count; i++){
		if (heights[i] < heights[index]){
			tallers[i]--;
		}
	}
}
