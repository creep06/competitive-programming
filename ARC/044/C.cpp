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

// タテとヨコのビームはそれぞれ独立に考えていい
// 最善のヨコ移動ができる行と最善のタテ移動ができる列をそれぞれ調べて結果を足し合わせるだけ
int w, h, q, t, d, x, y;
// qs[時間] = ビームの座標
map<int,vi> hq, wq;

int ans(int l, map<int,vi> &qs) {
	vi xs(l);
	each(Q,qs) {
		vi &bm = Q.se;
		sort(all(bm));
		// 右に避ける
		rep(i,bm.size()) if (bm[i]+1<l) chmin(xs[bm[i]+1], xs[bm[i]]+1);
		// 左に避ける
		repr(i,bm.size()-1) if (0<=bm[i]-1) chmin(xs[bm[i]-1], xs[bm[i]]+1);
		// この時刻にbm[i]にいるやつは助からない
		each(i,bm) xs[i] = inf;
	}
	return *min_element(all(xs));
}

signed main() {
	cin >> w >> h >> q;
	rep(i,q) {
		cin >> t >> d >> x;
		x--;
		(d ? hq : wq)[t].pb(x);
	}
	y = ans(h,hq), x = ans(w,wq);
	cout << ((x==inf || y==inf) ? -1 : x+y) << ln;
}