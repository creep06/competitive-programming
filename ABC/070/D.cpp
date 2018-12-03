#include <bits/stdc++.h>
using namespace std;

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
#define ln "\n"
#define show(x) cout << #x << " = " << x ln
#define dbg(x) cout<<#x"="<<x ln

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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;
struct edge {ll to, cost;};

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

ll n, a, b, c, q, k, x, y;
vector<edge> e[100000];
ll d[100000];

void Dijkstra(ll s) {
	priority_queue<pll, vector<pll>, greater<pll>> que;
	fill(d, d+n, linf);
	d[s] = 0;
	que.push(pll(0,s));
	
	while(!que.empty()) {
		pll p = que.top(); que.pop();
		ll v = p.second;
		if (d[v]<p.first) continue;
		for (ll i = 0; i < e[v].size(); ++i) {
			edge en = e[v][i];
			if (d[en.to] > d[v] + en.cost) {
				d[en.to] = d[v] + en.cost;
				que.push(pll(d[en.to], en.to));
			}
		}
	}
}

int main() {
	cin >> n;
	rep(i,n-1) {
		cin >> a >> b >> c;
		a--, b--;
		e[a].pb(edge{b, c});
		e[b].pb(edge{a, c});
	}
	cin >> q >> k;
	// kと全ての頂点の距離
	Dijkstra(k-1);
	rep(i,q) {
		cin >> x >> y;
		x--, y--;
		cout << d[x] + d[y] << ln;
	}
}