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

ll h, w, n, x, y, ans[10];
// 黒く塗った点の集合
map<pll,bool> m;
// 考慮すべき正方形の左上の座標全て
vector<pll> s;

int main() {
	cin >> h >> w >> n;
	rep(i,n) {
		cin >> y >> x;
		m[mp(x,y)] = true;
		// 点(x,y)を内側に含む正方形は最大9つ考えられる
		// 一番左上の正方形：(x,y)が正方形の右下になる位置
		// 一番右下の正方形：(x,y)が正方形の左上になる位置
		// 地図からはみ出すものは除外してそれぞれの正方形の左上の座標をsに追加しておく 最大9*10^5個
		rep(j,3) {
			rep(k,3) {
				ll xs = x-j, ys = y-k;
				if (1<=xs && xs+2<=w && 1<=ys && ys+2<=h) s.emplace_back(mp(xs, ys));
			}
		}
	}
	// 調べる必要がある正方形が↑で重複するので重複削除
	sort(all(s));
	s.erase(unique(all(s)), s.end());
	ans[0] = (h-2)*(w-2);
	// 上で追加した最大9*10^5個の正方形それぞれを構成している9マスを見ていく
	// その中で黒く塗られている点の数がjだったらans[0]を1個減らしてans[j]に持って来る
	rep(i,s.size()) {
		if (i!=0 && s[i]==s[i-1]) continue;
		int cnt = 0;
		rep(j,3) {
			rep(k,3) {
				if (m[mp(s[i].fi+j, s[i].se+k)]) cnt++;
			}
		}
		ans[0]--;
		ans[cnt]++;
	}
	rep(i,10) cout << ans[i] << ln;
}