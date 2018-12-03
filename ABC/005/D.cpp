#include <bits/stdc++.h>
using namespace std;

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
#define ln "\n"
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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

int n, d[55][55], s[55][55], q, p, dl[2525];

int main() {
	cin >> n;
	rep(i,n) rep(j,n) cin >> d[i][j];
	
	// 2次元の累積和をとっておく 1-based
	repst(i,1,n) {
		s[i][1] = d[i-1][0] + s[i-1][1];
		s[1][i] = d[0][i-1] + s[1][i-1];
	}
	repst(i,2,n) repst(j,2,n) s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + d[i-1][j-1];
	
	// 1〜n^2個のたこ焼きが焼けるときのおいしさの最大値を事前に全部求めておく
	// サイズがタテiヨコjで右下の座標が(x,y)の長方形を全通り試す
	repst(x,1,n) repst(y,1,n) rept(i,n-x) rept(j,n-y) chmax(dl[x*y], s[x+i][y+j] + s[i][j] - s[x+i][j] - s[i][y+j]);
	
	// 4個選べるけど1*3の長方形で焼いたほうがいいみたいな場合もあるのでdl[i]をdl[1]〜dl[i-1]の最大値で更新しとく
	int mx = 0;
	repst(i,1,n*n) {
		chmax(mx, dl[i]);
		chmax(dl[i], mx);
	}
	
	cin >> q;
	rep(Q,q) {
		cin >> p;
		cout << dl[p] << ln;
	}
}