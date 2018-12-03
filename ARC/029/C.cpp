#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rept(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
#define repst(i,s,n) for(int (i)=(s);(i)<=(int)(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > mat;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
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

struct edge {int from, to, cost;};
bool comp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}

ll n, m, c, a, b, r;
edge es[300300];

//----------------↓UnionFind↓----------------

int par[300300], rnk[300300];

void init(int n) {
	for (int i=0; i<n; i++) {
		par[i] = i;
		rnk[i] = 0;
	}
}

int find(int x) {
	if (par[x]==x) return x;
	else return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x==y) return;
	
	if (rnk[x]<rnk[y]) par[x] = y;
	else {
		par[y] = x;
		if (rnk[x]==rnk[y]) rnk[x]++;
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

//----------------↑UnionFind↑----------------

int Kruskal() {
	sort(es, es+m, comp);
	init(n);
	int res = 0;
	for (int i = 0; i < m; ++i) {
		edge e = es[i];
		if (!same(e.from, e.to)) {
			unite(e.from, e.to);
			res += e.cost;
		}
	}
	return res;
}

signed main() {
	cin >> n >> m;
	// 頂点0から各点iにコストc[i]の辺を引く
	rep(i,n) {
		cin >> c;
		es[i] = {0,i+1,c};
	}
	rep(i,m) {
		cin >> a >> b >> r;
		es[n+i] = {a,b,r};
	}
	n++;
	n = m = n+m;
	cout << Kruskal() << ln;
}