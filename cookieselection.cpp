#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <algorithm>

#define MAX 1000000

typedef struct Node Node;

struct Node{
	int val;
	Node* next;
};

using namespace std;

int a[MAX] = {0};
int tmp[MAX];
// list<int> a;

// Node *a = NULL;

int len = 0;
int pendingLen = 0;
int needSort = 0;
int needSend = 0;
double totalTimeSort = 0;
double totalTimeSend = 0;

int merge(int*, int, int, int);
int mergeSort(int*, int, int);
int swap(int*, int, int);
int arrive(int d);
int send(int count);
int printList(Node *root);

int main(void){
	char buff[100];
	gets(buff);
	while (strlen(buff)){
		// puts(buff);
		if (strcmp(buff, "#") == 0){
			if (pendingLen > 0){
				// sort(a, a + len);
				// Timer ti;
				mergeSort(tmp, 0, pendingLen - 1);
				for (int i = 0; i < pendingLen; ++i){
					a[len + i] = tmp[i];
				}
				// mergeSort(a, 0, len - 1);
				merge(a, 0, len - 1, len + pendingLen - 1);
				len += pendingLen;
				// totalTimeSort += ti.getElapsedTime();
				// printf("sort: %.5f\nsend %.5f\n", totalTimeSort, totalTimeSend);
			}
			pendingLen = 0;
			// send(1);
			needSend++;
			needSort = 0;
		}
		else{
			if (needSend > 0){
				// Timer ti;
				send(needSend);
				// totalTimeSend += ti.getElapsedTime();
				// printf("sort: %.5f\nsend %.5f\n", totalTimeSort, totalTimeSend);
				needSend = 0;
			}
			arrive(atoi(buff));
			needSort = 1;
		}
		buff[0] = 0;
		gets(buff);
		// printf("needSort needSend %d %d\n", needSort, needSend);
	}
	if (pendingLen > 0){
		// Timer ti;
		mergeSort(tmp, 0, pendingLen - 1);
		for (int i = 0; i < pendingLen; ++i){
			a[len + i] = tmp[i];
		}
		// mergeSort(a, 0, len - 1);
		merge(a, 0, len - 1, len + pendingLen - 1);
		len += pendingLen;
		pendingLen = 0;
		// totalTimeSort += ti.getElapsedTime();
		// printf("sort: %.5f\nsend %.5f\n", totalTimeSort, totalTimeSend);
	}
	if (needSend){
		// Timer ti;
		send(needSend);
		// totalTimeSend += ti.getElapsedTime();
		// printf("sort: %.5f\nsend %.5f\n", totalTimeSort, totalTimeSend);
	}
	// printf("sort: %.5f\nsend %.5f\n", totalTimeSort, totalTimeSend);
	return 0;
}

int arrive(int d){

	// a[len++] = d;
	tmp[pendingLen++] = d;
	// printf("\n----- Mang ---\n");
	// for (int i = 0; i < len; ++i){
	// 	printf("%d ", a[i]);
	// }
	// printf("\n--------------\n");
	// printf("d = %d\n", d);
	// if (!len){
	// 	// a = new Node;
	// 	// a->val = d;
	// 	// a->next = NULL;
	// 	// len++;
	// 	// return 0;
	// 	// ---
	// 	// printf("len = %d\n", len);
	// 	return a[len++] = d;

	// }

	// Node *left = a;
	// Node *left_ = a;
	// while ((left != NULL) && (left->val < d)){
	// 	left_ = left;
	// 	left = left->next;
	// }
	// Node *p = new Node;
	// p->val = d;
	// p->next = left;
	// left_->next = p;
	// len++;

	// ---

	// if (d <= a[0]){
	// 	for (int i = len; i > 0; --i){
	// 		a[i] = a[i - 1];
	// 	}
	// 	len++;
	// 	// printf("len = %d\n", len);
	// 	return a[0] = d;
	// }
	// else if (d >= a[len - 1]){
	// 	// printf("len = %d\n", len);
	// 	return a[len++] = d;
	// }

	// int left = 0;
	// int right = len - 1;
	// int position = -1;
	// while (left < right){
	// 	int mid = (left + right) / 2;
	// 	// printf("left mid right: %d %d %d\n", left, mid, right);
	// 	if ((a[mid] <= d) && (d <= a[mid + 1])){
	// 		position = mid + 1;
	// 		break;
	// 	}
	// 	else {
	// 		if ((a[left] <= d) && (a[left + 1] >= d)){
	// 			position = left + 1;
	// 			break;
	// 		}
	// 		else if ((a[right] >= d) && (a[right - 1] <= d)){
	// 			position = right;
	// 			break;
	// 		}
	// 		else if (a[mid] > d){
	// 			right = mid;
	// 		}
	// 		else {
	// 			left = mid;
	// 		}
	// 	}
	// }

	// if (position == -1){
	// 	return puts("dmm");
	// }
	// for(int i = len; i > position; i--){
	// 	a[i] = a[i - 1];
	// }
	// len++;
	// a[position] = d;
	// printf("len = %d\n", len);

	// printList(a);

}

int send(int count){
	if (count < 1){
		return 0;
	}
	// printf("\n----- Mang ---\n");
	// for (int i = 0; i < len; ++i){
	// 	printf("%d ", a[i]);
	// }
	// printf("\n--------------\n");
	int index = 0;
	if (len % 2 == 1){
		index = (len - 1) / 2;
	}
	else{
		index = len / 2;
	}
	// Node *node = a;
	// Node *node_ = a;
	// for(int i = 0; i < index; i++){
	// 	node_ = node;
	// 	node = node->next;
	// }
	// // puts("reach");
	// printf("%d\n", node->val);

	// node_->next = node->next;
	// if (next_){
	// 	node->next = node->next->next;
	// }
	// free(next_);
	// printf("len = %d a[%d] = %d\n", len, index, a[index]);
	printf("%d\n", a[index]);
	count--;
	int sign = 1;
	int base = 0;
	if (len % 2){
		sign = -1;
		base = 0;
	}
	for (int i = 0; i < count; ++i){
		if (sign == 1){
			if (len % 2){
				sign = -1;
				// base++;
			}
			else {
				sign = -1;
				base++;
			}
		}
		else {
			if (len % 2){
				sign = 1;
				base++;
			}
			else {
				sign = 1;
				// base++;
			}
		}
		// printf("len = %d a[%d] = %d\n", len, index + (base * sign), a[index + (base * sign)]);
		printf("%d\n", a[index + (base * sign)]);
	}
	index = (sign == 1) ? ((len % 2) ? (index - (base - 1) * sign) : (index - base * sign)) : (index + base * sign);
	
	for(int i = index; i < len - count - 1; i++){
		a[i] = a[i + count + 1];
	}
	len -= count + 1;
}

int mergeSort(int *a, int left, int right){
	if (left < right){
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
	return 0;
}

int merge(int *a, int left, int mid, int right){
	int count = right - left + 1;
	int *tmp = (int*) calloc(count, sizeof(int));
	int i = left;
	int j = mid + 1;
	int k;

	for(k = 0; k < count; k++){
		if (i > mid){
			tmp[k] = a[j];
			j++;
		}
		else if (j > right){
			tmp[k] = a[i];
			i++;
		}
		else if (a[i] < a[j]){
			tmp[k] = a[i];
			i++;
		}
		else{
			tmp[k] = a[j];
			j++;
		}
	}
	for(k = 0; k < count; k++)
		a[left + k] = tmp[k];
	free(tmp);
}

int swap(int *a, int i, int j){
	int tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
	return 0;
}

int printList(Node *root){
	printf("List: ");
	while (root){
		printf("%d ", root->val);
		root = root->next;
	}
}
