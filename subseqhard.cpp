#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef long long int mytype;

int arr[1000010];

int process(void);

int main(int argc, char const *argv[]){
	int testCases = 0;
	scanf("%d", &testCases);
	for (int i = 0; i < testCases; ++i){
		process();
	}
	return 0;
}

int process(void){
	int n = 0;
	scanf("%d", &n);
	mytype *sum = (mytype*) malloc(n * sizeof(mytype));
	sum[0] = 0;
	mytype tmp = 0;
	scanf("%lld", &tmp);
	arr[0] = tmp;
	sum[0] = tmp;
	for (int i = 1; i < n; ++i){
		scanf("%lld", &tmp);
		arr[i] = tmp;
		sum[i] = sum[i - 1] + tmp;
	}
	// printf("\narr:\n");
	// for (int i = 0; i < n; ++i){
	// 	printf("%d ", arr[i]);
	// }
	// printf("\nsum:\n");
	// for (int i = 0; i < n; ++i){
	// 	printf("%lld ", sum[i]);
	// }
	int count = 0;
	for (int i = 0; i < n - 1; ++i){
		for (int j = i + 1; j < n; ++j){
			if (sum[j] - sum[i] == 47){
				count++;
			}
		}
	}
	printf("%d\n", count);
	free(sum);
}