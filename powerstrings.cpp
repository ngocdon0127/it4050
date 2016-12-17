/**
 * Tạo xâu temp = s + s
 * Bỏ ký tự đầu tiên trong xâu temp
 * strstr(temp, s) - temp chính là số ký tự của a trừ đi 1, với s = a ^ n
 *
 * Độ phức tạp thuật toán O(n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define M 2000010
using namespace std;

int main() {
    
    char* s = new char[M];
    char* temp = new char[M * 2];
    
    while (cin >> s && s[0] != '.') {
        int n = strlen(s);
        
        strcpy(temp, s + 1);
        strcpy(temp + n - 1, s);
        
        int p = strstr(temp, s) - temp;
        
        cout << n / (p + 1) << "\n";    
    }

    return 0;
}