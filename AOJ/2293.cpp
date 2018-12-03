#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <string.h>
#include <numeric>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(i,v) for(auto &(i):(v))
#define eachr(i,v) for(auto &(i)=(v).rbegin();(i)!=(v).rend();(i)++)
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

//typedef complex<double> P;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
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

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m;for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
bool ool(int x,int y,int h,int w) {return((x<0)||(h<=x)||(y<0)||(w<=y));}
bool deq(double a,double b) {return abs(a-b)<eps;}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;



const int MAXV = 4040;
class MCF {
private:
	struct edge {int to, cap, cost, rev;};
	vector<edge> g[MAXV];
	int V, h[MAXV], dist[MAXV], prevv[MAXV], preve[MAXV];
public:
	// fromからtoへ向かう容量capコストcostの辺をグラフに追加する
	void add_edge(int from, int to, int cap, int cost) {
		g[from].push_back((edge){to, cap, cost, (int)g[to].size()});
		g[to].push_back((edge){from, 0, -cost, (int)g[from].size()-1});
	}
	// sからtへの流量fの最小費用流を求める (流せない場合は-1)
	int getflow(int s, int t, int f, int n) {
		V = n;
		int res = 0;
		fill(h, h+V, 0);
		if (0<f) {
			fill(h, h+V, 1<<30);
			h[s] = 0;
			while (1) {
				bool upd = 0;
				for (int i=0; i<V; i++) for (auto &e : g[i]) if (e.cap) {
					if (h[i]==(1<<30)) continue;
					if (h[e.to] > h[i]+e.cost) {
						h[e.to] = h[i] + e.cost;
						upd = 1;
					}
				}
				if (!upd) break;
			}
		}
		while (0<f) {
			priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > que;
			fill(dist, dist+V, 1<<30);
			dist[s] = 0;
			que.push({0,s});
			while (!que.empty()) {
				pair<int,int> p = que.top(); que.pop();
				int v = p.second;
				if (dist[v]<p.first) continue;
				for (int i=0; i<g[v].size(); i++) {
					edge &e = g[v][i];
					if (0<e.cap && dist[e.to] > dist[v]+e.cost+h[v]-h[e.to]) {
						dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
						prevv[e.to] = v, preve[e.to] = i;
						que.push({dist[e.to], e.to});
					}
				}
			}
			if (dist[t]==(1<<30)) return -1;
			for (int v=0; v<V; v++) h[v] += dist[v];
			int d = f;
			for (int v=t; v!=s; v=prevv[v]) d = min(d, g[prevv[v]][preve[v]].cap);
			f -= d;
			res += d*h[t];
			for (int v=t; v!=s; v=prevv[v]) {
				edge &e = g[prevv[v]][preve[v]];
				e.cap -= d;
				g[v][e.rev].cap += d;
			}
		}
		return res;
	}
};

int n, a[1010], b[1010], id = 1;
map<int,int> m;
MCF mcf;

signed main() {
	cin >> n;
	rep(i,n) {
		cin >> a[i] >> b[i];
		if (!m[a[i]]) m[a[i]] = id++;
		if (!m[b[i]]) m[b[i]] = id++;
	}
	reps(i,1,id) mcf.add_edge(0,i,1,0);
	rep(i,n) {
		mcf.add_edge(m[a[i]],id+i,1,-b[i]);
		mcf.add_edge(m[b[i]],id+i,1,-a[i]);
		mcf.add_edge(id+i,id+n,1,0);
	}
	mcf.add_edge(0,id+n,n,0);
	cout << -mcf.getflow(0,id+n,n,id+n+1) << endl;
}
