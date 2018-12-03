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

// うさぎとねこを0と1にして配列とかメソッドをまとめるべきだった クソ実装

int n, u, v, m, r[505][505], c[505][505], t, rh[505], rw[505], rdl, rdr, ch[505], cw[505], cdl, cdr;
map<int,pii> rp, cp;

bool rwin() {
	int x = rp[t].fi, y = rp[t].se;
	if (x==0) return 0;
	if (n==1) return u==1;
	u -= (++rh[x]==n) + (++rw[y]==n);
	if (x==y) u -= (++rdl==n);
	if (x+y==n+1) u -= (++rdr==n);
	return u<=0;
}

bool cwin() {
	int x = cp[t].fi, y = cp[t].se;
	if (x==0) return 0;
	if (n==1) return v==1;
	v -= (++ch[x]==n) + (++cw[y]==n);
	if (x==y) v -= (++cdl==n);
	if (x+y==n+1) v -= (++cdr==n);
	return v<=0;
}

signed main() {
	cin >> n >> u >> v >> m;
	repst(i,1,n) repst(j,1,n) {
		cin >> r[i][j];
		rp[r[i][j]] = {i,j};
	}
	repst(i,1,n) repst(j,1,n) {
		cin >> c[i][j];
		cp[c[i][j]] = {i,j};
	}
	rep(i,m) {
		cin >> t;
		bool a = rwin(), b = cwin();
		if (!a && !b) continue;
		else {
			if (a && b) cout << "DRAW" << ln;
			else if (a) cout << "USAGI" << ln;
			else cout << "NEKO" << ln;
			return 0;
		}
	}
	cout << "DRAW" << ln;
}