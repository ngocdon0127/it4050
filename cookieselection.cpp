#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <list>

#define MAX 600000

typedef struct Node Node;

struct Node{
	int val;
	Node* next;
};

using namespace std;

// int a[MAX];
// list<int> a;

Node *a = NULL;

int len = 0;

int merge(int*, int, int, int);
int mergeSort(int*, int, int);
int swap(int*, int, int);
int arrive(int d);
int send(void);
int printList(Node *root);

int main(void){
	char buff[100];
	gets(buff);
	while (strlen(buff)){
		if (strcmp(buff, "#") == 0){
			send();
		}
		else{
			arrive(atoi(buff));
		}
		buff[0] = 0;
		gets(buff);
	}
	return 0;
}

int arrive(int d){
	if (!len){
		a = new Node;
		a->val = d;
		a->next = NULL;
		len++;
		return 0;
	}

	Node *left = a;
	Node *left_ = a;
	while ((left != NULL) && (left->val < d)){
		left_ = left;
		left = left->next;
	}
	Node *p = new Node;
	p->val = d;
	p->next = left;
	left_->next = p;
	len++;

	// printList(a);

}

int send(){
	int index = 0;
	if (len % 2 == 1){
		index = (len - 1) / 2;
	}
	else{
		index = len / 2;
	}
	Node *node = a;
	Node *node_ = a;
	for(int i = 0; i < index; i++){
		node_ = node;
		node = node->next;
	}
	// puts("reach");
	printf("%d\n", node->val);

	node_->next = node->next;
	// if (next_){
	// 	node->next = node->next->next;
	// }
	// free(next_);
	len--;
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
