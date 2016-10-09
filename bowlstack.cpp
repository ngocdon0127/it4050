/**
 * Đệ quy quay lui, sinh tất cả các hoán vị của n cái cốc
 * Với 2 chiếc cốc a trên b dưới, xảy ra 3 trường hợp
 * + Cốc a có đáy lớn hơn cốc b => Cốc a đè lên miệng cốc b
 * + Cốc a có chiều cao thấp hơn cốc b và miệng nhỏ hơn cốc b => cốc a chui vào trong cốc b
 * + Còn lại, cốc a chui được 1 phần vào cốc b
 * Với mỗi hoán vị, tính tọa độ của đấy 1 cốc so với tất cả các cốc bên dưới nó rồi lấy giá trị lớn nhất
 * Cuối cùng lấy độ cao nhỏ nhất của tất cả các cốc.
 *
 * Độ phức tạp O(n!)
 */


#include <stdio.h>
#include <stdlib.h>

#define MAX 10

using namespace std;

typedef struct Pan Pan;

struct Pan
{
	float h;
	float r;
	float R;
	float y;
};

Pan pans[MAX];
Pan a[MAX];
int mark[MAX] = {0};
int n;
int minHeight = 0;

int process(void);
int Try(int index);
float lift(Pan p1, Pan p2);

int main(int argc, char const *argv[]){
	int testCases = 0;
	scanf("%d", &testCases);
	for (int i = 0; i < testCases; ++i){
		process();
	}
	return 0;
}

int process(void){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%f%f%f", &pans[i].h, &pans[i].r, &pans[i].R);
	}

	minHeight = 10000000;

	Try(0);
	printf("%d\n", minHeight);

}

int Try(int index){
	if (index >= n){
		int height = 0;
		for (int i = 0; i < n; ++i){
			int tmpHeight = a[i].y + a[i].h;
			(height < tmpHeight) ? (height = tmpHeight) : 1;
		}
		(minHeight > height) ? (minHeight = height) : 1;
	}
	else{
		for (int i = 0; i < n; ++i){
			if (!mark[i]){
				float tmpMaxY = 0;
				for (int j = 0; j < index; ++j){
					float tmpHeight = a[j].y + lift(a[j], pans[i]);
					(tmpMaxY < tmpHeight) ? (tmpMaxY = tmpHeight) : 1;
				}
				if(tmpMaxY + pans[i].h > minHeight) {
					continue;
				}
				a[index] = pans[i];
				a[index].y = tmpMaxY;
				mark[i] = 1;
				Try(index + 1);
				mark[i] = 0;
				// a[index].y = 0;
			}
		}
	}
}

float lift(Pan pan1,Pan pan2) {
		float lift;
		if ((pan1.R - pan1.r) / pan1.h > (pan2.R - pan2.r) / pan2.h){
			lift = pan1.h * (pan2.r - pan1.r) / (pan1.R - pan1.r); 
		}
		else if (pan2.R < pan1.R){
			lift = pan1.h * (pan2.R - pan1.r) / (pan1.R - pan1.r) - pan2.h; 
		}
		else {
			lift = pan1.h - pan2.h * (pan1.R - pan2.r) / (pan2.R - pan2.r);
		}
		if (lift < 0) {
			// puts("<");
			return 0.0;
		}
		if (lift > pan1.h) {
			// puts(">");
			return pan1.h;
		}
		return lift;
	}