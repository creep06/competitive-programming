#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
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
#define bln(i,n) (i==n-1?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
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

const int MAXV = 202;
class FordFulkerson {
	private:
	struct edge {int to, cap, rev;};
	vector<edge> g[MAXV];
	bool used[MAXV];
	public:
	// fromからtoへ向かう要領capの辺をグラフに追加する
	void add_edge(int from, int to, int cap) {
		g[from].pb((edge){to,cap,g[to].size()});
		g[to].pb((edge){from,0,g[from].size()-1});
	}
	// 増加パスをdfsで探す
	int dfs(int v, int t, int f) {
		if (v==t) return f;
		used[v] = true;
		rep(i,g[v].size()) {
			edge &e = g[v][i];
			if (!used[e.to] && e.cap>0) {
				int d = dfs(e.to,t,min(f,e.cap));
				if (d>0) {
					e.cap -= d;
					g[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	// sからtへの最大流を求める
	int getflow(int s, int t) {
		int flow = 0;
		while (true) {
			memset(used,0,sizeof(used));
			int f = dfs(s,t,inf);
			if (f==0) return flow;
			flow += f;
		}
	}
};

int n, a[100], b[100], c[100], d[100];
FordFulkerson f;

signed main() {
	cin >> n;
	rep(i,n) {
		cin >> a[i] >> b[i];
		f.add_edge(n*2,i,1);
	}
	rep(i,n) {
		cin >> c[i] >> d[i];
		f.add_edge(i+n,n*2+1,1);
		rep(j,n) if (a[j]<c[i] && b[j]<d[i]) f.add_edge(j,i+n,1);
	}
	cout << f.getflow(n*2,n*2+1) << ln;
}