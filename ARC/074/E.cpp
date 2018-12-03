#include <bits/stdc++.h>
using namespace std;

//#define int long long
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
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
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

// dp[r][g][b]: r,b,gがそれぞれ赤,緑,青を最後に塗ったマスの座標である塗り方の総数
// 座標i+1を例えば赤で塗るときはdp[i+1][g][b] += dp[r][g][b]とすればいい
// 条件チェックはk=max(r,g,b)としてr==kの条件だけ確認して、アウトならdp[r][g][b]を0にするようにする
int n, m, l, r, x, dp[301][301][301], ans;
vpii c[301];

bool inc(int t) {return l<=t && t<=r;}

signed main() {
	cin >> n >> m;
	rep(i,m) {
		cin >> l >> r >> x;
		c[r].pb({l,x});
	}
	dp[0][0][0] = 1;
	rept(i,n) rept(j,n) rept(k,n) {
		if (dp[i][j][k]==0) continue;
		int mx = tmax(i,j,k);
		// 条件チェック
		each(p,c[mx]) {
			tie(l,x) = p, r = mx;
			if (inc(i) + inc(j) + inc(k) != x) {
				dp[i][j][k] = 0;
				continue;
			}
		}
		if (mx==n) {
			(ans += dp[i][j][k]) %= mod;
			continue;
		}
		(dp[mx+1][j][k] += dp[i][j][k]) %= mod;
		(dp[i][mx+1][k] += dp[i][j][k]) %= mod;
		(dp[i][j][mx+1] += dp[i][j][k]) %= mod;
	}
	cout << ans << ln;
}