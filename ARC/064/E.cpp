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

int n;
double xs, ys, xt, yt, x[1234], y[1234], r[1234], d[1234], cost;
vector<pair<int,double>> g[1234];

void dijkstra(int s) {
	priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> que;
	fill(d, d+n, 1e20);
	d[s] = 0.0;
	que.push(make_pair(0.0,s));
	
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
	cin >> xs >> ys >> xt >> yt >> n;
	repst(i,1,n) cin >> x[i] >> y[i] >> r[i];
	x[0] = xs, y[0] = ys, x[n+1] = xt, y[n+1] = yt;
	n += 2;
	rep(i,n) {
		rep(j,n) {
			if (i==j) continue;
			cost = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])) - (r[i]+r[j]);
			chmax(cost, 0.0);
			g[i].pb({j, cost}), g[j].pb({i, cost});
		}
	}
	dijkstra(0);
	printf("%.10lf\n",d[n-1]);
}