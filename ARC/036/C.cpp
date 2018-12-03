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

// dp[i][j][k][l]: i文字目までで (0の数)-(1の数)の最小値・最大値・今の値がそれぞれj,k,l
// これだとO(nk^3)かかる
// j,kの差とlが同じ状態は1つにまとめてもその後問題ない
// dp[i][j][k]: i文字目までで (0の数)-(1の数)の最大値と最小値の差がj、今の値がkである状態の数
int n, K;
ll dp[300][300][300];
string s;

int rec(int id, int dif, int cur) {
	if (dif>K) return 0;
	if (id==n) return 1;
	int r = dp[id][dif][cur];
	if (r!=-1) return r;
	r = 0;
	
	// id文字目を1にするパターン
	if (s[id]!='0') {
		if (cur==dif) r += rec(id+1, dif+1, cur+1);
		else r += rec(id+1, dif, cur+1);
	}
	// id文字目を0にするパターン
	if (s[id]!='1') {
		if (cur==0) r += rec(id+1, dif+1, 0);
		else r += rec(id+1, dif, cur-1);
	}
	return dp[id][dif][cur] = r%mod;
}

signed main() {
	cin >> n >> K >> s;
	memset(dp, -1, sizeof(dp));
	cout << rec(0,0,0) << ln;
}