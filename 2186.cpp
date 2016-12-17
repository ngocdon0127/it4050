#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int MAX_V = 10000;
const int INF = 0x3f3f3f3f;
int V;
vector<int> g[MAX_V];  // Graph. G[v] includes all vertexs after v.

int dfn_idx = 0;
int scc_cnt = 0;
int dfn[MAX_V];
int low[MAX_V];
int belong[MAX_V]; // v belongs to SCC number belong[v]
bool in_st[MAX_V];
vector<int> st;

void scc(int v) {
    dfn[v] = low[v] = dfn_idx++;
    st.push_back(v);
    in_st[v] = true;

    for (size_t i = 0; i < g[v].size(); i++) {
        const int u = g[v][i];
        if (dfn[u] == -1) {
            scc(u);
            low[v] = min(low[v], low[u]);
        }
        else if (in_st[u]) {
            low[v] = min(low[v], dfn[u]);
        }
    }

    if (dfn[v] == low[v]) {
        int k;
        do {
            k = st.back(); st.pop_back();
            in_st[k] = false;
            belong[k] = scc_cnt;
        } while (k != v);
        scc_cnt++;
    }
}

void tarjan() {
    st.clear();
    fill(dfn, dfn + V, -1);
    fill(low, low + V, INF);
    dfn_idx = 0;
    scc_cnt = 0;
    for (int v = 0; v < V; v++) {
        if (dfn[v] == -1) {
            scc(v);
        }
    }
}

int solve() {
    tarjan();

    vector<int> out(scc_cnt, 0); // Bridge
    // After this loop, SCC i has out[i] bridges
    for (int v = 0; v < V; v++) {
        for (size_t i = 0; i < g[v].size(); i++) {
            int u = g[v][i];
            if (belong[v] != belong[u]) {
                out[belong[v]]++;
            }
        }
    }



    // find the target component
    int comp_idx = -1, comp_cnt = 0;
    for (int c = 0; c < scc_cnt; c++) {
        if (out[c] == 0) {
            comp_idx = c;
            comp_cnt++;
        }
    }

    // target component is the component which has 0 bridge

    if (comp_cnt != 1) {
        return 0;
    }

    int ans = 0;
    for (int v = 0; v < V; v++) {
        if (belong[v] == comp_idx) {
            ans++;
        }
    }
    return ans;
}

int main() {
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