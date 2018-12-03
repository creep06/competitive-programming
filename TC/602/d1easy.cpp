#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
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
 * レート2200未満はciel、2200以上はbrownという色がつく
 * コンテストiでは勝つとレートがd[i]増え、負けるとd[i]減る (0未満にはならない)
 * 各コンテストで勝ち負けを自由に選べるとき最大で何回色を変えられるか求めよ
 * ただし2回続けてbrownの状態を維持してはならない
 * ∴ コンテストi終了後にレートが2200以上になった場合コンテストi+1終了後には必ず2200未満になってないといけない
 *
 * (解法)
 * dp[i][j]: i番目のコンテスト終了時にレートがjであるときの色の変化回数の最大値 (そういう状態が存在しない場合は-1)
 * レートが2200以上になった次の回ですぐ2200を切らないといけないって制約から、状態は2199まで保持すれば十分
 * dpの遷移は、とりあえずi番目のコンテストに負ける場合は普通に dp[i+1][max(0,j-d[i])] = dp[i][j]
 * 勝ってもcianのままなら dp[i+1][j+d[i]] = dp[i][j]
 * 勝つとbrownになる場合、次のコンテストで負けてすぐcianに戻れるなら dp[i+2][j+d[i]-d[i+1] = d[i][j]+2
 * こんな感じで2個先に飛ぶ ただし次のコンテストが存在しない場合(i==n-1)だけは何も考えずに勝っていい
 */

class TypoCoderDiv1 {
	public:
	int getmax(vi d, int x) {
		int n = d.size(), dp[55][2222];
		memset(dp,-1,sizeof(dp));
		dp[0][x] = 0;
		rep(i,n) rep(j,2200) {
			if (dp[i][j]==-1) continue;
			chmax(dp[i+1][max(0,j-d[i])], dp[i][j]);
			if (j+d[i]<2200) chmax(dp[i+1][j+d[i]], dp[i][j]);
			else {
				if (i==n-1) chmax(dp[i+1][j], dp[i][j] + 1);
				else if (j+d[i]-d[i+1]<2200) chmax(dp[i+2][max(0,j+d[i]-d[i+1])], dp[i][j] + 2);
			}
		}
		return *max_element(dp[n],dp[n]+2200);
	}
};