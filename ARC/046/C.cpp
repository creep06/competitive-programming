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

// a:男の収入 b:求める条件 c:女の年収 d:条件
int n, m, a[200200], b[200200], c[200200], d[200200], t, r;
vector<pii> e;
map<int,int> f;

signed main() {
	cin >> n >> m;
	e.resize(n+m);
	rep(i,n) {
		cin >> a[i] >> b[i];
		e[i] = {a[i], i+200000};
	}
	rep(i,m) {
		cin >> c[i] >> d[i];
		e[n+i] = {d[i], i};
	}
	// 男の収入aと女の条件dを混ぜてソート
	sort(all(e));
	// これでe[i]の男はe[0]〜e[i-1]の女全ての条件dを満たすことになる
	// あとは女の収入cが男の条件bを満たせばペアにできる
	// e[i]が女ならとりあえず待機室fに入れておく
	// e[i]が男なら待機室にいる中で年収がb以上で最も少ない女をあてがう
	rep(i,n+m) {
		t = e[i].se;
		if (t>=200000) {
			t -= 200000;
			auto k = f.lower_bound(b[t]);
			if (k!=f.end()) {
				r++;
				if (--k->se==0) f.erase(k);
			}
		} else f[c[t]]++;
	}
	cout << r << ln;
}