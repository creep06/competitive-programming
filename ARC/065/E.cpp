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

// a,b間のマンハッタン距離をkとおくと
// "頂点aからスタートしてマンハッタン距離kの点に辺を引いて進めるとき、最大何本辺を引けるか" って問題に言い換えられる
// 45度回転してあるから、頂点vからマンハッタン距離がkの点ってのはvを中心とした1辺の長さ2kの正方形の周上の点全て

int n, a, b;
ll x[114514], y[114514], k, res;
map<ll,vector<pair<ll,int>>> u, d;
map<ll,set<pair<ll,int>>> us, ds;

void rec(int c) {
	//cout << c << "にいます！" << ln;
	// 45度回転後のx,y
	ll ud = y[c]-x[c], dd = y[c]+x[c];
	// 頂点cを使用済みにする(setから削除)
	us[ud].erase({x[c],c});
	ds[dd].erase({x[c],c});
	// 頂点cから距離kの点の数をカウント 正方形の4辺に対応
	res += lower_bound(all(u[ud+k]), mp(x[c],0)) - lower_bound(all(u[ud+k]), mp(x[c]-k,0));
	res += lower_bound(all(d[dd+k]), mp(x[c]+k+1,0)) - lower_bound(all(d[dd+k]), mp(x[c],0));
	res += lower_bound(all(u[ud-k]), mp(x[c]+k,0)) - lower_bound(all(u[ud-k]), mp(x[c],0));
	res += lower_bound(all(d[dd-k]), mp(x[c],0)) - lower_bound(all(d[dd-k]), mp(x[c]-k+1,0));
	//cout << res << ln;
	// ⇡のうちまだ探索していない点に移動して同様のことをする
	while (true) {
		auto it = us[ud+k].lower_bound({x[c]-k,0});
		if (it==us[ud+k].end() || it->fi > x[c]) break;
		rec(it->se);
	}
	while (true) {
		auto it = us[ud-k].lower_bound({x[c],0});
		if (it==us[ud-k].end() || it->fi > x[c]+k) break;
		rec(it->se);
	}
	while (true) {
		auto it = ds[dd+k].lower_bound({x[c],0});
		if (it==ds[dd+k].end() || it->fi > x[c]+k) break;
		rec(it->se);
	}
	while (true) {
		auto it = ds[dd-k].lower_bound({x[c]-k,0});
		if (it==ds[dd-k].end() || it->fi > x[c]) break;
		rec(it->se);
	}
}

signed main() {
	cin >> n >> a >> b;
	a--, b--;
	rep(i,n) {
		cin >> x[i] >> y[i];
		// 45度回転 (倍率==2点間の距離は変わる)
		u[y[i]-x[i]].pb({x[i],i});
		d[y[i]+x[i]].pb({x[i],i});
		us[y[i]-x[i]].insert({x[i],i});
		ds[y[i]+x[i]].insert({x[i],i});
	}
	k = abs(x[a]-x[b]) + abs(y[a]-y[b]);
	each(i,u) sort(all(i.se));
	each(i,d) sort(all(i.se));
	rec(a);
	// recでは各頂点について自身とk離れた点の数を数え上げているので2重にカウントしている
	cout << res/2 << ln;
}