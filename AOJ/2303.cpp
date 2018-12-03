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
const double eps = 1e-8;

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

// dp: 人iがj回目まででk回休憩する確率
// iがj回休憩して優勝する確率は (iがj回休憩する確率) * Π(j!=iがm回目まででpj回以上休憩する確率)
// pjは算数で求められる 累積和とっとくと楽そう
// t,vが0の場合に注意

int n, m, l, t[111], v[111];
double p[111], dp[111][55][55], r[111][55];

signed main() {
	cin >> n >> m >> l;
	rep(i,n) cin >> p[i] >> t[i] >> v[i];
	rep(i,n) p[i] /= 100;
	rep(i,n) {
		dp[i][0][0] = 1;
		rep(j,m) rept(k,j) {
			dp[i][j+1][k+1] += dp[i][j][k] * p[i];
			dp[i][j+1][k] += dp[i][j][k] * (1. - p[i]);
		}
		repr(j,m) r[i][j] = r[i][j+1] + dp[i][m][j];
	}
	rep(i,n) {
		double res = 0;
		rept(j,m) {
			if (v[i]==0) break;
			double ti = 1.*l/v[i] + 1.*j*t[i], pl = dp[i][m][j];
			rep(k,n) if (i!=k) {
				if (v[k]==0) continue; // 勝ち確
				if (t[k]==0) {
					if (deq(ti,1.*l/v[k]) || ti+eps>1.*l/v[k]) pl = 0;
					continue;
				}
				if (ti<1.*l/v[k]) continue; // kが休憩0でもiの方が速い場合
				int pj = ceil((ti-1.*l/v[k])/t[k]);
				if (deq((ti-1.*l/v[k])/t[k],pj)) pj++;
				if (pj>m) {
					pl = 0; // kが毎回休憩してもj回休憩したiより速い場合
					break;
				}
				else pl *= r[k][pj];
			}
			res += pl;
		}
		printf("%.14lf\n",res);
	}
}