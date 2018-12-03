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
#define chmin(x,y) if(x>y)x=y
#define chmax(x,y) if(x<y)x=y
#define log2(x) (log(x)/log(2))
#define ln '\n'
#define bln(i,n) ((i==n-1)?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

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

// N<=20000で、
// 1) 30000以下の異なる正の整数のみからなる数列
// 2) Sの全ての要素を割り切れる整数は存在しない -> 1個でも互いに素なペアがあればいい
// 3) どのiについてもa[i]と(Σa)-a[i]のGCDは1でない
// 2の倍数と3の倍数が[1,30000]の範囲に合わせて2万個ある
// それをただ並べるだけじゃ3を満たさない
// 2+4, 8+10, 14+16, ...は3の倍数 5000組10000数字
// 3*1+3*3, 3*5+3*7, 3*9+3*11, ...は2の倍数 2500組5000数字
// これら2グループをうまく足し合わせて調整 片方のみ使うのはダメ
// 6の倍数で足りない部分を補う

int n;
vi r, c;
vpii a, b;

signed main() {
	cin >> n;
	if (n==3) return cout << "2 5 63" << ln, 0;
	
	for (int i = 8; i+2 <= 30000; i += 6) a.pb({i,i+2});
	for (int i = 15; i+6 <= 30000; i += 12) b.pb({i,i+6});
	for (int i = 6; i <= 30000; i += 6) c.pb(i);
	
	r.pb(2), r.pb(4), r.pb(3), r.pb(9);
	n -= 4;
	each(i,a) {
		if (n<=1) break;
		r.pb(i.fi), r.pb(i.se);
		n -= 2;
	}
	each(i,b) {
		if (n<=1) break;
		r.pb(i.fi), r.pb(i.se);
		n -= 2;
	}
	each(i,c) {
		if (n==0) break;
		r.pb(i);
		n -= 1;
	}
	rep(j,r.size()) cout << r[j] << bln(j,r.size());
}