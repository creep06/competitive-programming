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

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m;for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}
bool ool(int x,int y,int h,int w) {return((x<0)||(h<=x)||(y<0)||(w<=y));}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// 同じ直線上にあるk個のスライムはk-1手でk個のうち任意のスライムの位置にまとめられる
// unionfindで同一直線上にあるスライムをuniteしていって a) Σ(グループのサイズ-1) に
// b) 各グループ(をまとめた点)を全て4辺どれかに寄せてからまとめるのにかかるコスト を足したものが答え
// bはグループがp(>=2)個あったとして、点n個のうち1個でも4辺に接してる点があれば2p-2 なければ2p-1

struct UF {
	vector<int> p;
	UF(int n) : p(n, -1) {};
	bool unite(int u, int v) {
		u = find(u), v = find(v);
		if (u==v) return false;
		if (p[u] > p[v]) swap(u,v);
		p[u] += p[v]; p[v] = u;
		return true;
	}
	bool same(int u, int v) { return find(u) == find(v); }
	int find(int u) { return p[u] < 0 ? u : p[u] = find(p[u]); }
	int usize(int u) { return -p[find(u)]; }
};

int n, h, w, x[40040], y[40040], ok;
vi xx[100100], yy[100100], r;
UF uf(40040);

signed main() {
	cin >> n >> h >> w;
	rep(i,n) {
		cin >> x[i] >> y[i];
		x[i]--, y[i]--;
		if (x[i]==0 || x[i]==h-1 || y[i]==0 || y[i]==w-1) ok = 1;
		xx[x[i]].pb(i), yy[y[i]].pb(i);
	}
	rep(i,100000) {
		rep(j,(int)xx[i].size()-1) uf.unite(xx[i][j], xx[i][j+1]);
		rep(j,(int)yy[i].size()-1) uf.unite(yy[i][j], yy[i][j+1]);
	}
	// set -> eachの方が楽 AOJだとなぜか通らないからvector -> unique
	rep(i,n) r.pb(uf.find(i));
	unq(r);
	int res = (r.size()==1 ? 0 : r.size()*2-1-ok);
	rep(i,r.size()) res += uf.usize(r[i]) - 1;
	cout << res << ln;
}