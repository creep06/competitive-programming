#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(ll (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,n+1)
#define repst(i,s,n) reps(i,s,n+1)
#define reprt(i,n,t) for(ll (i)=(n);(i)>=t;--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto (itr):(v))
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
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<n;++i){cout<<x[i]<<(i==n-1?'\n':' ');}}

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

// dp[i][j]: 頂点iを根とする部分木をj==0?白:黒で塗るときの1-jの頂点に書いてきた数字の総和の最小値

int n, p, x[1010], dp[1010][2];
vi c[1010];
bitset<5050> b;

void rec(int v) {
	// 葉はとりあえず1で塗っとく
	if (c[v].empty()) {
		dp[v][1] = x[v];
		return;
	}
	// 子の0の数字の和、1の数字の和
	int s0 = 0, s1 = 0;
	each(i,c[v]) {
		rec(i);
		s0 += dp[i][0], s1 += dp[i][1];
	}
	// 0の和がx[v]を超えているならそれはもうどうしようもない
	if (s0>x[v]) {
		cout << "IMPOSSIBLE" << ln;
		exit(0);
	}
	// 部分和DP
	b = 1;
	each(i,c[v]) b |= (b << (dp[i][1]-dp[i][0]));
	int l = x[v]-s0;
	while (l>=0 && !b[l]) l--;
	dp[v][0] = x[v], dp[v][1] = s1-l;
	// 今まで塗ってきた黒と白は入れ替えても問題ない 便宜上黒の方が和が大きいようにしておく
	if (dp[v][0]>dp[v][1]) swap(dp[v][0],dp[v][1]);
}

signed main() {
	cin >> n;
	reps(i,1,n) {
		cin >> p;
		c[p-1].pb(i);
	}
	rep(i,n) cin >> x[i];
	rec(0);
	cout << "POSSIBLE" << ln;
}