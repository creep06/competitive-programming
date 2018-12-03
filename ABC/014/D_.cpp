#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto &(itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define bln(i,n) (i==n-1?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
typedef vector<bool> vb;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int> > mat;

const ll inf = (ll)1e9+10;
const ll linf = (ll)1e18+10;
const ll mod = (ll)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double eps = 1e-10;

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

const int MAX_V = 100100;
int n, a, b, q;
vi G[MAX_V];

int root;				// 根ノードの番号
int parent[20][MAX_V];		// parent[k][i]: iの親を2^k回辿って到達する頂点 (根を通り過ぎる場合は-1)
int depth[MAX_V];		// 根からの深さ

void LCAdfs(int v, int p, int d) {
	parent[0][v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); ++i) {
		if (G[v][i] != p) LCAdfs(G[v][i], v, d+1);
	}
}

// LCAの初期化
void LCAinit(int V) {
	// parent[0](真上の親)とdepthを初期化する
	LCAdfs(root, -1, 0);
	// parent[k](k>=1)を初期化する
	for (int k = 0; k+1 < 20; ++k) {
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
	for (int k = 0; k < 20; ++k) {
		if ((depth[v]-depth[u])>>k & 1) v = parent[k][v];
	}
	if (u == v) return u;
	
	// 二分探索でLCAを求める
	for (int k = 19; k >= 0; --k) {
		if (parent[k][u] != parent[k][v]) {
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}

signed main() {
	cin >> n;
	rep(i,n-1) {
		cin >> a >> b;
		a--, b--;
		G[a].pb(b), G[b].pb(a);
	}
	LCAinit(n);
	cin >> q;
	while (q--) {
		cin >> a >> b;
		a--, b--;
		int p = LCA(a,b);
		cout << depth[a]+depth[b]-2*depth[p]+1 << ln;
	}
}