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

int n, m, s, t, a[200000], b[200000], c[200000], d[100000], dr[100000], dps[100000], dpt[100000], ans;
vector<pii> e[100000];
pii sd[100000], td[100000];

void dijkstra(int s, vector<pair<int,int>> g[], int *d, int *dp) {
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
	fill(d, d+n, linf);
	d[s] = 0;
	dp[s] = 1;
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
				dp[to] = dp[v]%mod;
			} else if (d[to] == d[v] + cost) {
				dp[to] = (dp[to] + dp[v]) %mod;
			}
		}
	}
}

signed main() {
	cin >> n >> m >> s >> t;
	s--, t--;
	rep(i,m) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
		e[a[i]].pb({b[i],c[i]});
		e[b[i]].pb({a[i],c[i]});
	}
	// sからの最短距離を全点について求めれば、頂点uからvに最短で行くために辺(v,u)を使っていいかどうかはd[u]==d[v]+cost[v][u]?でわかる
	// sからvへの行き方をdps[v]、vからtへの行き方をdpt[v]とする
	dijkstra(s, e, d, dps);
	dijkstra(t, e, dr, dpt);
	// 2人が途中で出会うようなものも含めた最短路の選び方の組
	ans = dps[t]*dps[t] %mod;
	// tへの距離の半分
	double half = d[t]/2.0;
	rep(i,n) {
		// 2人が頂点上で出会うような最短路の選び方の組
		if (d[i] == half) {
			int tmp = dps[i]*dpt[i]%mod;
			ans = (ans + mod - tmp*tmp%mod) %mod;
		}
		// 2人が辺上で出会うような最短路の選び方の組
		each(it,e[i]) {
			int j = it.fi, co = it.se;
			if (d[i]+co+dr[j] != d[t]) continue;
			if (d[i]<half && d[j]>half) {
				int tmp = dps[i]*dpt[j]%mod;
				ans = (ans + mod - tmp*tmp%mod) %mod;
			}
		}
	}
	cout << ans << ln;
}