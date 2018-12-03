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

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// 風船は同時に3個まで k個持ってると1動くのにk+1秒かかる
// dp[i][j]: i番目までを移動距離jで運びきって原点にいる状態になるのにかかる時間の最小値
int n, p[40], t[40], dp[44][8080];

void solve() {
	rept(i,n) rept(j,8000) dp[i][j] = inf;
	dp[0][0] = 0;
	rep(i,n) rept(j,8000) if (dp[i][j]!=inf) {
		// iを運ぶ
		if (dp[i][j]+p[i]<=t[i]) chmin(dp[i+1][j+p[i]*2], t[i]+p[i]*2);
		else continue;
		// i+1も同時に運ぶ
		if (i+1>=n) continue;
		int d = abs(p[i]-p[i+1]);
		if (t[i]+d*2<=t[i+1]) chmin(dp[i+2][j+p[i]+d+p[i+1]], t[i+1]+p[i+1]*3);
		else continue;
		// i+2も同時に運ぶ
		if (i+2>=n) continue;
		int e = abs(p[i+1]-p[i+2]);
		if (t[i+1]+e*3<=t[i+2]) chmin(dp[i+3][j+p[i]+d+e+p[i+2]], t[i+2]+p[i+2]*4);
	}
	int res = inf;
	rept(i,8000) if (dp[n][i]!=inf) chmin(res,i);
	if (res==inf) {
		repst(i,1,n) {
			bool ng = 1;
			rept(j,8000) if (dp[i][j]!=inf) ng = 0;
			if (ng) {
				cout << "NG " << i << ln;
				return;
			}
		}
	} else cout << "OK " << res << ln;
}

signed main() {
	while (1) {
		cin >> n;
		if (n==0) break;
		rep(i,n) cin >> p[i] >> t[i];
		solve();
	}
}