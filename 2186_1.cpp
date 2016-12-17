#include <iostream>
#include <vector>
#include <cstdio>
#include <stdlib.h>
#include <stack>

using namespace std;

const int MAX_V = 10000;


int V;
vector<int> g[MAX_V];  // Graph. G[v] includes all vertexs after v.
vector<int> rg[MAX_V];
int noOfScc = 0;
int curScc = 0;
int curSize = 0;
int belong[MAX_V]; // v belongs to SCC number belong[v]
int *mark;
stack<int> s;
int sizeOfSCC[10000] = {0};

int solve();
int kosaraju();
int DFS(int v);
int DFSPhase2(int v);

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v; scanf("%d %d", &u, &v); u--; v--;
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
				out[belong[u]]++;
			}
		}
	}

	int noOfCmp = 0;
	int indexCmp = 0;

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
	
	// First Phase
	for(int v = 0; v < V; v++){
		if (!mark[v]){
			DFS(v);
			
		}
	}


	// Reverse Graph
	for(int v = 0; v < V; v++){
		for(int i = 0; i < g[v].size(); i++){
			rg[g[v][i]].push_back(v);
		}
	}

	// Second Phase
	for(int v = 0; v < V; v++){
		mark[v] = 0;
	}

	while (!s.empty()){
		int v = s.top();
		s.pop();
		if (!mark[v]){
			belong[v] = curScc;
			curSize = 0;
			DFSPhase2(v);
			sizeOfSCC[curScc] = curSize;
			curScc++;
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
	curSize++;
	return 0;
}