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

int n, m, r, t, a, b, c, d[2525], ans;
vector<pii> g[2525];

void dijkstra(int s) {
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
	fill(d, d+n, inf);
	d[s] = 0;
	que.push(make_pair(0,s));
	
	while(!que.empty()) {
		pair<int,int> p = que.top(); que.pop();
		int v = p.second, dis = p.first;
		if (d[v]<dis) continue;
		for (int i = 0; i < g[v].size(); ++i) {
			int to = g[v][i].first, cost = g[v][i].second;
			if (d[to] > d[v] + cost) {
				d[to] = d[v] + cost;
				que.push(make_pair(d[to], to));
			}
		}
	}
}

signed main() {
	cin >> n >> m >> r >> t;
	rep(i,m) {
		cin >> a >> b >> c;
		a--, b--;
		g[a].pb({b,c}), g[b].pb({a,c});
	}
	// 目的地をkに定めて全点への最短距離を計算
	rep(k,n) {
		dijkstra(k);
		sort(d, d+n);
		// 亀のスタート地点をiに定める
		// iからkの距離をd、ウサギのスタート地点からkの距離をeとすると、d/t < e/rが成り立てばいい
		// つまりe > dr/tを満たすeの個数が求める答え 二分探索でok
		reps(i,1,n) {
			double s = 1.*d[i]*r / t;
			int tmp = upper_bound(d, d+n, s) - d;
			// 亀と同じ点はウサギの始点に選べないので2重カウントしてるときは取り除く
			ans += n - tmp - (tmp<=i);
		}
	}
	cout << ans << ln;
}