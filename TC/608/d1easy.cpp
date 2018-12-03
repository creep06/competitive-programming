#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(ll (i)=(n);(i)>=(t);--(i))
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
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

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

/*
 * (問題)
 * i番目の箱にはアメがlow[i]からhigh[i]個入っていて、全ての箱の中のアメの合計はc個であるとき、
 * 確実にx個以上のアメを入手するために開ける必要のある箱の個数の最小値を求めよ
 *
 * (解法)
 * lowの総和をslとすると、各箱にはlow[i]に加えてc-sl個のアメのうちのいくつかが入っていることになる
 * 仮にいくつかの箱を選んだとき、最悪のケースは、残りの箱にc-slが最大限入っているような状態
 * 例えばex2ではc-sl == 58-45 == 13個のアメが浮いていて、2,4番目の箱を選んだとき、
 * 残りの0,1,3番目の箱のhigh-lowの総和は10だから、最低でも13-10 == 3個は確実に選んだ箱のどちらかに入っている
 * low[2]+low[4]+3 == 30 == xだから2個でOK っていう流れ
 * lowが大きいほど確実に得られるアメは多いけどhighが大きくても結果として流れてくるアメの個数は増える
 * どういう優先順位で選べばいいのかわからなかった lowの降順でやるとex4がWAになる
 *
 * -> lowの降順とhighの降順を両方別々にやってminを採用すればいいらしい
 */

class MysticAndCandies {
	public:
	int minBoxes(int c, int x, vi low, vi high) {
		int n = low.size(), sl = accumulate(all(low), 0), res = inf;
		vpii pl(n), ph(n);
		rep(i,n) pl[i] = {low[i], high[i]}, ph[i] = {high[i], low[i]};
		sort(pl.rbegin(), pl.rend()), sort(ph.rbegin(), ph.rend());
		// lowの降順
		rep(i,n) {
			int sum = 0, dif = 0;
			rept(j,i) sum += pl[j].fi;
			reps(j,i+1,n) dif += pl[j].se - pl[j].fi;
			if (sum + max(0, c-sl-dif) >= x) {
				res = i+1;
				break;
			}
		}
		// highの降順
		rep(i,res-1) {
			int sum = 0, dif = 0;
			rept(j,i) sum += ph[j].se;
			reps(j,i+1,n) dif += ph[j].fi - ph[j].se;
			if (sum + max(0, c-sl-dif) >= x) {
				res = i+1;
				break;
			}
		}
		return res;
	}
};