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

// bはaをkで割った余りである必要がある b==a(mod k)ではダメらしい つまり
// x a%k == b%k
// o a%k == b
// kはbの最大値を超えてる必要があるってこと
ll n, a[101010], b[101010], c, mx, g;

signed main() {
	cin >> n;
	rep(i,n) cin >> a[i];
	rep(i,n) {
		cin >> b[i];
		chmax(mx, b[i]);
	}
	rep(i,n) {
		c = a[i] - b[i];
		if (c<0) {
			cout << -1 << ln;
			return 0;
		}
		g = __gcd(g, c);
	}
	if (g==0) cout << mx + 1 << ln;
	else if (g<=mx) cout << -1 << ln;
	else {
		// cのgcdの約数のうち一番小さい&mxを超えてるものを採用
		ll r = g;
		for (ll i = 1; i*i <= g; ++i) {
			if (g%i) continue;
			if (i>=mx) chmin(r, i);
			if (g/i>=mx) chmin(r, g/i);
		}
		cout << r << ln;
	}
}