#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rept(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
#define repst(i,s,n) for(int (i)=(s);(i)<=(int)(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > mat;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
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

ll a, b, g, m, x, y, z, r;

ll mpow(ll x, ll n) {
	ll res = 1;
	while (n>0) {
		if (n&1) res = res * x %m;
		x = x * x %m;
		n >>= 1;
	}
	return res;
}

// 1が1の位からs桁おきにn回現れる数をmで割った余り 例えばn=3,s=5なら10000100001
ll f(ll n, ll s) {
	if (n<=1) return n;
	// nが奇数のとき 1周期分削る
	if (n&1) return (f(n-1,s) * s + 1) %m;
	// nが偶数のとき 半分の桁のものを求めて繋げる
	// 例えば1001001001なら1001*(10^(3*2) + 1)と分解できる
	return f(n/2,s) * (mpow(s,n/2) + 1) %m;
}

signed main() {
	cin >> a >> b >> m;
	// x=c(a)などと書くことにするとgcd(c(a),c(b)) = c(gcd(a,b))
	// gcd(a,b)をgとするとgcd(x,y) = c(g) (=zとする)
	// ∴ lcm(x,y) = x*y/z = (x/z)*(y/z)*z
	// 関数fを上のように定義すると x/z%M = f(a/g,g), y/z%M = f(b/g,g), z%M = f(g,1)
	g = __gcd(a,b);
	x = f(a/g,mpow(10,g)), y = f(b/g,mpow(10,g)), z = f(g,10);
	r = x*y %m *z %m;
	cout << r << ln;
}