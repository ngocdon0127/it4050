#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <vector>

using namespace std;

const int MAX_V = 10000;


int V;
vector<int> g[MAX_V];       // Graph. G[v] bao gồm tất cả các đỉnh có thể đi trực tiếp từ v bằng 1 cạnh
vector<int> rg[MAX_V];
int belong[MAX_V];          // belong[v] là số thứ tự của SCC mà v thuộc vào
int *mark;
stack<int> s;
int sizeOfSCC[10000] = {0}; // Lưu trữ số lượng phần tử của các SCC

int noOfScc = 0;
int curScc = 0;
int curSize = 0;

int solve();
int kosaraju();
int DFS(int v);
int DFSPhase2(int v);

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v; 
		scanf("%d %d", &u, &v); 
		u--; v--;		// 0-based index
		g[u].push_back(v);
	}

	V = N;
	printf("%d\n", solve());
	return 0;
}

int solve(){
	kosaraju();

	vector<int> out(noOfScc, 0);

	for(int u = 0; u < V; u++){
		for(int j = 0; j < g[u].size(); j++){
			int v = g[u][j];
			if (belong[u] != belong[v]){
				out[belong[u]]++; 				// Đánh dấu số cầu ra của SCC có số thứ tự belong[u]
			}
		}
	}

	int noOfCmp = 0; 							// Số lượng SCC có cầu ra bằng 0
	int indexCmp = 0; 							// Chỉ số của 1 trong các SCC đó

	for(int i = 0; i < noOfScc; i++){
		if (out[i] == 0){
			indexCmp = i;
			noOfCmp++;
		}
	}

	if (noOfCmp != 1){
		return 0;
	}

	return sizeOfSCC[indexCmp];
}

int kosaraju(){
	mark = (int*) calloc(sizeof(int), V);
	
	// Phase 1
	for(int v = 0; v < V; v++){
		if (!mark[v]){
			DFS(v);
		}
	}


	// Đồ thị chuyển vị
	for(int v = 0; v < V; v++){
		for(int i = 0; i < g[v].size(); i++){
			rg[g[v][i]].push_back(v);
		}
	}

	// Phase 2
	for(int v = 0; v < V; v++){
		mark[v] = 0;
	}

	while (!s.empty()){
		int v = s.top();
		s.pop();
		if (!mark[v]){
			belong[v] = curScc;          // Đánh dấu v thuộc về SCC hiện tại
			curSize = 0; 
			DFSPhase2(v);
			sizeOfSCC[curScc] = curSize; // Lưu lại số lượng phần tử
			curScc++;                    // Thêm 1 phần tử vào SCC hiện tại
		}
	}
	noOfScc = curScc;
	
	return 0;
}

int DFS(int v){
	mark[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		if (!mark[g[v][i]]){
			DFS(g[v][i]);
		}

	}
	s.push(v);
	return 0;
}

int DFSPhase2(int v){
	mark[v] = 1;
	for(int i = 0; i < rg[v].size(); i++){
		if (!mark[rg[v][i]]){
			DFSPhase2(rg[v][i]);
		}
	}
	belong[v] = curScc;
	curSize++;							// Cập nhật số lượng đỉnh của SCC hiện tại
	return 0;
}