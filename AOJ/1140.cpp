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

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m; assert(b>=0); for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
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

int h, w;
string s[20];

// (h,w) <-> (y,x)
int mn(int sy, int sx, int gy, int gx) {
	queue<pair<int,pii> > q;
	q.push({0,{sy,sx}});
	int d[20][20];
	rep(i,h) rep(j,w) d[i][j] = inf;
	d[sy][sx] = 0;
	while (!q.empty()) {
		int x = q.front().se.se, y = q.front().se.fi, dis = q.front().fi; q.pop();
		if (d[y][x]<dis) continue;
		rep(i,4) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx<0 || xx>=w || yy<0 || yy>=h || d[yy][xx]<=dis+1 || s[yy][xx]=='x') continue;
			d[yy][xx] = dis+1;
			q.push({dis+1,{yy,xx}});
		}
	}
	return d[gy][gx];
}

signed main() {
	while (1) {
		cin >> w >> h;
		if (h==0) break;
		vi ti, tj;
		// 0: スタート地点
		int d[11][11] = {};
		rep(i,11) rep(j,11) if (i!=j) d[i][j] = inf;
		rep(i,h) {
			cin >> s[i];
			rep(j,w) if (s[i][j]=='o') ti.pb(i), tj.pb(j);
		}
		rep(i,h) rep(j,w) if (s[i][j]=='*') ti.pb(i), tj.pb(j);
		int n = ti.size();
		
		rep(i,n) reps(j,i+1,n) d[i][j] = d[j][i] = mn(ti[i],tj[i],ti[j],tj[j]);
		bool fin = 0;
		reps(i,1,n) if (d[0][i]==inf) fin = 1;
		if (fin) {
			cout << -1 << ln;
			continue;
		}
		rep(k,n) rep(i,n) rep(j,n)
		    chmin(d[i][j], d[i][k]+d[k][j]);
		
		// dp[i][j]: 通過済みの点の集合がjであり今点iにいるような状態の最小移動回数
		int dp[11][1<<11] = {};
		rep(i,n) rep(j,1<<n) dp[i][j] = inf;
		dp[0][1] = 0;
		rep(j,1<<n) rep(i,n) if (dp[i][j]!=inf)
			rep(k,n) if (!(j>>k&1)) chmin(dp[k][j|(1<<k)], dp[i][j]+d[i][k]);
		int res = inf;
		rep(i,n) chmin(res, dp[i][(1<<n)-1]);
		cout << res << ln;
	}
}