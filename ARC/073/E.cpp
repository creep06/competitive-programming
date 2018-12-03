#include <bits/stdc++.h>
using namespace std;

#define int long long
#define reps(i,s,n) for(ll (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,n+1)
#define repst(i,s,n) reps(i,s,n+1)
#define reprt(i,n,t) for(ll (i)=(n);(i)>=t;--(i))
#define repr(i,n) reprt(i,n,0)
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
#define dbga(x,n) for(int (i)=0;i<n;++i){cout<<x[i]<<(i==n-1?'\n':' ');}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
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

ll n, x, y, mx, mn = inf, r, d;
pii a[252525];

signed main() {
	cin >> n;
	rep(i,n) {
		// x<=yにしとく
		cin >> x >> y;
		if (x>y) swap(x,y);
		// デカイ方(y)だけのmin/max
		chmin(mn,y), chmax(mx,y);
		a[i] = {x,y};
	}
	sort(a, a+n);
	// するとmxがRmax/Bmax, mnがRmin/Bminそれぞれどちらかになるから決め打ちできる とりあえずmnは赤で塗ることにして、
	// 1) mxは青で塗る場合
	// 残りはxを赤、yを青で塗るのが最善
	r = (mx-mn) * (a[n-1].fi-a[0].fi);
	// 2) mxも赤で塗る場合
	// 残りはどう塗っても赤のmin/maxが変わらないから青のmax-minを最小化することだけ考えればいい
	d = mx-a[0].fi, mn = inf, mx = 0;
	rep(i,n) {
		if (a[i].fi>=mn) break;
		chmin(mn, a[i].se), chmax(mx, a[i].se);
		chmin(r, d * (max(a[n-1].fi, mx) - min(mn, a[i+1].fi)));
	}
	cout << r << ln;
}