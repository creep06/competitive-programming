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

// dp[i][j][k][l]: 左下を(i,j) 右上を(k,l)とした長方形領域が残ったときの最適解
int w, h, n, dp[33][33][33][33];
vi x, y, xs, ys;

// https://image.slidesharecdn.com/abc008-140510085949-phpapp02/95/atcoder-beginner-contest-008-39-638.jpg
// ⇡こんな感じ 今考えてる範囲(最初は図の黄色い部分)の内側(境界は含まない!)の点全てについて最適解を求める
// https://drive.google.com/open?id=1WjIGEDAmzOEPnjycnOtTcsiOwUjga6gr
// ⇡入力例1の再帰のイメージ
// 左下の点の実際の座標はxs[x1],ys[y1]であることに注意
// recは'rec'ursionと'rec'tangleがかかってる(ﾜﾗ
int rec(int x1, int y1, int x2, int y2) {
	int &r = dp[x1][y1][x2][y2];
	if (r!=-1) return r;
	
	r = 0;
	rep(i,n) {
		// 範囲からはみ出してる点
		if (x[i]<=x1 || x2<=x[i] || y[i]<=y1 || y2<=y[i]) continue;
		// まずi番目のクレーンの上下左右(と真下)の金塊を全部拾う
		// ヨコ: xs[x1]+1, xs[x1]+2, ..., xs[x2]-1のxs[x2]-1 - xs[x1]個の金塊と
		// タテ: ys[y1]+1, ys[y1]+2, ..., ys[y2]-1のys[y2]-1 - ys[y1]個の金塊
		// を拾って、クレーンの足元の金塊が重複カウントされてるから-1 ってかんじ
		int t = xs[x2]-xs[x1] + ys[y2]-ys[y1] - 3;
		// 十字に拾ったので4つの新しい長方形のスペースが生まれる
		// それぞれのスペースの最適解を足してやればi番目の点を選択したときに得られる最大の金塊の数が求められる
		t += rec(x1, y1, x[i], y[i]);	// 左下の最適解を足す
		t += rec(x1, y[i], x[i], y2);	// 左上
		t += rec(x[i], y1, x2, y[i]);	// 右下
		t += rec(x[i], y[i], x2, y2);	// 右上
		chmax(r, t);
	}
	return r;
}

int main() {
	cin >> w >> h >> n;
	x.resize(n), y.resize(n);
	xs.resize(n+2), ys.resize(n+2);
	rep(i,n) {
		cin >> x[i] >> y[i];
		xs[i] = x[i], ys[i] = y[i];
	}
	// 両端を(0, 0)と(w+1, h+1)で囲んでおく
	// クレーンの座標は1..w, 1..hなので、これで座圧するとクレーンの座標n個が1..nのインデックスに入る
	// (0, 0, n+1, n+1)で再帰を始めることで左下(0,0)右上(w+1,h+1)を取れるようにしている
	xs[n] = w+1, ys[n] = h+1;
	// xs[n+1] = 0, ys[n+1] = 0;
	
	// 座標圧縮 x[i]をその値が配列xの中で何番目にでかいのかって情報に書き換える
	// ⇡で囲んでおいたので1..nになる
	sort(all(xs));
	sort(all(ys));
	xs.erase(unique(all(xs)), xs.end());
	ys.erase(unique(all(ys)), ys.end());
	rep(i,n) {
		x[i] = (int)(lower_bound(all(xs), x[i]) - xs.begin());
		y[i] = (int)(lower_bound(all(ys), y[i]) - ys.begin());
	}
	memset(dp, -1, sizeof(dp));
	cout << rec(0, 0, n+1, n+1) << ln;
}