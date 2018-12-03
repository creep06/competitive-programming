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
#define show(x) cout << #x << " = " << x ln
#define dbg(x) cout<<#x"="<<x ln

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > mat;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
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

int h, w, n, a[100000], ans[100][100];
bool us[100][100];

int main() {
	cin >> h >> w >> n;
	rep(i,n) cin >> a[i];
	
	// 左上から始まって壁にぶつかる度にぐるぐる回りながら真ん中に進めば絶対途切れない
	// と思ったけどSを描くように反復横跳びしながら下に進んでくだけでよかった 実装略
	int i = 0, j = 0, x = 0, y = 0, d = 0;
	while (i<n) {
		// 答えの配列を埋める
		ans[x][y] = i+1;
		// iのj個目を埋めました
		j++;
		// iをa[i]個全部埋めたなら次の要素(i+1)に移る
		if (j==a[i]) i++, j = 0;
		// 壁を作っとく
		us[x][y] = true;
		// 盤からはみ出そう/壁に当たりそうな場合方向を90度回転
		if ((x+dx[d]<0 || x+dx[d]>=w || y+dy[d]<0 || y+dy[d]>=h) || us[x+dx[d]][y+dy[d]]) d++;
		if (d==4) d = 0;
		// 前に1歩進む
		x += dx[d], y += dy[d];
	}
	rep(yy,h) rep(xx,w) cout << ans[xx][yy] << (xx==w-1 ? '\n' : ' ');
}