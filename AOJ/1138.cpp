#include <bits/stdc++.h>
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

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m;for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}
bool ool(int x,int y,int h,int w) {return((x<0)||(h<=x)||(y<0)||(w<=y));}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

struct S {
	int v, t; // 頂点 馬車券
	double c; // コスト
	S(int vv, double cc, int tt) {v = vv, c = cc, t = tt;}
	bool operator > (const S &e) const {return c > e.c;}
};

int n, m, p, a, b, t[8], x, y, z;
double d[30][1<<8];
vector<S> e[30][1<<8];

void dijkstra() {
	priority_queue<S, vector<S>, greater<S> > que;
	que.push(S(a,0,0));
	while(!que.empty()) {
		S p = que.top(); que.pop();
		int v = p.v, ti = p.t;
		double dis = p.c;
		if (d[v][ti] < dis) continue;
		for (int i = 0; i < e[v][ti].size(); ++i) {
			S q = e[v][ti][i];
			int u = q.v, af = q.t;
			double cost = q.c;
			if (d[u][af] > d[v][ti] + cost) {
				d[u][af] = d[v][ti] + cost;
				que.push(S(u, d[u][af], af));
			}
		}
	}
}

signed main() {
	while (1) {
		cin >> m >> n >> p >> a >> b;
		if (n==0) break;
		a--, b--;
		rep(i,n) rep(j,1<<m) d[i][j] = 1e100, e[i][j].clear();
		d[a][0] = 0;
		rep(i,m) cin >> t[i];
		rep(i,p) {
			cin >> x >> y >> z;
			x--, y--;
			rep(j,m) rep(k,1<<m) if (!(k>>j&1))
				e[x][k].pb(S(y, 1.*z/t[j], k|(1<<j))), e[y][k].pb(S(x, 1.*z/t[j], k|(1<<j)));
		}
		dijkstra();
		double res = 1e100;
		rep(i,1<<m) chmin(res, d[b][i]);
		if (res==1e100) printf("Impossible\n");
		else printf("%.14lf\n",res);
	}
}