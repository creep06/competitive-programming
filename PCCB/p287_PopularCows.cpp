#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define MAX_V 1000000

int v, e, a, b, r;
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

int main() {
	cin >> v >> e;
	rep(i,e) {
		cin >> a >> b;
		a--, b--;
		add_edge(a,b);
	}
	// 強連結成分の個数
	int k = scc();
	// 求めるものはこのグラフで全頂点から到達可能な頂点の個数
	// 2頂点a,bがそれに当たるとすると、aからbに到達できてbからaにも到達できる
	// つまりa,bは同じ強連結成分に属している ゆえに求めるものは特定の強連結成分の集合
	// それはは強連結成分分解後のトポロジカル順序の最後の集合になる(全頂点から辿り着ける集合はそれだけ)
	// ただグラフで浮いてる点がある可能性もあるので、本当に全ての点から辿り着けるか確認は必要
	// 辿り着けない点が合った場合当然条件を満たす頂点は1つも存在しない
	int u = 0, num = 0;
	for (int i = 0; i < v; ++i) {
		if (cmp[v]==k-1) u = v, num++;
	}
	memset(used, 0, sizeof(used));
	rdfs(u, 0);
	for (int i = 0; i < v; ++i) {
		if (!used[i]) {
			num = 0;
			break;
		}
	}
	cout << num << endl;
}