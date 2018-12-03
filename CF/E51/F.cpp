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

#define int long long
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
	static const int MAXLOGV = 17;
	static const int MAXV = 1<<MAXLOGV;
	int root;
	vector<int> e[MAXV];
	int par[MAXLOGV][MAXV], dep[MAXV];

public:
	void dfs(int v, int p, int d) {
		par[0][v] = p;
		dep[v] = d;
		for (int i=0; i<e[v].size(); i++)
			if (e[v][i]!=p) dfs(e[v][i], v, d+1);
	}
	void add(int from, int to) {
		e[from].push_back(to);
		e[to].push_back(from);
	}
	void init(int N, int ROOT) {
		root = ROOT;
		dfs(root, -1, 0);
		for (int k=0; k<MAXLOGV-1; k++)
			for (int v=0; v<N; v++) {
				if (par[k][v]<0) par[k+1][v] = -1;
				else par[k+1][v] = par[k][par[k][v]];
			}
	}
	int lca(int u, int v) {
		if (dep[u]>dep[v]) swap(u,v);
		for (int k=0; k<MAXLOGV; k++)
			if ((dep[v]-dep[u])>>k&1) v = par[k][v];
		if (u==v) return u;
		for(int k=MAXLOGV-1; k>=0; k--)
			if (par[k][u]!=par[k][v]) {
				u = par[k][u];
				v = par[k][v];
			}
		return par[0][u];
	}
};

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

int n, m, a, b, c, q, dt[114514], ds[114514][44], d[44][44];
LCA lc;
UF uf(114514);
vector<pair<int,int> > e[114514];
vector<pair<pair<int,int>,int> > es;
set<int> com;
map<int,int> t;
vector<int> r(44);

void rec(int v, int p, int dis) {
	dt[v] = dis;
	each(i,e[v]) if (i.first!=p) rec(i.first, v, dis+i.second);
}

int dist(int x, int y) {
	return dt[x] + dt[y] - dt[lc.lca(x,y)]*2;
}

signed main() {
	cin >> n >> m;
	rep(i,m) {
		cin >> a >> b >> c;
		a--, b--;
		if (uf.same(a,b)) {
			es.push_back({{a,b},c});
			com.insert(a), com.insert(b);
		} else {
			e[a].push_back({b,c}), e[b].push_back({a,c});
			lc.add(a,b);
			uf.unite(a,b);
		}
	}
	// 根付き木の根(頂点0)から各点への距離を求める
	rec(0,-1,0);
	// 余った辺が繋ぐ頂点たちの番号を圧縮
	lc.init(n,0);
	int num = 0;
	each(i,com) t[i] = num, r[num++] = i;
	// このnum個の頂点間の最短距離を求める
	rep(i,num) rep(j,num) if (i!=j) d[i][j] = linf;
	each(i,es) {
		a = i.first.first, b = i.first.second, c = i.second;
		int ta = t[a], tb = t[b];
		d[ta][tb] = d[tb][ta] = c;
	}
	rep(i,num) reps(j,i+1,num) {
		int dis = dist(r[i],r[j]);
		chmin(d[i][j],dis), chmin(d[j][i],dis);
	}
	rep(k,num) rep(i,num) rep(j,num)
		chmin(d[i][j], d[i][k]+d[k][j]);
	// 各頂点とnum個の頂点間の距離を事前に求めておく(ここをクエリごとにやってるとTLE)
	rep(i,n) rep(j,num) ds[i][j] = dist(i,r[j]);
	// クエリに答える
	cin >> q;
	while (q--) {
		cin >> a >> b;
		a--, b--;
		int res = dist(a,b);
		rep(i,num) rep(j,num) if (i!=j)
			chmin(res, ds[a][i] + d[i][j] + ds[b][j]);
		cout << res << endl;
	}
}
