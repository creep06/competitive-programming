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
 * i番目のアラームはstart[i]秒目からperiod[i]秒ごとに鳴り、アレックス君の眠さをvolume[i]だけ減らす
 * 眠さは毎秒dだけ増えていく
 * アレックス君は眠さが0以下になった瞬間目を覚ます
 * いつかアレックス君が目を覚ますような眠さの初期値の最大値を求めよ
 *
 * (解法)
 * periodのLCMが周期になってる
 * 眠さを0とおいて1周期分シミュレートしてみて、トータルがマイナスの場合は周期ごとに眠さが単調減少するから眠さの初期値に関係なくいつか起きる
 * そうじゃない場合は1周期目の中の眠さの最小値*(-1)が答え 眠さの初期値がそれより1でも大きいとアレックスは永眠する
 */

class WakingUp {
	public:
	int maxSleepiness(vi p, vi s, vi v, int d) {
		int n = p.size();
		ll lcm = 1;
		each(i,p) lcm = lcm*i/__gcd(lcm,(ll)i);
		ll sum = 0, res = 0;
		repst(i,1,lcm) {
			rep(j,n) if (s[j]<=i && (i-s[j])%p[j]==0) sum -= v[j];
			sum += d;
			chmin(res,sum);
		}
		if (sum<0) return -1;
		return -res;
	}
};