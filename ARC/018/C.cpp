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

ll n, m, x, a, p, r;
pll so[1000000];

signed main() {
	cin >> n >> m >> x >> t >> p;
	t %= p;
	// x0以外全て同じ値になる場合
	if (t==0) {
		if (x>=p) cout << 2*(n-1) << ln;
		else cout << 0 << ln;
		return 0;
	}
	// まず普通に配置する
	rep(i,n*m) {
		// 成績でソートした後元々いた位置がわかるようにメモ
		so[i] = {x, i};
		x = (x + t)%p;
	}
	// 成績順にソート
	sort(so, so+n*m);
	rep(i,n) {
		// i行目に来ないと行けない人たちが元々いた列の番号の集合
		ll mo[m];
		rep(j,m) {
			ll x = so[i*m+j].se/m, y = so[i*m+j].se%m;
			// 移動する必要のある行数
			r += abs(x - i);
			mo[j] = y;
		}
		// なるべく横移動しなくて済むように配置
		sort(mo, mo+m);
		rep(j,m) r += abs(mo[j] - j);
	}
	cout << r << ln;
}