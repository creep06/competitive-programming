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

// 7日以上連続で雨が降らない点があってはいけない
// i日目は1の点に雨を降らせてはいけない
// 毎朝雨エリアは上下左右どれか1方向に1/2マス動かすかその場に留まるか
// 何日雨が降ってないかは4隅(雲座標0,2,6,8)だけ記録すればいい 7^4=2401
// 現在の雲の位置は9通り、最大365日 全部掛けると8×10^6くらい
// dp[i][j][k][l][m][n]: i日目に雲がjにあり4隅をそれぞれk〜n日放置してる状態があり得るかどうか
// 遷移に時間かけると間に合わないかも

int n, x[400], t;
bool dp[2][9][7][7][7][7];
vi e[9];
set<int> in[9];

signed main() {
	rep(i,9) {
		e[i].pb(i);
		t = i/3*3;
		rep(yo,3) if (i!=t+yo) e[i].pb(t+yo);
		t = i%3;
		rep(ta,3) if (i!=t+ta*3) e[i].pb(t+ta*3);
		t = i + i/3;
		rep(j,2) rep(k,2) in[i].insert(t+j*4+k);
	}

	while (1) {
		cin >> n;
		if (n==0) break;
		zero(x);
		rep(i,n) rep(j,16) {
			cin >> t;
			x[i] |= (t<<j);
		}
		zero(dp[0]);
		bool ng = 0;
		each(p,in[4]) if (x[0]&1<<p) ng = 1;
		dp[1][4][1][1][1][1] = 1-ng;
		reps(i,1,n) {
			int fr = i&1, to = (i+1)&1;
			zero(dp[to]);
			rep(j,9) rep(a,7) rep(b,7) rep(c,7) rep(d,7) if (dp[fr][j][a][b][c][d]) each(u,e[j]){
				ng = 0;
				each(p,in[u]) if (x[i]&1<<p) ng = 1;
				if (ng) continue;
				int aa = a+1, bb = b+1, cc = c+1, dd = d+1;
				if (u==0) aa = 0;
				else if (u==2) bb = 0;
				else if (u==6) cc = 0;
				else if (u==8) dd = 0;
				if (aa<7 && bb<7 && cc<7 && dd<7) dp[to][u][aa][bb][cc][dd] = 1;
			}
		}
		bool res = 0;
		rep(j,9) rep(a,7) rep(b,7) rep(c,7) rep(d,7) res |= dp[n&1][j][a][b][c][d];
		cout << res << ln;
	}
}