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
#define chmin(x,y) if((x)>(y))(x)=(y)
#define chmax(x,y) if((x)<(y))(x)=(y)
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

ll mop(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// d[i][j]: 街iに総コストjかけて到着する際に遭遇する盗賊の数の最小値
int n, m, s, a, b, l, x, d[101][101];
vector<pair<int,pii> > e[101];

void dijkstra() {
	priority_queue<pair<pii,int>, vector<pair<pii,int> >, greater<pair<pii,int> > > que;
	rep(i,n) rept(j,s) d[i][j] = inf;
	d[0][0] = 0;
	que.push({{0,0},0});
	while(!que.empty()) {
		int v = que.top().second, th = que.top().fi.fi, cs = que.top().fi.se; que.pop();
		if (d[v][cs]<th) continue;
		for (int i = 0; i < e[v].size(); ++i) {
			int to = e[v][i].first, dist = e[v][i].se.fi, bd = e[v][i].se.se;
			// 護衛を雇う場合
			if (cs+dist<=s && d[to][cs+dist] > d[v][cs]) {
				d[to][cs+dist] = d[v][cs];
				que.push({{d[to][cs+dist], cs+dist}, to});
			}
			// 雇わない場合
			if (d[to][cs] > d[v][cs] + bd) {
				d[to][cs] = d[v][cs] + bd;
				que.push({{d[to][cs], cs}, to});
			}
		}
	}
}

signed main() {
	while (1) {
		cin >> n >> m >> s;
		if (n==0) break;
		rep(i,n) e[i].clear();
		rep(i,m) {
			cin >> a >> b >> l >> x;
			a--, b--;
			e[a].pb({b,{l,x}}), e[b].pb({a,{l,x}});
		}
		dijkstra();
		int res = inf;
		rept(i,s) chmin(res,d[n-1][i]);
		cout << res << ln;
	}
}