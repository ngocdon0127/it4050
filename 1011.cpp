/**
 * Đệ quy quay lui, sinh tất cả các xâu nhị phân độ dài n
 * Môi xâu nhị phân ứng với 1 cách chọn các đồ vật
 * Trong quá trình sinh, tính toán khối lượng các vật đã chọn,
 * nếu vượt quá b thì chặt đệ quy
 *
 * Độ phức tạp O(n * n) 
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Object Object;

struct Object{
	int weight;
	int value;
	float pp;
};

bool compare(const Object &ob1, const Object &ob2){
	return ob1.pp < ob2.pp;
}

int Try(int index);
int out(void);

int n = 0;
int b = 0;
Object a[50];
int cur_value = 0;
int cur_weight = 0;
int max_value = -1;

int main(int argc, char const *argv[]){
	scanf("%d%d", &n, &b);
	Object tmp;
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &(a[i].weight), &(a[i].value));
		a[i].pp = (float) a[i].value / a[i].weight;
		
	}

	Try(0);

	printf("%d", max_value);

	return 0;
}

int Try(int index){
	if (index >= n){
		out();
	}
	else {
		for (int i = 0; i < 2; ++i){
			if (i){
				if (cur_weight + a[index].weight <= b){
					cur_value += a[index].value;
					cur_weight += a[index].weight;
					Try(index + 1);
					cur_weight -= a[index].weight;
					cur_value -= a[index].value;
				}
			}
			else {
				Try(index + 1);
			}
		}
	}
}

int out(void){
	max_value = (max_value < cur_value) ? cur_value : max_value;
	return 0;
}