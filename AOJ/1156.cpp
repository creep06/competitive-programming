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
// → ↓ ← ⇡
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

struct S {
	int x, y, d, c; // i座標 j座標 方向 命令コスト
	S(int xx, int yy, int dd, int cc) {x=xx,y=yy,d=dd,c=cc;}
	bool operator > (const S &e) const {return c > e.c;}
};

int h, w, s[30][30], c[4], d[30][30][4];
vector<S> e[30][30][4];

void dijkstra() {
	priority_queue<S, vector<S>, greater<S> > que;
	que.push(S(0,0,0,0));
	while(!que.empty()) {
		S p = que.top(); que.pop();
		int x = p.x, y = p.y, di = p.d, co = p.c;
		if (d[x][y][di] < co) continue;
		for (int i = 0; i < e[x][y][di].size(); ++i) {
			S q = e[x][y][di][i];
			int xx = q.x, yy = q.y, din = q.d, con = q.c;
			if (d[xx][yy][din] > d[x][y][di] + con) {
				d[xx][yy][din] = d[x][y][di] + con;
				que.push(S(xx, yy, din, d[xx][yy][din]));
			}
		}
	}
}

signed main() {
	while (1) {
		cin >> w >> h;
		if (h==0) break;
		rep(i,h) rep(j,w) cin >> s[i][j];
		rep(i,4) cin >> c[i];
		rep(i,h) rep(j,w) rep(k,4) d[i][j][k] = inf, e[i][j][k].clear();
		d[0][0][0] = 0;
		// k:現在の向き l:進みたい向き
		rep(i,h) rep(j,w) rep(k,4) rep(l,4) {
			int ii = i + dx[l], jj = j + dy[l];
			if (ool(ii, jj, h, w)) continue;
			e[i][j][k].pb(S(ii, jj, l, ((l-k+4)%4==s[i][j]) ? 0 : c[(l-k+4)%4]));
		}
		dijkstra();
		cout << *min_element(d[h-1][w-1], d[h-1][w-1]+4) << ln;
	}
}