#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(ll (i)=(n);(i)>=(t);--(i))
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
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

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

struct union_find {
	vector<int> p;
	union_find(int n) : p(n, -1) {};
	bool unite(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return false;
		if (p[u] > p[v]) swap(u, v);
		p[u] += p[v]; p[v] = u;
		return true;
	}
	bool same(int u, int v) { return find(u) == find(v); }
	int find(int u) { return p[u] < 0 ? u : p[u] = find(p[u]); }
	int usize(int u) { return -p[find(u)]; }
};

int n, k, l, a, b;
union_find x(200200), y(200200);
pii p[200200];

signed main() {
	cin >> n >> k >> l;
	rep(i,k) {
		cin >> a >> b;
		a--, b--;
		x.unite(a,b);
	}
	rep(i,l) {
		cin >> a >> b;
		a--, b--;
		y.unite(a,b);
	}
	// iから道路でも鉄道でも行ける都市の数 == これ↓と一致するペアの数
	rep(i,n) p[i] = {x.find(i),y.find(i)};
	sort(p,p+n);
	rep(i,n) {
		pii tmp = {x.find(i),y.find(i)};
		cout << upper_bound(p,p+n,tmp) - lower_bound(p,p+n,tmp) << (i==n-1 ? '\n' : ' ');
	}
}