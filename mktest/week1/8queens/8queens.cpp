/**
 * Author : ngocdon0127
 * Date   : 2016-09-01 22 : 21 : 00
 *
 * Ý nghĩa các biến:
 * Mảng rows: rows[i] = x nghĩa là hàng i có x quân hậu
 * Mảng cols: cols[i] = x nghĩa là cột  i có x quân hậu
 * Mảng diagons1 và mảng diagons2 có ý nghĩa tương tự.
 * diagons1: mảng ứng với các đường chéo có tổng i + j cố định
 * diagons2: mảng ứng với các đường chéo có hiệu i - j cố định
 *
 * Với mỗi vị trí [i][j] có dấu *,
 * tăng các giá trị rows[i], cols[j], diagons1[i + j], diagons2[i - j + 8] lên 1 đơn vị.
 * (i - j + 8) tránh lỗi index out of range
 * 
 * Đọc input, nếu số hậu khác 8 thì in ra "invalid"
 * Kiểm tra các phần tử của 4 mảng đánh dấu, nếu có 1 phần tử có giá trị từ 2 trở lên thì in ra "invalid"
 * Còn lại là các trường hợp "valid".
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

int rows[8] = {0};
int cols[8] = {0};
int diagons1[16] = {0};
int diagons2[16] = {0};
int count = 0;

int readData();

int main(int argc, char const *argv[]){
	readData();
	if (count != 8){
		cout << "invalid";
		return 0;
	}

	for (int i = 0; i < 8; ++i){
		if ((rows[i] > 1) || (cols[i] > 1)){
			cout << "invalid";
			return 0;
		}
	}

	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if ((diagons1[i + j] > 1) || (diagons2[i - j + 8] > 1)) {
				cout << "invalid";
				return 0;
			}
		}
	}
	cout << "valid";
	return 0;
}

int readData(){
	char ch;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cin >> ch;
			if (ch == '*'){
				rows[i]++;
				cols[j]++;
				diagons1[i + j]++;
				diagons2[i - j + 8]++;
				count++;
			}
			else if (ch == '.'){

			}
			else {
				cout << "invalid";
				exit(0);
			}
		}
	}
	return 0;
}
