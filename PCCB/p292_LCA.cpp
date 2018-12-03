/*
 * 根付き木の2頂点のLCAを二分探索で求める
 * 各頂点vに対し、その親の情報から2回親を辿って到達する頂点parent2[v] = parent[parent[v]]が計算でき、
 * 同様に4回、8回、...、2^k回親を辿ったときに到達する頂点parent[k][v]を計算できる
 * k = floor(logn)まで計算すれば二分探索が可能となり、1回の計算量はO(logn)で、初期化がO(nlogn)でできる
 */
#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 100;
vector<int> G[MAX_V];	// グラフの隣接リスト表現
int root;				// 根ノードの番号
int parent[(int)log(MAX_V)][MAX_V];		// parent[k][i]: iの親を2^k回辿って到達する頂点 (根を通り過ぎる場合は-1)
int depth[MAX_V];		// 根からの深さ

void LCAdfs(int v, int p, int d) {
	parent[0][v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); ++i) {
		if (G[v][i] != p) LCAdfs(G[v][i], v, d + 1);
	}
}

// LCAの初期化
void LCAinit(int V) {
	// parent[0](真上の親)とdepthを初期化する
	LCAdfs(root, -1, 0);
	// parent[k](k>=1)を初期化する
	for (int k = 0; k+1 < log(MAX_V); ++k) {
		for (int v = 0; v < V; ++v) {
			if (parent[k][v] < 0) parent[k+1][v] = -1;
			else parent[k+1][v] = parent[k][parent[k][v]];
		}
	}
}

// 2頂点のLCAを求める
int LCA(int u, int v) {
	// uとvの深さが同じになるまで親を辿る
	if (depth[u] > depth[v]) swap(u, v);
	for (int k = 0; k < log(MAX_V); ++k) {
		if ((depth[v] - depth[u])>>k & 1) {
			v = parent[k][v];
		}
	}
	if (u == v) return u;
	
	// 二分探索でLCAを求める
	for (int k = (int)log(MAX_V)+1; k >= 0; --k) {
		if (parent[k][u] != parent[k][v]) {
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}