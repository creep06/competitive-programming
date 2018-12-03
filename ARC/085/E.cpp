#include <bits/stdc++.h>
using namespace std;

#define int long long
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

// https://www.slideshare.net/shindannin/project-selection-problem
// ⇡参考 複数の選択肢があり、選択肢同士に依存関係もあるとき全体の費用/利益を最小/最大化する問題は最大フロー最小カットで解ける
// この問題の場合 "aが正の宝石だけ残し残りを全て破壊したとき貰える金額s" が理想値だが、
// 実際は倍数の宝石を壊さないといけない制約から理想値よりある程度減る可能性がある この減少量の最小値を最小カット==最大フローで求める
// a[i]>=0ならs->iに容量a[i]の辺、a[i]<0ならi->tに容量-a[i]の辺を引く
// s->iにフローが流れることは正の宝石を破壊すると和が減ることに、i->tに流れることは負の宝石を破壊しないと和が減ることに対応する
// これだけだと当然s->tが繋がらずフローは0 倍数破壊の制約に対応する辺を追加する必要がある
// これはj=2i,3i,...についてi->jに容量無限の辺を引くことで対応付けられる

int n, a[123], s;

const int MAXV = 123;
class FordFulkerson {
	private:
	struct edge {int to, cap, rev;};
	vector<edge> g[MAXV];
	bool used[MAXV];
	public:
	// fromからtoへ向かう容量capの辺をグラフに追加する
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
			int f = dfs(s,t,linf);
			if (f==0) return flow;
			flow += f;
		}
	}
};

signed main() {
	cin >> n;
	FordFulkerson ff;
	repst(i,1,n) {
		cin >> a[i];
		s += max(0ll,a[i]);
		if (a[i]<=0) ff.add_edge(0,i,-a[i]);
		else ff.add_edge(i,n+1,a[i]);
		for (int j = i*2; j <= n; j += i) ff.add_edge(i,j,linf);
	}
	cout << s - ff.getflow(0,n+1) << ln;
}