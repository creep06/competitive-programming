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
#define each(i,v) for(auto &(i):(v))
#define eachr(i,v) for(auto &(i)=(v).rbegin();(i)!=(v).rend();(i)++)
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
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
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

// 距離dだったものが(d+1)/2になる
// 0と他の点との距離の総和をsとすると、
// 1と他の点との距離の総和は？
// 距離が1減る頂点群と1増える頂点群がある

int n, a, b, d[200200], s, res;
vector<int> e[200200];
pair<int,int> pa[200200];
LCA lc;

void rec(int v, int p, int dis) {
	d[v] = dis;
	each(i,e[v]) if (i!=p) rec(i, v, dis+1);
}

pair<int,int> rec2(int v, int p) {
	if (e[v].size()==1 && e[v][0]==p) {
		int ev = (d[v]%2==0), od = (d[v]%2==1);
		return pa[v] = {ev,od};
	}
	pair<int,int> t = {(d[v]%2==0), (d[v]%2==1)};
	each(i,e[v]) if (i!=p) {
		pair<int,int> g = rec2(i,v);
		t.first += g.first, t.second += g.second;
	}
	return pa[v] = t;
}

void rec3(int v, int p, int dep, int ev, int od, int sum) {
	int dev = pa[v].first, dod = pa[v].second;
	if (v) {
		if (dep) sum += ev - dod;
		else sum += od - dev;
	}
	res += sum;
	each(i,e[v]) if (i!=p) {
		int x = dev - pa[i].first, y = dod - pa[i].second;
		rec3(i,v,dep^1,ev+x,od+y,sum);
	}
}

signed main() {
	cin >> n;
	rep(i,n-1) {
		cin >> a >> b;
		a--, b--;
		lc.add(a,b);
		e[a].push_back(b), e[b].push_back(a);
	}
	lc.init(n,0);
	rec(0,-1,0);
	rep(i,n) s += (d[i]+1)/2;
	rec2(0,-1);
	rec3(0,-1,0,0,0,s);
	cout << res/2 << endl;
}
