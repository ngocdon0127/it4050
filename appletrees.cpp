// https://apps.topcoder.com/forums//?module=ThreadList&forumID=541737
// https://apps.topcoder.com/forums//?module=Thread&threadID=694807&start=0

// 556.99
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h> 
#include <vector> 
#include <algorithm> 
using namespace std; 

typedef long long Int; 

#define MAX (2*41*41) 
#define MOD 1000000007 

int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); } 

long long Res[41][42][MAX] = {0}; 
int A[41]; 
int Z[41]; 

class AppleTrees { 
	public: 
	int theCount(int D, vector <int> v) 
	{ 
		sort(v.begin(), v.end()); 
		reverse(v.begin(), v.end()); 
		int N = v.size(); 

		Res[0][1][0] = 1; 

		int i, j, k; 
		for (i = 0; i < N; i++) 
			for (j = 1; j < i + 2; j++) 
				for (k = 0; k < MAX; k++) 
					if(Res[i][j][k] != 0) 
					{ 
						Res[i + 1][j - 1][k] += j * Res[i][j][k]; 
						// Res[i + 1][j - 1][k] %= MOD; 

						Res[i + 1][j][ k + v[i] ] += 2 * j * Res[i][j][k]; 
						// Res[i + 1][j][ k + v[i] ] %= MOD; 

						Res[i + 1][j + 1][ k + v[i] + v[i] ] += j * Res[i][j][k]; 
						// Res[i + 1][j + 1][ k + v[i] + v[i] ] %= MOD; 
					} 

		long long res = 0; 
		for(k = 0; k < MAX; k++) 
			if(Res[N][0][k] != 0) 
			{ 
				int d = D - 1 - k; 
				if(d < 0) 
					continue; 

				for(i = 0; i < N; i++) 
				{ 
					A[i] = d + i + 1; 
					Z[i] = i + 1; 
				} 

				for(i = 0; i < N; i++) 
					for(j = 0; j < N; j++) 
					{ 
						int g = gcd(Z[i], A[j]); 
						Z[i] /= g; 
						A[j] /= g; 

						if(Z[i] == 1) 
							break; 
					} 

				long long r = Res[N][0][k]; 
				for(i = 0; i < N; i++) 
				{ 
					r *= A[i]; 
					r %= MOD; 
				} 

				res += r; 
			} 

		return res % MOD; 
	} 

	 

}; 

int main(int argc, char const *argv[]){
	std::vector<int> v;
	AppleTrees appleTree = AppleTrees();
	int D = 58;
	int x[] = {5, 8};
	int size = 2;
	int n = 1;
	for(int i = 0; i < size; i++){
		v.push_back(x[i]);
	}
	printf("%d\n", appleTree.theCount(D, v));
	return 0;
}