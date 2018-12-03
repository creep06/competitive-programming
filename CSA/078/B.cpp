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

int n, a[100100], mx;
vi m;

signed main() {
	cin >> n;
	rep(i,n) cin >> a[i];
	
	/*
	reps(i,1,n) chmax(mx, a[i]-a[i-1]);
	reps(i,1,n) if (a[i]-a[i-1]==mx) m.pb(i);
	if (m.size()>=3) return cout << mx << ln, 0;
	else if (m.size()==2) {
		// 片方が端っこならそれを動かしてもう片方を打ち消せる
		if (m[0]==1) a[0] = (a[m[1]] + a[m[1]-1]) / 2;
		else if (m[1]==n-1) a[n-1] = (a[m[0]] + a[m[0]-1]) / 2;
		sort(a,a+n);
	}
	else {
		int mi = m[0];
		if (mi==1) a[0] = a[1];
		else if (mi==n-1) a[n-1] = a[n-2];
		else a[mi] =
	}
	*/
	
	int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
	reps(i,2,n) {
		int t = a[i] - a[i-1];
		if (t>a1) a2 = a1, a1 = t;
		else if (t>a2) a2 = t;
	}
	reps(i,1,n-1) {
		int t = a[i] - a[i-1];
		if (t>b1) b2 = b1, b1 = t;
		else if (t>b2) b2 = t;
	}
	cout << min(max((a1+1)/2,a2), max((b1+1)/2,b2)) << ln;
}