// 556.99
#include <iostream> 
#include <sstream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cctype> 
#include <string> 
#include <vector> 
#include <list> 
#include <algorithm> 
using namespace std; 

typedef long long Int; 
typedef pair<int,int> PII; 
typedef vector<int> VInt; 

#define FOR(i, a, b) for(i = (a); i < (b); ++i) 
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i) 
#define SIZE(a) int((a).size()) 
#define ALL(a) (a).begin(),(a).end() 
#define PB push_back 
#define MP make_pair 

#define MAX (2*41*41) 
#define MOD 1000000007 

int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); } 

Int Res[41][42][MAX] = {0}; 
int A[41]; 
int Z[41]; 

class AppleTrees { 
  public: 
  int theCount(int D, vector <int> v) 
  { 
    sort(ALL(v)); 
    reverse(ALL(v)); 
    int N = SIZE(v); 

    Res[0][1][0] = 1; 

    int i, j, k; 
    FOR(i, 0, N) 
      FOR(j, 1, i + 2) 
        FOR(k, 0, MAX) 
          if(Res[i][j][k] != 0) 
          { 
            Res[i + 1][j - 1][k] += j*Res[i][j][k]; 
            Res[i + 1][j - 1][k] %= MOD; 

            Res[i + 1][j][ k + v[i] ] += 2*j*Res[i][j][k]; 
            Res[i + 1][j][ k + v[i] ] %= MOD; 

            Res[i + 1][j + 1][ k + v[i] + v[i] ] += j*Res[i][j][k]; 
            Res[i + 1][j + 1][ k + v[i] + v[i] ] %= MOD; 
          } 

    Int res = 0; 
    FOR(k, 0, MAX) 
      if(Res[N][0][k] != 0) 
      { 
        int d = D - 1 - k; 
        if(d < 0) 
          continue; 

        FOR(i, 0, N) 
        { 
          A[i] = d + i + 1; 
          Z[i] = i + 1; 
        } 

        FOR(i, 0, N) 
          FOR(j, 0, N) 
          { 
            int g = gcd(Z[i], A[j]); 
            Z[i] /= g; 
            A[j] /= g; 

            if(Z[i] == 1) 
              break; 
          } 

        Int r = Res[N][0][k]; 
        FOR(i, 0, N) 
        { 
          r *= A[i]; 
          r %= MOD; 
        } 

        res += r; 
      } 

    return res % MOD; 
  } 

   

}; 
