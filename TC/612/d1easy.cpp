#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
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

/*
 * (問題)
 * 絵文字が1つある状態からスタートし、コピー/ペースト/1文字削除を繰り返して絵文字をちょうどn個にするための最小操作回数を求める
 *
 * (解法)
 * dp[i][j]: i個の絵文字があり、クリップボードにはj個の絵文字がある状態の最小操作回数
 * ペーストでnを超える場合はその差の回数だけ削除するようにして遷移
 * nを超えるまでコピペしまくる作戦より途中で削除調整してぴったりnに届かせた方が得するケースもあるかもしれないけど、
 * n<=1000で100回も削除した方が得なことはなさそうだから適当に100回ループを回した
 * グラフで考えてBFSとかダイクストラが想定解らしい
 */

class EmoticonsDiv1 {
	public:
	int printSmiles(int n) {
		int dp[1010][1010];
		rept(i,n) rept(j,n) dp[i][j] = inf;
		dp[1][1] = 1;
		rep(k,100) reps(i,1,n) repst(j,1,i) {
			if (dp[i][j]==inf) continue;
			chmin(dp[i][i], dp[i][j] + 1);
			chmin(dp[i-1][j], dp[i][j] + 1);
			if (i+j<=n) chmin(dp[i+j][j], dp[i][j] + 1);
			else chmin(dp[n][j], dp[i][j] + 1 + (i+j-n));
		}
		return *min_element(dp[n], dp[n]+n);
	}
};