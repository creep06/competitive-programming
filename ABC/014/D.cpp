#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rept(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
#define repst(i,s,n) for(int (i)=(s);(i)<=(int)(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define each(itr,v) for(auto (itr):(v))
#define all(c) c.begin(),c.end()
#define pb push_back
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln << "\n"
#define show(x) cout << #x << " = " << x ln
#define dbg(x) cout<<#x"="<<x ln

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

// ⊂ニニニニニニニニニニニ(^ω^ )ニニニニニニニニニニニ⊃
//　　　　　　　　　　　　　　　　おっ
// 　　　　　　⊂ニニニニニニニニニニニ( ^ω^)ニニニニニニニニニニニ⊃

int n, mid, y, q, a, b;
vector<vi> G(100000);	// グラフの隣接リスト表現
int root = 0;	// 根ノード
int parent[20][100000];	// parent[k][i]: iの親を2^k回辿って到達する頂点 (根を通り過ぎる場合は-1)
int depth[100000];	// 根からの深さ

// 一度rootからdfsでグラフを一周して各頂点の親と深さを調べる
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
	for (int k = 0; k+1 < 20; ++k) {
		for (int v = 0; v < V; ++v) {
			// vを2^k回辿るとグラフをはみ出しちゃう場合は2^k+1回もはみ出す
			if (parent[k][v] < 0) parent[k+1][v] = -1;
			else parent[k+1][v] = parent[k][parent[k][v]];
		}
	}
}

// 2頂点のLCAを求める
int LCA(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);
	// vと同じ高さになるまでuから親を辿る
	for (int k = 0; k < log2(n); ++k) {
		if ((depth[v] - depth[u])>>k & 1) {
			v = parent[k][v];
		}
	}
	if (u == v) return u;
	
	// 二分探索でLCAを求める
	for (int k = 18; k >= 0; --k) {
		if (parent[k][u]>=0 && parent[k][u]!=parent[k][v]) {
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	// 辺(a,b)を追加して出来る閉路の長さ -> 元々のa-b間の最短距離+1
	// a,b間の距離は、a,bのLCAをダブリングテーブルで求めて、a,bそれぞれのLCAとの距離を足せば求められる
	
	cin >> n;
	rep(i,n-1) {
		cin >> mid >> y;
		mid--, y--;
		G[mid].pb(y);
		G[y].pb(mid);
	}
	LCAinit(n);
	
	cin >> q;
	rep(i,q) {
		cin >> a >> b;
		a--, b--;
		int lca = LCA(a,b);
		int da = depth[a] - depth[lca];
		int db = depth[b] - depth[lca];
		cout << (da + db + 1) ln;
	}
}