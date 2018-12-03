#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
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
#define log2(x) log(x)/log(2)
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
 *
 *
 * (解法)
 * アリスの最高得点はbの目がa回連続で出たときのa*bで、ボブの最低得点は1の目がc回出たときのc
 * だからとりあえずa*b<=cのときはアリスは勝ちようがない そうじゃないときについて考える
 * dp[i][j]: b面のダイスをi回振って目の総和がjになる確率 同様にdp2はd面のダイスを〜確率
 * (アリスがx点で試合に勝つ確率) = Σ(ボブがk点(1<=k<=x-1)である確率) * (アリスがx点である確率)
 * この式で期待値を求めればいい
 *
 * (反省)
 * アリスが試合に勝ってるって情報があるときの確率をどう求めればいいか考えてて混乱して解けなかった
 * ↓参考↓
 * http://kmjp.hatenablog.jp/entry/2014/06/29/0900
 */

class FixedDiceGameDiv1 {
	public:
	double getExpectation(int a, int b, int c, int d) {
		if (a*b<=c) return -1;
		double dp[55][2600] = {}, dp2[55][2600] = {};
		dp[0][0] = dp2[0][0] = 1;
		rep(i,a) rept(j,2500) repst(k,1,b) dp[i+1][j+k] += dp[i][j]/b;
		rep(i,c) rept(j,2500) repst(k,1,d) dp2[i+1][j+k] += dp2[i][j]/b;
		
		double num = 0, den = 0;
		rept(i,2500) {
			double w = 0;
			rep(j,i) w += dp2[c][j];
			num += i * dp[a][i] * w;
			den += dp[a][i] * w;
		}
		return num/den;
	}
};