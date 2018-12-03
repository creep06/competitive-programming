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
#define rall(c) (c).rbegin(),(c).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define bln(i,n) (((i)==(n)-1)?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln<<flush
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ')<<flush;}}
#define zero(a) memset(a,0,sizeof(a))
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())

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

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m; assert(b>=0); for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

const int MAXV = 1010;
class FordFulkerson {
	private:
	struct edge {int to, cap, rev;};
	vector<edge> g[MAXV];
	bool used[MAXV];
	public:
	// fromからtoへ向かう要領capの辺をグラフに追加する
	void add_edge(int from, int to, int cap) {
		g[from].push_back((edge){to, cap, (int)g[to].size()});
		g[to].push_back((edge){from, 0, (int)g[from].size()-1});
	}
	// 増加パスをdfsで探す
	int dfs(int v, int t, int f) {
		if (v==t) return f;
		used[v] = true;
		for (int i = 0; i < g[v].size(); ++i) {
			edge &e = g[v][i];
			if (!used[e.to] && e.cap>0) {
				int d = dfs(e.to, t, min(f,e.cap));
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
			int f = dfs(s,t,(int)1e9+10);
			if (f==0) return flow;
			flow += f;
		}
	}
};

int n, m, b[505], r[505];

signed main() {
	while (1) {
		cin >> n >> m;
		if (n==0) break;
		FordFulkerson f;
		repst(i,1,n) {
			cin >> b[i];
			f.add_edge(0,i,1);
		}
		repst(i,1,m) {
			cin >> r[i];
			f.add_edge(n+i,n+m+1,1);
			repst(j,1,n) if (gcd(b[j],r[i])!=1) f.add_edge(j,n+i,1);
		}
		cout << f.getflow(0,n+m+1) << ln;
	}
}