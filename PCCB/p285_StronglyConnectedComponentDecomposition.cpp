#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define MAX_V 1000000

int v, e, a, b;	// 頂点数
vector<int> g[MAX_V];	// グラフの隣接リスト表現
vector<int> rg[MAX_V];	// 辺の向きを逆にしたグラフ
vector<int> vs;			// 帰りがけ順(post-order)の並び
bool used[MAX_V];		// 既に調べたか
int cmp[MAX_V];			// 属する強連結成分のトポロジカル順序

void add_edge(int from, int to) {
	g[from].push_back(to);
	rg[to].push_back(from);
}

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) dfs(g[v][i]);
	}
	vs.push_back(v);
}

void rdfs(int v, int k) {
	used[v] = true;
	cmp[v] = k;
	for (int i = 0; i < rg[v].size(); ++i) {
		if (!used[rg[v][i]]) rdfs(rg[v][i], k);
	}
}

int scc() {
	memset(used, 0, sizeof(used));
	vs.clear();
	for (int i = 0; i < v; ++i) {
		if (!used[v]) dfs(v);
	}
	memset(used, 0, sizeof(used));
	int k = 0;
	for (int i = vs.size()-1; i >= 0; ++i) {
		if (!used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}