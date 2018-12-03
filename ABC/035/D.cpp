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

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

ll n, m, t, a[100000], x, y, z;
// 辺と逆辺 後者を使って各頂点から原点へ戻る最短距離が求められる
vector<vector<pll>> m(100000), er(100000);
// それぞれ 原点から各頂点への最短距離、各頂点から原点への最短距離
// 全ての頂点について(t-(d[i]+dr[i]))*a[i]で答えを更新すればいい
ll d[100000], dr[100000];

int main() {
	cin >> n >> m >> t;
	rep(i,n) cin >> a[i];
	rep(i,m) {
		cin >> x >> y >> z;
		x--, y--;
		m[x].emplace_back(mp(y,z));
		er[y].emplace_back(mp(x,z));
	}
	
	priority_queue<pll, vector<pll>, greater<>> que;
	fill(d, d+n, inf);
	fill(dr, dr+n, inf);
	d[0] = dr[0] = 0;
	// 順方向の最短距離
	que.push(mp(0,0));
	while(!que.empty()) {
		pll p = que.top(); que.pop();
		ll dis = p.fi;
		ll v = p.se;
		if (d[v]<dis) continue;
		for (int i = 0; i < m[v].size(); ++i) {
			ll to = m[v][i].fi;
			ll cost = m[v][i].se;
			if (d[to] > d[v] + cost) {
				d[to] = d[v] + cost;
				que.push(mp(d[to], to));
			}
		}
	}
	// 逆方向の最短距離
	que.push(mp(0,0));
	while(!que.empty()) {
		pll p = que.top(); que.pop();
		ll dis = p.fi;
		ll v = p.se;
		if (dr[v]<dis) continue;
		for (int i = 0; i < er[v].size(); ++i) {
			ll to = er[v][i].fi;
			ll cost = er[v][i].se;
			if (dr[to] > dr[v] + cost) {
				dr[to] = dr[v] + cost;
				que.push(mp(dr[to], to));
			}
		}
	}
	ll ans = 0;
	rep(i,n) chmax(ans, (t-(d[i]+dr[i]))*a[i]);
	cout << ans << ln;
}