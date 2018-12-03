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

// どこで反転するかを全探索

int n, c, x, v, s, p, r;
vpii a, b;
int ma[100100], mb[100100], sma[100100], smb[100100];

signed main() {
	cin >> n >> c;
	rep(i,n) {
		cin >> x >> v;
		a.pb({x,v}), b.pb({c-x,v});
	}
	
	sort(all(a)), sort(all(b));
	rep(i,n) {
		sma[i] = (i==0 ? 0 : sma[i-1]) + a[i].se;
		smb[i] = (i==0 ? 0 : smb[i-1]) + b[i].se;
	}
	
	rep(i,n) {
		s += a[i].se - (a[i].fi - p);
		chmax(ma[i],s);
		chmax(r,s);
		if (0<i) chmax(ma[i],ma[i-1]);
		p = a[i].fi;
	}
	
	s = p = 0;
	rep(i,n) {
		s += b[i].se - (b[i].fi - p);
		chmax(mb[i],s);
		chmax(r,s);
		if (0<i) chmax(mb[i],mb[i-1]);
		p = b[i].fi;
	}
	
	// 時計回りにi番目まで回収してから逆に戻る
	rep(i,n) {
		s = sma[i] - a[i].fi*2;
		if (s>0) chmax(r, s + (i==n-1 ? 0 : mb[n-i-2]));
	}
	rep(i,n) {
		s = smb[i] - b[i].fi*2;
		if (s>0) chmax(r, s + (i==n-1 ? 0 : ma[n-i-2]));
	}
	cout << r << ln;
}