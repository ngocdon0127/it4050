#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <map>

using namespace std;
 
string child;
queue <string> q;
map <string, bool> mark;
int count;

int N = 23;
 
bool generateState (string s){
	string t = s;
	bool haveChild = false;

	for (int i = 0; i < N - 1; i++ ) {
		if (s.at (i) == 'o' && s.at (i + 1) == 'o' ) {
			if ( i + 2 < N && s.at (i + 2) == '-' ) {
				s.at(i + 2) = 'o';
				s.at(i) = s.at (i + 1) = '-';
				if (!mark [s]) {
					mark [s] = true;
					q.push (s);
				}
				haveChild = true;
				s = t;
			}
			if ( i - 1 >= 0 && s.at (i - 1) == '-' ) {
				s.at (i - 1) = 'o';
				s.at (i) = s.at (i + 1) = '-';
				if ( !mark [s] ) {
					mark [s] = true;
					q.push (s);
				}
				haveChild = true;
				s = t;
			}
		}
	}

	// for (int i = 0; i < N - 2; ++i){
	// 	if ((s.at(i) == 'o') && (s.at(i + 1) == 'o')) {
	// 		if ((i + 2 < N) && (s.at(i + 2) == '-')) {
	// 			s.at(i) = '-';
	// 			s.at(i + 1) = '-';
	// 			s.at(i + 2) = 'o';
	// 			if (!mark[s]){
	// 				mark[s] = true;
	// 				q.push(s);
					
	// 			}
	// 			haveChild = true;
	// 			s = t; // recovery s
	// 		}
	// 		if ((i > 0) && (s.at(i - 1) == '-')){
	// 			s.at(i) = '-';
	// 			s.at(i + 1) = '-';
	// 			s.at(i - 1) = 'o';
	// 			if (!mark[s]){
	// 				mark[s] = true;
	// 				q.push(s);
					
	// 			}
	// 			haveChild = true;
	// 			s = t; // recovery s
	// 		}
	// 	}
	// }

	return haveChild;
}
 
int countPebbles (string p)
{
	int c = 0;
 
	for (int i = 0; i < p.size (); i++ ) {
		if (p.at (i) == 'o' )
			c++;
	}
 
	return c;
}
int main (){
	int testCase;
	scanf ("%d", &testCase);

	while (testCase--) {
		string input;
		cin >> input;


		count = 100;
		q.push(input);
		mark[input] = true;

		while (!q.empty()) {
			string s = q.front();
			q.pop();

			if (!generateState(s)) {
				int t = countPebbles(s);
				if (t < count){
					count = t;
				}
			}
		}

		printf ("%d\n", count);

	}
	return 0;
}

