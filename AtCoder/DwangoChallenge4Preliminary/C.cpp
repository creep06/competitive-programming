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

int n, m, ka[101], kb[101], da, db, dv[2525][2525], A, B;
pii ksa[101], ksb[101];
int aa = 1, bb = 1;

int ans(pii *kill, int death, int group) {
	// dp[i][j]: i番目までのグループにjデス割り当てるときの組み合わせ数
	int dp[group+1][death+1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	rep(i,group) {
		rept(j,death) {
			rept(k,death-j) {
				// 今までjデス振り分けた状態から、i+1番目のグループにkデス振り分ける
				dp[i+1][j+k] = (dp[i+1][j+k] + dp[i][j]*dv[kill[i].se][k]) %mod;
				//cout << k << "デスを" << kill[i].se << "人に振り分ける組み合わせは" << dv[kill[i].se][k] << ln;
				//cout << "dp[" << i+1 << "][" << j+k << "] = " << dp[i+1][j+k] << ln;
			}
		}
	}
	return dp[group][death];
}

signed main() {
	cin >> n >> m;
	rep(i,n) {
		cin >> ka[i];
		db += ka[i];
	}
	rep(i,m) {
		cin >> kb[i];
		da += kb[i];
	}
	// キル数ごとにグループ分けしておく aa/bbがそれぞれA/Bチームのキル数のグループの数
	sort(ka, ka+n), sort(kb, kb+m);
	ksa[0] = {ka[0], 1}, ksb[0] = {kb[0], 1};
	reps(i,1,n) {
		if (ksa[aa - 1].fi != ka[i]) ksa[aa++] = {ka[i], 1};
		else ksa[aa-1].se++;
	}
	reps(i,1,m) {
		if (ksb[bb - 1].fi != kb[i]) ksb[bb++] = {kb[i], 1};
		else ksb[bb-1].se++;
	}
	// dv[i][j]: jのi分割の総数
	// 分割数のテーブルを事前に作っておく
	dv[0][0] = 1;
	repst(i,1,1919) rept(j,1919) {
		if (j>=i) dv[i][j] = (dv[i-1][j] + dv[i][j-i]) %mod;
		else dv[i][j] = dv[i-1][j];
	}
	// dpで答えを計算
	cout << (ans(ksa, da, aa) * ans(ksb, db, bb)) %mod << ln;
}