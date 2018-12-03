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

// dp[i][j][k]: 既にi枚目まで見て、j枚食べていて、現時点でのmaxを食べているか(bool) のときの最終的に条件を満たせる確率の最大値
double dp[1010][1010][2];
int N, K;

// 目の前にあるせんべいを食べるかどうかの判断は "そのせんべいが今まで見た中で一番大きいかどうか" だけに依存し、その確率は常に1/i
double rec(int n, int k, int f) {
	if (n==N) return f;
	double &r = dp[n][k][f];
	if (r!=-1) return r;
	// (i-1)/iの確率で最大値は更新されない この場合は明らかに食べるべきじゃない
	r = rec(n+1, k, f) * (1.*n / (n+1));
	// 1/iの確率で最大値更新 食べない場合と食べる場合を両方試す必要がある 大きい方を採用
	double t = rec(n+1, k, 0);
	if (k+1<=K) chmax(t, rec(n+1, k+1, 1));
	r += t / (n+1);
	return r;
}

signed main() {
	cin >> N >> K;
	rep(i,1010) rep(j,1010) rep(k,2) dp[i][j][k] = -1;
	printf("%.14lf\n",rec(0,0,0));
}