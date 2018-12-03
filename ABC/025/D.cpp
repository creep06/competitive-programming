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

int a[25], sel[26], dp[1<<25], b, r, x, y;
vi emp;

int main() {
	rep(i,25) {
		cin >> a[i];
		if (a[i]) sel[a[i]] = i+1;
		else emp.pb(i);
	}
	
	/*
	 * 連続する3マスが昇順にも降順にもならないように25マス埋める埋め方の総数 を求めたい
	 * dp[S]: 数字の配置がSまで決まったときの配置の総数 下からiビット目が立っていれば盤面の左上からi番目の数字が決まってることを表す
	 * 1から順に埋めていくことにする するとb = __builtin_popcount(S)+1が次に埋めるべき数字になる
	 * もしsel[b]!=0なら既にbを置く位置が決められてるのでbの置き方は1通り
	 * そうでないなら空いている全てのマスについてbを置けるか考える
	 * そのマスの上下(左右も同様)のうちどちらかのみ既に埋まっている場合、
	 * そこにbを置いてしまうとその後いつかもう片方のマスにbより大きい数字を置いて昇順/降順になっちゃうので置けない
	 * 連続する3マスの大小関係は2個目の数字が置かれた時点で定まり、ダメなケースは必ず⇡こうなるので、
	 * 常にこのケースだけを避けながら配置していけばいい
	 */
	
	dp[0] = 1;
	rep(s,(1<<25)-1) {
		// このsに辿り着ける置き方が存在しなければスキップ
		if (!dp[s]) continue;
		b = __builtin_popcount(s) + 1;
		// 数字bを置く位置が指定されてる場合
		if (sel[b]) {
			// 指定されてる位置
			r = sel[b] - 1;
			if (s>>r & 1) continue;
			x = r%5, y = r/5;
			// 左右/上下のどちらかのみに数字が置かれてる場合 xor使うのがわかりやすい
			if (0<x && x<4 && (((s>>(r-1)) ^ (s>>(r+1))) & 1)) continue;
			if (0<y && y<4 && (((s>>(r-5)) ^ (s>>(r+5))) & 1)) continue;
			dp[s|(1<<r)] = (dp[s|(1<<r)] + dp[s]) % mod;
		} else {
			each(r,emp) {
				// 既にそのマスに数字を置いてある場合スキップ
				if (s>>r & 1) continue;
				x = r%5, y = r/5;
				if (0<x && x<4 && (((s>>(r-1)) ^ (s>>(r+1))) & 1)) continue;
				if (0<y && y<4 && (((s>>(r-5)) ^ (s>>(r+5))) & 1)) continue;
				dp[s|(1<<r)] = (dp[s|(1<<r)] + dp[s])%mod;
			}
		}
	}
	cout << dp[(1<<25)-1] << ln;
}