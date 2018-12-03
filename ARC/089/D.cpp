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

int n, k, x, y, imo[3333][3333], r;
char c;

int sum(int a, int b, int aa, int bb) {
	return imo[aa][bb] - imo[aa][b-1] - imo[a-1][bb] + imo[a-1][b-1];
}

signed main() {
	cin >> n >> k;
	// (x,y)が白である というのは (x+k,y)が黒である と置き換えられる
	// また (x+2ak,y+2bk)が黒である というのは (x,y)が黒である と置き換えられる
	rep(i,n) {
		cin >> x >> y >> c;
		if (c == 'W') x += k;
		x %= 2 * k, y %= 2 * k;
		imo[x+1][y+1]++;
	}
	// 累積和
	repst(i,1,2222) rept(j,2222) imo[i][j] += imo[i-1][j];
	repst(i,1,2222) rept(j,2222) imo[j][i] += imo[j][i-1];
	// 2k*2kのボードの中には最大で5個黒い四角形が入る(はみ出るやつも含めて)
	// その真ん中の正方形の左上の座標を(1,1)から(k,k)までk*k通り全部試せばいい
	repst(i,1,k) repst(j,1,k) {
		int tmp = 0;
		tmp += sum(i, j, i+k-1, j+k-1);
		tmp += sum(i+k, j+k, 2*k, 2*k);
		tmp += sum(1, 1, i-1, j-1);
		tmp += sum(i+k, 1, 2*k, j-1);
		tmp += sum(1, j+k, i-1, 2*k);
		// tmp個の条件を満たせるってことは白黒反転すればn-tmp個の条件を満たせることにもなる
		chmax(r, max(tmp, n-tmp));
	}
	cout << r << ln;
}