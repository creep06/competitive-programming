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



struct S {
	int v, c, p, n;
	S(int vv, int cc, int pp, int nn) {v = vv, c = cc, p = pp, n = nn;}
	bool operator > (const S &e) const {
		if (c!=e.c) return c > e.c;
		return p>e.p;
	}
};

int n, a, x[111], y[111], d[111][3][111];
vector<S> e[111][3];

void dijkstra(int n) {
	priority_queue<S, vector<S>, greater<S> > que;
	rep(i,111) rep(j,3) rep(k,111) d[i][j][k] = inf;
	rep(i,3) d[0][i][0] = 0;
	que.push(S(0,0,0,0)), que.push(S(0,0,0,1)), que.push(S(0,0,0,2));
	while(!que.empty()) {
		S p = que.top(); que.pop();
		int v = p.v, dis = p.c, ch = p.p, ty = p.n;
		if (d[v][ty][ch] < dis) continue;
		for (int i = 0; i < e[v][ty].size(); ++i) {
			S q = e[v][ty][i];
			int u = q.v, cost = q.c, to = q.p;
			if (to!=ty) cost++;
			if (d[u][to][ch+(to!=ty)] > d[v][ty][ch] + cost) {
				d[u][to][ch+(to!=ty)] = d[v][ty][ch] + cost;
				que.push(S(u, d[u][to][ch+(to!=ty)], ch+(to!=ty), to));
			}
		}
	}
}

const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

signed main() {
	cin >> n;
	rep(i,n) rep(j,n) {
		cin >> a;
		a--;
		x[a] = i, y[a] = j;
	}
	int N = n*n;
	rep(i,N-1) {
		// knight
		set<pair<int,int> > g;
		rep(k,8) {
			int xx = x[i]+dx[k], yy = y[i]+dy[k];
			if (!ool(xx,yy,n,n)) g.insert({xx,yy});
		}
		if (g.count({x[i+1],y[i+1]})) {
			rep(k,3) e[i][k].push_back(S(i+1,1,0,0));
		} else {
			set<pair<int,int> > gg;
			each(l,g) rep(k,8) {
				int xx = l.first+dx[k], yy = l.second+dy[k];
				if (!ool(xx,yy,n,n)) gg.insert({xx,yy});
			}
			if (gg.count({x[i+1],y[i+1]})) {
				rep(k,3) e[i][k].push_back(S(i+1,2,0,0));
			}
		}
		// bishop
		int xx = abs(x[i]-x[i+1]), yy = abs(y[i]-y[i+1]);
		if (xx==yy) {
			rep(k,3) e[i][k].push_back(S(i+1,1,1,0));
		} else if ((xx+yy)%2==0) {
			rep(k,3) e[i][k].push_back(S(i+1,2,1,0));
		}
		// rook
		if (xx==0 || yy==0) {
			rep(k,3) e[i][k].push_back(S(i+1,1,2,0));
		} else {
			rep(k,3) e[i][k].push_back(S(i+1,2,2,0));
		}
	}
	dijkstra(N);
	N--;
	int st = inf, rp = inf;
	rep(i,3) rep(j,111) if (d[N][i][j]!=inf) {
		if (st>d[N][i][j]) st = d[N][i][j], rp = j;
		else if (st==d[N][i][j]) chmin(rp,j);
	}
	cout << st << ' ' << rp << endl;
}
