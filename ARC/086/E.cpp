#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(ll (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto &(itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int> > mat;

const ll inf = (ll)1e9+10;
const ll linf = (ll)1e18+10;
const ll mod = (ll)(1e9+7);
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

/*
 * 同じ深さにある2頂点に同時に玉を置くとそれらはどこかで出会う
 * 頂点を根からの深さごとに分類し、各深さdについてtree dp
 * dp[i][j]: 頂点iを根とする部分木に着目したとき、頂点iにj(0or1)個の玉が置かれるような頂点0からの距離がdの頂点への玉の配置の数
 * を求めると答えは Σ dp[0][1]*2^(n-s[d]) (1<=d<=n) (s[d]:深さdにある頂点の数) O(n^2)で部分点
 * このdpには無駄な遷移が含まれる 例えばある頂点に玉が複数個来るためには子が2つ以上ある必要があるが⇡は1つの場合でも毎回計算している
 * 深さdについてdequeを使って管理し、サイズが小さい方を大きい方にマージするやり方でO(n)
 */

typedef deque<pair<pll,ll>> dq;
ll n, p, ans;
vi e[200200];

void rec(int v, dq &d) {
	dq m;
	each(i,e[v]) rec(i,m);
	if (e[v].size()>=2) {
		each(i,m) {
			(i.fi.fi += i.se) %= mod;
			i.se = 0;
		}
	}
	m.push_front({{1,1},0});
	if (d.size()<m.size()) d.swap(m);
	auto j = d.begin();
	each(i,m) {
		j->se = (j->se + j->fi.fi + j->fi.se) * (i.se + i.fi.fi + i.fi.se) %mod;
		j->fi.se = ((j->fi.se * i.fi.fi) + (j->fi.fi * i.fi.se)) %mod;
		j->fi.fi = (j->fi.fi * i.fi.fi) %mod;
		j->se = (j->se + mod - j->fi.fi + mod - j->fi.se) %mod;
		j++;
	}
}

signed main() {
	cin >> n;
	repst(i,1,n) {
		cin >> p;
		e[p].pb(i);
	}
	dq nw;
	rec(0,nw);
	ll t = 1;
	each(i,nw) {
		ans = (ans * (i.fi.fi + i.fi.se) + t * i.fi.se) %mod;
		t = t * (i.fi.fi + i.fi.se) %mod;
	}
	cout << ans << ln;
}