#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto (itr):(v))
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

typedef complex<double> P;
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
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}
bool ool(int x,int y,int h,int w) {return((x<0)||(h<=x)||(y<0)||(w<=y));}
bool deq(double a,double b) {return abs(a-b)<eps;}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// sccdしてcmpから新しいグラフを作る
// dp[i][j]: 頂点iを塗らない/塗る(j)場合の数
// iの子kに対して dp[i][0] = dp[k][0]+dp[k][1], dp[i][1] = dp[k][1]
// 辺の向きは逆にしたほうがたぶん楽
// 塗らない->その子は完全に自由 塗る->その子も全部塗るしかない

// initで頂点数を指定してsccで成分分解を実行 返り値は強連結成分の個数==grpのサイズ
// grp[i]:i番目の強連結成分に含まれる頂点一覧
// cmp[i]:頂点iが属する強連結成分の番号 この番号も⇡のiもトポロジカル順
class SCC {
	public:
	static const int MV = 1010;
	vector<vector<int> > grp; int NV,cmp[MV];
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) {vis[cu]=1; cmp[cu]=ind; grp[ind].push_back(cu);
		for(int i=0;i<RE[cu].size();++i) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	int scc() {
		int c=0; grp.clear(); grp.resize(MV); NUM.clear();
		memset(vis,0,sizeof(vis)); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		memset(vis,0,sizeof(vis)); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]])
			{ grp[c].clear(); revdfs(NUM[i],c); sort(grp[c].begin(),grp[c].end()); c++;}
		grp.resize(c); return c;
	}
};

int n, m, a[1000], b[1000];
bool us[1000];
SCC scc;
vi e[1000];

ll rec(int v) {
	us[v] = 1;
	ll res = 1;
	rep(i,e[v].size()) (res *= rec(e[v][i])) %= mod;
	return res + 1;
}

signed main() {
	cin >> n >> m;
	scc.init(n);
	rep(i,m) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		scc.add(a[i],b[i]);
	}
	int g = scc.scc();
	rep(i,m) if (scc.cmp[b[i]]!=scc.cmp[a[i]]) e[scc.cmp[b[i]]].pb(scc.cmp[a[i]]);
	ll res = 1;
	repr(i,g-1) if (!us[i]) (res *= rec(i)) %= mod;
	cout << res << ln;
}