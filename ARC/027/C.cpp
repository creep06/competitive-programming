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

// dp[i][j][k]: i番目まででスペシャルチケットをj枚、通常のチケットをk枚使うような買い方をしたときの嬉しさの最大値 存在しない場合-1
// 明らかに通常のチケットを優先的に使ったほうがいいから考えるべき遷移は絞られる
ll x, y, n, t[300], h[300], dp[301][301][301], xx, yy, zz, r;

signed main() {
	cin >> x >> y >> n;
	rep(i,n) cin >> t[i] >> h[i];
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	rep(i,n) rept(j,x) rept(k,y) {
		if (dp[i][j][k]==-1) continue;
		// i番目を買わない場合
		chmax(dp[i+1][j][k], dp[i][j][k]);
		// スペシャルの残り枚数、通常の残り枚数、合計
		xx = x-j, yy = y-k, zz = xx + yy;
		if (xx==0 || zz<t[i]) continue;
		// スペシャル1枚と通常t[i]-1枚で買えるならそうする
		if (t[i]-1<=yy) chmax(dp[i+1][j+1][k+t[i]-1], dp[i][j][k]+h[i]);
		// 通常が足りない場合 通常を持ってるぶん使った上で残りをスペシャルで補うしかない
		else chmax(dp[i+1][j+t[i]-yy][k+yy], dp[i][j][k]+h[i]);
	}
	rept(i,x) rept(j,y) chmax(r, dp[n][i][j]);
	cout << r << ln;
}