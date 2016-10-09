#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	int count = 0;
	for (int i = 1; i < 10; ++i){
		for (int i1 = 0; i1 < 10; ++i1){
			for (int i2 = 0; i2 < 10; ++i2){
				for (int i3 = 0; i3 < 10; ++i3){
					for (int i4 = 0; i4 < 10; ++i4){
						int num1 = i * 10000 + 5090 + i1 * 100 + i2;
						int num2 = 30570 + i3 * 1000 + i4;
						count++;
						if (num1 - num2 == 9057){
							printf("%d %d\n", num1, num2);
						}
					}
				}
			}
		}
	}
	printf("count = %d\n", count);
	return 0;
}