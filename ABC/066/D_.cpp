#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto &(itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define bln(i,n) (i==n-1?'\n':' ')
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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// 重複する数字をd、その数字の位置をl,r(l<r)とすると、長さiの部分列の数え上げは
// (1)dを含まない選び方 (2)dを1個だけ含む選び方 (3)dを2個とも含む選び方
// に分解できる (1)と(3)は普通にやればok
// (2)で問題になるのは区間(l,r)の数字を1つも採用していない数列
// 例えば1234536とあったとき1234--6と12-4-36は区別できても123---6と12---36は区別できない
// これを引いてやればいい

ll n, f[100100], a[100100], l, r, s;
int u[100100];

ll mpow(ll x, ll n=mod-2, ll m=mod) {
	ll res = 1;
	while (n>0) {
		if (n&1) res = res * x %m;
		x = x * x %m;
		n >>= 1;
	}
	return res;
}

ll comb(int n, int k) {
	if (n<k) return 0;
	return f[n] * mpow(f[k]) %mod * mpow(f[n-k]) %mod;
}

signed main() {
	cin >> n;
	memset(u, -1, sizeof(u));
	rep(i,n+1) {
		cin >> a[i];
		if (u[a[i]]!=-1) l = u[a[i]], r = i;
		u[a[i]] = i;
	}
	
	f[0] = f[1] = 1;
	for (ll i = 2; i <= 100000; ++i) f[i] = f[i-1]*i %mod;
	s = r - l + 1;
	cout << n << ln;
	repst(k,2,n+1) {
		// type1, 3
		ll res = (comb(n-1, k) + comb(n-1, k-2)) %mod;
		// type2
		(res += 2*comb(n-1, k-1) + mod - comb(n+1-s, k-1)) %= mod;
		cout << res << ln;
	}
}