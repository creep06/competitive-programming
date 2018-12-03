#include <bits/stdc++.h>
using namespace std;

//#define int long long
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

int n, x[1000], y[1000], t[1000], r[1000];
double d[1000], ans;
vector<pair<int,double>> g[1000];

void dijkstra(int s) {
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
	fill(d, d+n, 1e100);
	d[s] = 0;
	que.push(make_pair(0,s));
	
	while(!que.empty()) {
		pair<double,int> p = que.top(); que.pop();
		int v = p.second;
		double dis = p.first;
		if (d[v]<dis) continue;
		for (int i = 0; i < g[v].size(); ++i) {
			int to = g[v][i].first;
			double cost = g[v][i].second;
			if (d[to] > d[v] + cost) {
				d[to] = d[v] + cost;
				que.push(make_pair(d[to], to));
			}
		}
	}
}

signed main() {
	cin >> n;
	// x座標、y座標、投げる速度の上限、受け取る速度の上限
	rep(i,n) cin >> x[i] >> y[i] >> t[i] >> r[i];
	// 点iからjへ行くコストは(距離) / min(t[i],r[j])
	// O(n^2)で辺を全部引いて大工酢虎
	rep(i,n) {
		rep(j,n) {
			if (i==j) continue;
			double dis = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
			double spd = min(t[i], r[j]);
			g[i].pb({j, dis/spd});
		}
	}
	dijkstra(0);
	// たこやき発射は1秒の間隔が空いているので、常に最短距離で投げる場合、同じ人がたこやきを2個以上持つような瞬間は存在しない
	// (逆に存在すると仮定すると、片方のたこ焼きが通ってきた経路は他方のたこ焼きが通ってきた経路より短いことになり最短距離に矛盾する)
	// だからそういう心配はしなくていい で遠い人から順に投げればいい
	sort(d, d+n);
	for (int i = n-1; i >= 1; --i) chmax(ans, d[i]+n-1-i);
	printf("%.10lf\n",ans);
}