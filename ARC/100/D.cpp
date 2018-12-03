#include <bits/stdc++.h>
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

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// 真ん中の切れ目を決めた後左右の2個をなるべく均等に切るのが最善
int n, a[200200], b[200200], res = LONG_LONG_MAX;
int p, q, r, s;

void le(int m) {
	int sum = b[m];
	int t = lower_bound(b,b+n,sum/2) - b;
	p = b[t], q = b[m]-b[t];
	while (1) {
		t--;
		if (t<=0) break;
		int be = abs(p-q), nw = abs(b[t] - (b[m]-b[t]));
		if (nw<be) p = b[t], q = b[m]-b[t];
		else break;
	}
}

void ri(int m) {
	int sum = b[n] - b[m-1];
	int sea = b[m-1] + sum/2;
	int t = lower_bound(b,b+n,sea) - b;
	r = b[t] - b[m-1], s = b[n]-b[t];
	while (1) {
		t--;
		if (t<=0) break;
		int rr = b[t] - b[m-1], ss = b[n]-b[t];
		int be = abs(r-s), nw = abs(rr-ss);
		if (nw<be) r = rr, s = ss;
		else break;
	}
}

signed main() {
	cin >> n;
	repst(i,1,n) {
		cin >> a[i];
		b[i] = a[i] + b[i-1];
	}
	// i:左半分の右端
	repst(i,2,n-2) {
		int sl = b[i], sr = b[n] - b[i];
		int gl = sl/2, gr = sl + sr/2;
		le(i), ri(i+1);
		int mn = tmin(p,q,min(r,s)), mx = tmax(p,q,max(r,s));
		chmin(res, mx-mn);
	}
	cout << res << ln;
}