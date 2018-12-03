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

typedef complex<double> P;
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



int n, m, x, a, b, c, dif, eq, up, res, mx[1010][1010];
vector<pair<int,pair<int,int> > > e;
vector<pair<int,int> > ee[1010];
bool us[2020], vis[1010];

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

int kruskal(int n, int m, vector<pair<int,pair<int,int> > > &e) {
	sort(e.begin(),e.end());
	UF uf(n);
	int res = 0;
	for (int i=0; i<m; ++i) {
		if (!uf.same(e[i].second.first, e[i].second.second)) {
			uf.unite(e[i].second.first, e[i].second.second);
			res += e[i].first, us[i] = 1;
		}
	}
	return res;
}

void rec(int v, int t, int p) {
	vis[v] = 1;
	mx[p][v] = t;
	each(i,ee[v]) if (!vis[i.first]) rec(i.first, max(t,i.second), p);
}

signed main() {
	cin >> n >> m >> x;
	rep(i,m) {
		cin >> a >> b >> c;
		a--, b--;
		e.push_back({c,{a,b}});
	}
	dif = x - kruskal(n,m,e);
	rep(i,m) if (us[i])
		ee[e[i].second.first].push_back({e[i].second.second,e[i].first}),
		ee[e[i].second.second].push_back({e[i].second.first,e[i].first});
	rep(i,n) zero(vis), rec(i,0,i);
	rep(i,m) if (!us[i]) {
		int t = e[i].first - mx[e[i].second.first][e[i].second.second];
		if (t==dif) eq++;
		else if (t>dif) up++;
	}
	if (dif<0) res = 0;
	else if (dif==0) res = (mop(2,n-1)+mod-2) %mod *mop(2,m-n+1) + 2*(mop(2,eq)-1)*mop(2,up);
	else res = 2*(mop(2,eq)-1)*mop(2,up);
	res %= mod;
	cout << res << endl;
}
