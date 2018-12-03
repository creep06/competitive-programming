#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(ll (i)=(n);(i)>=(t);--(i))
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

// dp[i][j]: 頂点iで終わるパスの中で文字jが出てくる最大値
// これをトポロジカル順に沿って更新すればいい

int n, m, a, b, dp[300300][30], r;
vi e[300300];
string s;

struct tsort {
	vector<vector<int>> E; tsort(int N) { E.resize(N); }
	void add(int a, int b) { E[a].push_back(b); }
	bool visit(int v, vector<int>& order, vector<int>& color) { color[v] = 1;
		for (int u : E[v]) { if (color[u] == 2) continue; if (color[u] == 1) return false;
			if (!visit(u, order, color)) return false; } order.push_back(v); color[v] = 2; return true; }
	bool sort(vector<int> &order) { int n = E.size(); vector<int> color(n);
		for (int u = 0; u < n; u++) if (!color[u] && !visit(u, order, color)) return false;
		reverse(order.begin(), order.end()); return true; }
};

signed main() {
	cin >> n >> m >> s;
	tsort ts(n);
	rep(i,m) {
		cin >> a >> b;
		a--, b--;
		ts.add(a,b);
		e[a].pb(b);
	}
	vi ord(n);
	rep(i,n) ord[i] = i;
	if (!ts.sort(ord)) return cout << -1 << ln, 0;
	rep(i,n) dp[i][s[i]-'a']++;
	each(i,ord) {
		each(j,e[i]) {
			int c = s[j]-'a';
			rep(k,26) chmax(dp[j][k],dp[i][k]+(k==c));
		}
	}
	rep(i,n) rep(j,26) chmax(r,dp[i][j]);
	cout << r << ln;
}