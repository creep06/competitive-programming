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

const int inf = (ll)1e9+10;
const ll linf = (ll)1e18+10;
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

int n, k, w[20][20], y[1<<17], dp[1<<17];

signed main() {
	cin >> n >> k;
	rep(i,n) rep(j,n) cin >> w[i][j];
	// 各部分集合ごとの信頼度の和を求めておく
	rep(i,1<<n) {
		vi a;
		rep(j,n) if (i>>j&1) a.pb(j);
		int c = a.size();
		rep(A,c) reps(B,A+1,c) y[i] += w[a[A]][a[B]];
	}
	// dp[s]: 頂点集合sに対する問題の答え
	// sの部分集合tを一つの部門にまとめ、残りのs-tを違う部門にするとすると、
	// スコアはdp[s-t] + k - (s-tとtの間の辺の重みの総和) となる
	// 第3項は y[s] - (y[s-t] + y[t]) で求められる
	// 部分集合が2^n個、それぞれについて更に部分集合のとり方に2^nかけるとO(4^n)？ 実は3^nらしい
	// マスクsのビットが1のときだけ0,1で枝分かれするから、ビット単位で考えると
	// (sのビット,tのビット) = (0,0), (1,0), (1,1) で3通りだから3^nらしい
	// (0,1)も含めて列挙しちゃうと明らかに(4^n)になってそれとの中間だから3^nって感じ？
	reps(s,1,1<<n)
		for (int t = s; t > 0; t = (t-1)&s)
			chmax(dp[s], dp[s^t] + k - (y[s]-y[s^t]-y[t]));
	cout << dp[(1<<n)-1] << ln;
}