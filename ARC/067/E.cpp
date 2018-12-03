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
#define pb emplace_back
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

// dp[i][j]: i人未満のグループだけでj人振り分ける場合の数 i人のグループをk個作るとすると遷移は
// dp[i+1][j+ik] += dp[i][j] * (n-j)Ci * (n-j-i)Ci * ... * (n-j-i(k-1))Ci / k! (グループ自体は区別しないため)
// 後半部分は (n-j+ik)Pik / i!^k / k! とまとまる 階乗と逆元を事前計算しとけばいい
ll n, a, b, c, d, dp[1010][1010], f[1010], fin[1010], inv[1010];

ll mpow(ll x, ll n) {
	ll res = 1;
	while (n>0) {
		if (n&1) res = res * x %mod;
		x = x * x %mod;
		n >>= 1;
	}
	return res;
}

ll comb(ll n, ll k) {return f[n] * fin[k] %mod *fin[n-k] %mod;}

signed main() {
	cin >> n >> a >> b >> c >> d;
	rep(i,1010) dp[i][0] = 1;
	// f[i]==i! fin[i]==i!^(mod-2) inv[i]==i^(mod-2)
	f[0] = fin[0] = 1;
	reps(i,1,1010) {
		inv[i] = mpow(i,mod-2);
		f[i] = f[i-1]*i %mod;
		fin[i] = fin[i-1]*inv[i] %mod;
	}
	repst(i,a,b) {
		rept(j,n) {
			if (dp[i][j]==0) continue;
			// i人のグループを一つも作らない
			if (j!=0) dp[i+1][j] = (dp[i+1][j] + dp[i][j]) %mod;
			ll p = 1;
			repst(k,1,d) {
				if (j+i*k>n) break;
				p = p * comb(n-j-i*(k-1), i) %mod * inv[k] %mod;
				if (c<=k) dp[i+1][j+i*k] = (dp[i+1][j+i*k] + dp[i][j]*p) %mod;
			}
		}
	}
	cout << dp[b+1][n] << ln;
}