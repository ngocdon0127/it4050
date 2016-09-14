#include <stdio.h>
#include <stdlib.h>

int n = 0;
int arr[100010];
int *mark = NULL;
int flag = 1;
int offset = 0;
int done = 0;

int init(void);
int nextIndex(void);
int process(void);
int processOddPhrase(int index);
int processEvenPhrase(int index);

int main(int argc, char const *argv[]){
	init();
	// printf("\n---\n");
	// for (int i = 1; i <= n; ++i){
	// 	printf("%d ", arr[i]);
	// }
	// printf("\n---\n");
	process();
	free(mark);
	return 0;
}

int init(void){
	scanf("%d", &n);
	mark = (int*) calloc(n + 1, sizeof(int));
	mark[0] = 1;
	int tmp = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &tmp);
		// a[i + 1] = tmp;
		arr[tmp] = i + 1;
	}
	return 0;
}

int nextIndex(void){
	int index = 0;
	if (flag){
		flag = 0;
		index = 1 + offset;
	}
	else {
		flag = 1;
		index = n - offset;
		offset++;
	}
	return index;
}

int process(void){
	while (done < n){
		int index = nextIndex();
		// printf("Processing %d\n", index);
		if (flag % 2 == 0){
			// Flag is even => We are in odd Phrase
			processOddPhrase(index);
		}
		else {
			processEvenPhrase(index);
		}
		// printf("\n---\n");
		// for (int i = 1; i <= n; ++i){
		// 	printf("%d ", arr[i]);
		// }
		// printf("\n---\n");
		done++;
	}
}

int processOddPhrase(int index){
	int position = arr[index];
	printf("%d\n", position - index);
	arr[index] = index;
	mark[index] = 1;
	// for(int i = 1; i < position; i++){
	// 	if (!mark[i]){
	// 		arr[i]++;
	// 	}
	// }
	int start = index + 1;
	int finish = n - index + 1;
	for(int i = start; i <= finish; i++){
		if (!mark[i] && (arr[i] < position)){
			arr[i]++;
		}
	}
	return 0;
}

int processEvenPhrase(int index){
	int position = arr[index];
	printf("%d\n", index - position);
	arr[index] = index;
	mark[index] = 1;
	// for(int i = position + 1; i <= n; i++){
	// 	if (!mark[i]){
	// 		arr[i]--;
	// 	}
	// }
	int finish = index - 1;
	int start = n - index + 2;
	for(int i = start; i <= finish; i++){
		if (!mark[i] && (arr[i] > position)){
			arr[i]--;
		}
	}
	return 0;
}