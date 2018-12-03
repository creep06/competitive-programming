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
const ll mod = (int)(1e9+7);
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

// 1,2,3なら110100って感じで数列を0-1で表してxyzを含まない数列を数え上げる
// dp[i][s]: 数列のa[i-1]までを矛盾なく直前の和が集合s(|s| <= x+y+z-1)であるように数字を決めてきた数列の個数

int n, x, y, z, l, ng;
ll dp[41][1<<16], ans;

signed main() {
	cin >> n >> x >> y >> z;
	l = x+y+z-1;
	int m = (1<<l)-1;
	ng = (1<<l) | (1<<(l-x)) | (1<<(l-x-y));
	dp[0][0] = 1;
	rep(i,n) repst(a,1,10) rep(s,1<<l) {
		int t = (s<<a) | (1<<(a-1));
		if ((ng&t)!=ng) dp[i+1][t&m] = (dp[i+1][t&m] + dp[i][s]) %mod;
	}
	ans = 1;
	rep(i,n) ans = ans*10 %mod;
	rep(s,1<<l) ans -= dp[n][s];
	ans %= mod, ans += mod, ans %= mod;
	cout << ans << ln;
}