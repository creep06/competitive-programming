#include <bits/stdc++.h>
using namespace std;

#define int long long
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

const int inf = 1001001001;
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

// dp[i][j]: i日目までに勝率がj回上昇した場合の勝利数の最小値
int n, k, a[2000], dp[2020][2020], s, r;

signed main() {
	cin >> n >> k;
	rep(i,n) cin >> a[i];
	rept(i,n) fill(dp[i], dp[i]+n+1, inf);
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	s += a[0];
	reps(i,1,n) {
		// 今までs試合やってきてdp[i][j]勝してる 勝率はdp[i][j]/s これを越すためにはdp[i][j] * a[i] / s + 1回勝てばいい
		rept(j,i) {
			// i日目に勝率アップ
			if (dp[i][j] * a[i] / s + 1 <= a[i]) chmin(dp[i+1][j+1], dp[i][j] + (dp[i][j] * a[i] / s + 1));
			// i日目に勝率ダウン
			chmin(dp[i+1][j], dp[i][j]);
		}
		s += a[i];
	}
	if (s==k) r = 1;
	else rept(i,n) if (dp[n][i]<=k) r = i;
	cout << r << ln;
}