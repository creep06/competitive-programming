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

// まず関数fはx1^i * x2^j * x3^k * ... (i+j+k+... = c)のi,j,k,...全通りの組み合わせの和
// 例えばn==3のときx=x1, y=x2, z=x3とすると x^3+y^3+z^3 + x^2y+x^2z+y^2x+y^2z+z^2x+z^2y + xyz
// dp[k][l]: k番目まででl個の飴を配ったときのxi^aiの総和 とおくと
// a==bのとき dp[k+1][l+m] = Σ dp[k][l+p] * a[i]^p (p = 0,1,...,m)
// a!=bのとき dp[k+1][l+m] = Σ dp[k][l+p] * (a[i]^p + (a[i]+1)^p + ... + b[i]^p)
// 一番最後のかっこ内は事前計算しとく

int n, c, a[429], b[429], s[429][429], sp[429][429], dp[429][429];

signed main() {
	cin >> n >> c;
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];
	// sp[i][j] = i^j
	// s[i][j] = 0^j + 1^j + ... + (i-1)^j
	sp[0][0] = 1;
	repst(i,1,400) {
		sp[i][0] = 1;
		rep(j,400) sp[i][j+1] = sp[i][j]*i %mod;
	}
	rept(j,400) rept(i,400) s[i+1][j] = (s[i][j] + sp[i][j]) %mod;
	dp[0][0] = 1;
	// i番目まででx個配った状態 -> i+1番目まででx+y個配った状態 という遷移
	rep(i,n) rept(x,c) rept(y,c-x) {
		ll p = (s[b[i]+1][y] + mod - s[a[i]][y]) %mod;
		dp[i+1][x+y] = (dp[i+1][x+y] + dp[i][x]*p) %mod;
	}
	cout << dp[n][c] << ln;
}