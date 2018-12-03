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
const int dx[6] = {0, 1, 1, 0, -1, -1};
const int dy[2][6] = {{1, 0, -1, -1, -1, 0}, {1, 1, 0, -1, 0, 1}};
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

// どこがバグってるかわからん

struct S {
	int x, y, t, c;
	S(int xx, int yy, int tt, int cc) {x = xx, y = yy, t = tt, c = cc;}
	bool operator > (const S &e) const {return c > e.c;}
};

int sx, sy, gx, gy, n, jx[1000], jy[1000], lx, ly, LX, LY, d[222][222][6];
bool ng[222][222];
vector<S> e[222][222][6];

void dijkstra() {
	priority_queue<S, vector<S>, greater<S> > que;
	que.push(S(sx,sy,0,0));
	while(!que.empty()) {
		S p = que.top(); que.pop();
		int x = p.x, y = p.y, t = p.t, dis = p.c;
		if (d[x][y][t] < dis) continue;
		for (int i = 0; i < e[x][y][t].size(); ++i) {
			S q = e[x][y][t][i];
			int xx = q.x, yy = q.y, tt = q.t, cost = q.c;
			if (d[xx][yy][tt] > d[x][y][t] + cost) {
				d[xx][yy][tt] = d[x][y][t] + cost;
				que.push(S(xx,yy,tt,d[xx][yy][tt]));
			}
		}
	}
}

signed main() {
	cin >> sx >> sy >> gx >> gy >> n;
	rep(i,n) cin >> jx[i] >> jy[i];
	cin >> lx >> ly;
	
	sx += lx, sy += ly, gx += lx, gy += ly;
	rep(i,n) {
		jx[i] += lx, jy[i] += ly;
		ng[jx[i]][jy[i]] = 1;
	}
	LX = lx*2+1, LY = ly*2+1;
	
	rep(i,LX) rep(j,LY) rep(k,6) d[i][j][k] = inf;
	d[sx][sy][0] = 0;
	rep(i,LX) rep(j,LY) if (!ng[i][j]) {
		int p = (i+lx)%2;
		rep(k,6) {
			int id = abs((i-lx)*(j-ly)*k)%6;
			rep(l,6) {
				int ii = i + dx[l], jj = j + dy[p][l];
				if (ool(ii,jj,LX,LY) || ng[ii][jj]) continue;
				e[i][j][k].pb(S(ii, jj, (k+1)%6, id!=l));
			}
			e[i][j][k].pb(S(i, j, (k+1)%6, 1));
		}
	}
	dijkstra();
	int res = inf;
	rep(i,6) chmin(res, d[gx][gy][i]);
	cout << (res==inf ? -1 : res) << ln;
}