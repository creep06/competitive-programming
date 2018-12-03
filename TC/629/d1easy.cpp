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
 * 四角形の穴を↓のルールに従っていくつかの四角形の板で完全に埋めたい
 * ・板は重なってもいい (けど重ねて得することはない)
 * ・板は90度回転してもOK
 * ・全ての板の4頂点は穴の内側(境界線も含む)にあってはいけない
 * 使う必要のある板の枚数の最小値を求めよ (どうやっても穴を塞げない場合は-1)
 *
 * (解法)
 * dp[i][j]: i番目まででヨコ幅がw+1以上ある板をタテにj枚並べたときカバーできる高さの最大値
 * これを求めて、dp[n][i]>=hを満たすiの最小値が答え (存在しなければ-1)
 * 板をタテに並べていくパターンの他にヨコに並べていったほうがいいパターンもあるからhとwを入れ替えて2回やる
 * (例えば1,100のヨコに超長い穴に対して50,50の板2枚の場合とか)
 * 脳死でdpしたけどちょっとググった感じソートして大きい順に何個取れば和がh以上になるかって解き方の方が多そう どっちでもいい
 */

class RectangleCovering {
	public:
	
	int sub(int h, int w, vi hs, vi ws) {
		int n = hs.size();
		ll dp[55][55];
		memset(dp,-1,sizeof(dp));
		dp[0][0] = 0;
		rep(i,n) rep(j,n) {
			if (dp[i][j]==-1) continue;
			chmax(dp[i+1][j], dp[i][j]);
			int mx = 0;
			if (w+1<=hs[i]) chmax(mx,ws[i]);
			if (w+1<=ws[i]) chmax(mx,hs[i]);
			if (mx==0) continue;
			chmax(dp[i+1][j+1], dp[i][j] + mx);
		}
		int res = inf;
		rept(i,n) if (h<=dp[n][i]) chmin(res,i);
		return res;
	}
	
	int minimumNumber(int h, int w, vi hs, vi ws) {
		int res = min(sub(h,w,hs,ws), sub(w,h,hs,ws));
		return res==inf ? -1 : res;
	}
};