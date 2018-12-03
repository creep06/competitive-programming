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
const double eps = 1e-10;

ll mop(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
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

int n, m, p, x, y, b[10][10][10];
vi dx, dy, dz;
int sz;

int rec(int x, int y, int z, int c, int d) {
	int xx = x + dx[d], yy = y + dy[d], zz = z + dz[d];
	if (xx<0 || n<xx || yy<0 || n<yy || zz<0 || n<zz) return c;
	if (b[xx][yy][zz]==b[x][y][z]) return rec(xx,yy,zz,c+1,d);
	else return c;
}

bool fin() {
	rep(i,n) rep(j,n) rep(k,n)
				rep(d,sz) if (b[i][j][k]!=0 && rec(i,j,k,1,d)>=m) return 1;
	return 0;
}

signed main() {
	repst(i,-1,1) repst(j,-1,1) repst(k,-1,1) if (!(i==0 && j==0 && k==0))
					dx.pb(i), dy.pb(j), dz.pb(k);
	sz = dx.size();
	while (1) {
		cin >> n >> m >> p;
		zero(b);
		if (n==0) break;
		int wt = -1;
		rep(i,p) {
			cin >> x >> y;
			x--, y--;
			int h = 0;
			while (b[x][y][h]!=0) h++;
			// 先行白1 後攻黒-1
			b[x][y][h] = (i%2==0 ? 1 : -1);
			if (wt==-1 && fin()) wt = i;
		}
		if (wt==-1) cout << "Draw" << ln;
		else cout << (wt%2 ? "White" : "Black") << ' ' << wt+1 << ln;
	}
}