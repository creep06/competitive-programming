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

int n, a, b;
vector<vi> m(100000);
ll dpf[100000], dpg[100000], f(int x, int p), g(int x, int p);

// xを親とする部分木に含まれる頂点を、両端が黒にならないように白か黒で塗る組み合わせの数
// pはxの親を表す 親に戻ってループしないように
ll f(int x, int p) {
	if (dpf[x]>0) return dpf[x];
	ll white = g(x,p);
	ll black = 1;
	rep(i,m[x].size()) {
		int to = m[x][i];
		if (to==p) continue;
		black = (black * g(to, x))%mod;
	}
	return dpf[x] = (white + black)%mod;
}

// 頂点pを黒に塗っていてxが白でないといけない場合のxを親とする部分木の塗り方
ll g(int x, int p) {
	if (dpg[x]>0) return dpg[x];
	ll cnt = 1;
	rep(i,m[x].size()) {
		int to = m[x][i];
		if (to==p) continue;
		cnt = (cnt * f(to, x))%mod;
	}
	return dpg[x] = cnt;
}

int main() {
	cin >> n;
	rep(i,n-1) {
		cin >> a >> b;
		a--, b--;
		m[a].pb(b), m[b].pb(a);
	}
	
	/*
	 * treeDPってやつらしい ↓のスライドがすごくわかりやすかった
	 * http://keita-matsushita.hatenablog.com/entry/2016/12/30/180918
	 * まずf(0,-1)が木全体の塗り方の総数(求めたい答え)を表す
	 * 例えば0から頂点1,2,3に辺が伸びているとすると、f(0,-1)は各部分木(0-1-..、0-2-..、0-3-..と続く3つ)の
	 * (0を黒に塗った場合のこの部分木の他の頂点の塗り方の総数) + (0を白に塗った場合の...)
	 * の和で求められる 前者の場合0と隣接している頂点は絶対白で塗る必要があるのでg(to,0)で表せる
	 * 後者だと0と隣接している頂点は白で塗っても黒で塗ってもいいのでf(to,0)
	 * ってことでf(0,-1) = f(1,0)+f(2,0)+f(3,0) + g(1,0)+g(2,0)+g(3,0)となる
	 * これを再帰で繰り返して木全体を探索すればいい
	 */
	
	ll ans = f(0, -1);
	cout << ans << ln;
}