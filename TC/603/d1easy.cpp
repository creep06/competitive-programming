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
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<n;++i){cout<<x[i]<<(i==n-1?'\n':' ');}}

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
 * 木を使って2人がゲームをする
 * 2人は交互に"取り除くことで木の成分を2分するような辺(∴ 橋)"を1つ選び、その後2分された成分のうち片方を残し、他方を消す
 * 最後に残った1つの頂点の重みをゲームのスコアとし、先攻はそれを最大化、後攻は最小化したい
 * お互いが最善の動きをしたときのスコアを求めよ
 *
 * (解法)
 * 次数1の点のコストの最大値が答え なぜかというと、
 * まず(次数1の点のコストの最大値) >= (次数2以上の点のコストの最大値) のときは明らか
 * そうでないとき 次数1の点は必ず2個以上存在するため、先攻が何をしても次のターンに後攻がスコアを
 * それらのコストのうちの最小値に確定させられる だから初期状態で取れるコストの最大値にスコアを確定させてしまうのが最善
 */

class MaxMinTreeGame {
	public:
	int findend(vi edges, vi costs) {
		int n = costs.size();
		vi e[n];
		rep(i,n-1) e[i+1].pb(edges[i]), e[edges[i]].pb(i+1);
		int res = 0;
		rep(i,n) if (e[i].size()==1) chmax(res,costs[i]);
		return res;
	}
};