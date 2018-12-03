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

// 人形のサイズの種類はm 最終的な人形の最小値はs
// つまり人形の中に人形を入れる操作をn-s回する必要がある
// 自分より大きい人形の数 の総和をsdとして sdC(n-s)は嘘
// 例えば1223で1を3に入れた上で2も3に入れるような場合も数え上げてる
// こういうパターンを後から引く or 最初からきれいに数え上げる必要がある
// dp[i][j]: i種類目まででj回操作を行うような手順
// m種類あるとき操作回数の最大値はn/m(たぶん) 遷移はi種類目でO(c[i])かかる
// 操作回数がめちゃくちゃ多ければc[i]は小さくなるから大丈夫かもしれない

ll n, a[114514], b[114514], c[114514], m = 1, s, f[114514], res = 1;

ll mpow(ll x, ll n=mod-2, ll m=mod) {
	ll res = 1;
	while (n>0) {
		if (n&1) res = res * x %m;
		x = x * x %m;
		n >>= 1;
	}
	return res;
}

ll pam(ll n, ll k) {
	return f[n] * mpow(f[n-k]) %mod;
}

signed main() {
	cin >> n;
	rep(i,n) cin >> a[i];
	sort(a,a+n);
	// 圧縮
	rep(i,n) {
		if (i>0 && a[i]!=a[i-1]) m++;
		b[i] = m-1;
		c[b[i]]++, chmax(s, c[b[i]]);
	}
	f[0] = 1;
	for (ll i = 1; i <= 100000; ++i) f[i] = f[i-1]*i %mod;
	rep(i,m) (res *= pam(s, c[i])) %= mod;
	cout << res * mpow(f[s]) %mod << ln;
}