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
 * 種類と味が決まっているハンバーガーがある (食べた種類数)*(味の総和)を最大化せよ
 *
 * (解法)
 * ハンバーガーの味をタイプごとに分類し、"(分類後のインデックスで)i番目のタイプのハンバーガーを
 * 食うと決めたときに集められるtasteの最大値" s[i]も計算しておく
 * (基本的にうまいハンバーガーは全部食って、i番目のtypeのハンバーガーがどれもまずい場合は
 * その中で一番マシなやつを仕方なく1個だけ食って総type数をかさ増しする感じ)
 * で dp[i][j]: i番目まででj個のtypeを採用したときのtasteの合計の最大値 を計算してmax(j*dp[i][j])が答え
 */

class AlienAndHamburgers {
	public:
	int getNumber(vi type, vi taste) {
		int n = type.size();
		vpii sr(n);
		rep(i,n) sr[i] = {type[i], taste[i]};
		sort(all(sr));
		vi p[50];
		int m = 0;
		rep(i,n) {
			if (i==0 || sr[i].fi!=sr[i-1].fi) m++;
			p[m-1].pb(sr[i].se);
		}
		int s[50] = {};
		rep(i,m) {
			sort(p[i].rbegin(), p[i].rend());
			rep(j,p[i].size()) {
				if (j==0 || p[i][j]>0) s[i] += p[i][j];
				else break;
			}
		}
		
		int dp[51][51];
		rept(i,m) rept(j,m) dp[i][j] = -1<<25;
		dp[0][0] = 0;
		rep(i,m) rep(j,i+1) {
			chmax(dp[i+1][j], dp[i][j]);
			chmax(dp[i+1][j+1], dp[i][j] + s[i]);
		}
		int res = 0;
		rept(i,m) chmax(res, dp[m][i]*i);
		return res;
	}
};