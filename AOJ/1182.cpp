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

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m; assert(b>=0); for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// ワーシャルで鉄道会社ごとの全点対間最短路を求める
// → 距離を運賃に変換
// → それらのminをとった配列で更にワーシャルで全点対間最短路を求める

int n, m, t, s, g, x, y, d, c, p[20], q[50], r[50], w[20][100][100], z[100][100], b[20020];

signed main() {
	while (1) {
		cin >> n >> m >> t >> s >> g;
		if (n==0) break;
		s--, g--;
		rep(i,t) rep(j,n) rep(k,n) if (j!=k) w[i][j][k] = inf;
		rep(i,m) {
			cin >> x >> y >> d >> c;
			x--, y--, c--;
			chmin(w[c][x][y],d), chmin(w[c][y][x],d);
		}
		rep(o,t) rep(k,n) rep(i,n) rep(j,n)
		    chmin(w[o][i][j], w[o][i][k]+w[o][k][j]);
		rep(i,t) cin >> p[i];
		rep(i,t) {
			rep(j,p[i]-1) cin >> q[j];
			rep(j,p[i]) cin >> r[j];
			rep(j,p[i]-1) repst(k,(j==0 ? 1 : q[j-1]+1),q[j]) b[k] = b[k-1] + r[j];
			repst(k,q[p[i]-2]+1,20000) b[k] = b[k-1] + r[p[i]-1];
			rep(j,n) rep(k,n) if (w[i][j][k]!=inf) w[i][j][k] = b[w[i][j][k]];
		}
		rep(i,n) rep(j,n) if (i!=j) z[i][j] = inf;
		rep(o,t) rep(i,n) rep(j,n) chmin(z[i][j], w[o][i][j]);
		rep(k,n) rep(i,n) rep(j,n)
		    chmin(z[i][j], z[i][k]+z[k][j]);
		cout << (z[s][g]==inf ? -1 : z[s][g]) << ln;
	}
}