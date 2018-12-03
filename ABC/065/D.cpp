#include <bits/stdc++.h>
using namespace std;

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
#define ln "\n"
#define show(x) cout << #x << " = " << x ln
#define dbg(x) cout<<#x"="<<x ln

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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

struct edge{int from, to, cost;};
bool comp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}
bool pCom(const pii& a, const pii& b) {
	if (a.se!=b.se) return a.se < b.se;
	else return a.fi < b.fi;
}
bool comx(const pair<int,pii>& a, const pair<int,pii>& b) {return a.se.fi < b.se.fi;}
bool comy(const pair<int,pii>& a, const pair<int,pii>& b) {return a.se.se < b.se.se;}

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

int n, x, y;
pair<int,pii> c[100000];
vector<edge> es;

//----------------↓UnionFind↓----------------

int par[100000], rnk[100000];

void init(ll n) {
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

ll Kruskal() {
	sort(all(es), comp);
	init(n);
	ll res = 0;
	for (int i = 0; i < es.size(); ++i) {
		edge e = es[i];
		if (!same(e.from, e.to)) {
			unite(e.from, e.to);
			res += e.cost;
		}
	}
	return res;
}

int main() {
	cin >> n;
	rep(i,n) {
		cin >> c[i].se.fi >> c[i].se.se;
		c[i].fi = i;
	}
	
	// 全ての点の間に辺を伸ばそうとすると約10^10本必要になる
	// A(s,i) < B(t,j) < C(u,k)と並んだ3点があるとして、
	// ACを繋ぐ辺1本 と ABを繋ぐ辺とBCを繋ぐ辺の2本 ではコストは一緒なので明らかに後者を選んだほうがいい
	// つまりx座標 / y座標それぞれでソートして全ての隣接する点の間のみに辺を伸ばせばいい
	// x座標
	sort(c, c+n, comx);
	reps(i,1,n) es.pb(edge{c[i-1].fi, c[i].fi, c[i].se.fi-c[i-1].se.fi});
	// y座標
	sort(c, c+n, comy);
	reps(i,1,n) es.pb(edge{c[i-1].fi, c[i].fi, c[i].se.se-c[i-1].se.se});
	ll ans = Kruskal();
	cout << ans << ln;
}