#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <string.h>
#include <numeric>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto &(itr):(v))
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define bln(i,n) (((i)==(n)-1)?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln<<flush
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ')<<flush;}}
#define zero(a) memset(a,0,sizeof(a))
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())

//typedef complex<double> P;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
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

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m;for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}
bool ool(int x,int y,int h,int w) {return((x<0)||(h<=x)||(y<0)||(w<=y));}
bool deq(double a,double b) {return abs(a-b)<eps;}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;



class LCA {
private:
	static const int MAXLOGV = 20;
	static const int MAXV = 1<<MAXLOGV;
	int root;
	vector<pair<int,int> > e[MAXV];
	int par[MAXLOGV][MAXV], cost[MAXLOGV][MAXV], dep[MAXV];

public:
	void dfs(int v, int p, int d) {
		par[0][v] = p;
		dep[v] = d;
		for (int i=0; i<e[v].size(); i++) {
			if (e[v][i].first!=p) dfs(e[v][i].first, v, d+1);
			else cost[0][v] = e[v][i].second;
		}
	}
	void add(int from, int to, int dis) {
		e[from].push_back({to,dis});
		e[to].push_back({from,dis});
	}
	void init(int N, int ROOT) {
		root = ROOT;
		dfs(root, -1, 0);
		for (int k=0; k<MAXLOGV-1; k++)
			for (int v=0; v<N; v++) {
				if (par[k][v]<0) par[k+1][v] = -1, cost[k+1][v] = cost[k][v];
				else par[k+1][v] = par[k][par[k][v]], cost[k+1][v] = max(cost[k][v], cost[k][par[k][v]]);
			}
	}
	int query(int uu, int vv) {
		int u = uu, v = vv, p = -1;
		if (dep[u]>dep[v]) swap(u,v);
		for (int k=0; k<MAXLOGV; k++)
			if ((dep[v]-dep[u])>>k&1) v = par[k][v];
		if (u==v) p = u;
		else {
			for(int k=MAXLOGV-1; k>=0; k--)
				if (par[k][u]!=par[k][v]) {
					u = par[k][u];
					v = par[k][v];
				}
			p = par[0][u];
		}
		if (p==0) return -1;
		u = uu, v = vv;
		int du = dep[u] - dep[p], dv = dep[v] - dep[p], res = 0;
		for (int k=0; k<MAXLOGV; k++) {
			if (du>>k&1) chmax(res, cost[k][u]), u = par[k][u];
			if (dv>>k&1) chmax(res, cost[k][v]), v = par[k][v];
		}
		return res;
	}
};

int n, m, a, b, q;
vector<pair<int, pair<int, int> > > te;
LCA lc;

struct UF {
	vector<int> p;
	UF(int n) : p(n, -1) {};
	bool unite(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return false;
		if (p[u] > p[v]) swap(u, v);
		p[u] += p[v]; p[v] = u;
		return true;
	}
	bool same(int u, int v) { return find(u) == find(v); }
	int find(int u) { return p[u] < 0 ? u : p[u] = find(p[u]); }
	int usize(int u) { return -p[find(u)]; }
};

void kruskal(int n, int m, vector<pair<int,pair<int,int> > > &e) {
	sort(e.begin(), e.end());
	UF uf(n);
	for (int i=0; i<m; ++i) {
		if (!uf.same(e[i].second.first, e[i].second.second)) {
			uf.unite(e[i].second.first, e[i].second.second);
			lc.add(e[i].second.first, e[i].second.second, e[i].first);
		}
	}
	for (int i=1; i<n; ++i)
		if (!uf.same(0,i)) uf.unite(0,i), lc.add(0,i,0);
}

signed main() {
	cin >> n >> m;
	n++;
	rep(i,m) {
		cin >> a >> b;
		te.push_back({i+1,{a,b}});
	}
	kruskal(n,m,te);
	lc.init(n,0);
	cin >> q;
	while (q--) {
		cin >> a >> b;
		cout << lc.query(a,b) << endl;
	}
}
