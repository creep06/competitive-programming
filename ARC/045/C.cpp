#include <bits/stdc++.h>
using namespace std;

#define int long long
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

int n, x, a, b, c, xo[100000], r;
vector<pii> e[100000];
map<int,int> xoxo;
bool us[100000];

void rec(int v, int t) {
	us[v] = true;
	xo[v] = t;
	each(i,e[v]) if (!us[i.fi]) rec(i.fi, t^(i.se));
}

signed main() {
	cin >> n >> x;
	rep(i,n-1) {
		cin >> a >> b >> c;
		a--, b--;
		e[a].pb({b,c}), e[b].pb({a,c});
	}
	// 頂点0からスタートして各点まで辺のコストのxor和をとりつつ進み、各点でそれを記録しておく
	// 頂点a,b間のパス上の辺のコストのxor和はa->0->bって経路の時と等しい (∵同じ辺を2度通るならそれらのコストのxorは打ち消し合うため)
	// でxor和がiの経路がj個、x^iの経路がl個あったとすると組み合わせはj*l通りあるって感じ
	// xが0のときはi==x^iだから自分自身を2重にカウントしないように j個あるなら選び方は(j-1)*j/2通り
	rec(0,0);
	rep(i,n) xoxo[xo[i]]++;
	if (x==0) each(i,xoxo) r += (i.se-1) * i.se / 2;
	else {
		each(i,xoxo) r += i.se * xoxo[x^(i.fi)];
		// (i, x^i)と(x^i, i)で2重カウントしてるので
		r /= 2;
	}
	cout << r << ln;
}