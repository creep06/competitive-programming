#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define each(itr,v) for(auto &(itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define dbg(x) cout<<#x" = "<<(x)<<ln<<flush
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ')<<flush;}}

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

// dp[i][j]: 黒をi番目、白をj番目まで左から並べるのに必要な最小操作回数
// b,w[i][j]: 黒をi番目、白をj番目まで並べた状態に黒/白を追加するのに必要な最小操作回数
// ∴ 初期状態で黒/白のi+1/j+1番目より左側にある、黒i+1以上のボールと白j+1以上のボールの個数
// これをO(N^2)で求められればいい
// まず各黒ボールの左側にある白j+1以上のボールの個数を累積和かなんかで求めてから、
// b[i+1][j] = b[i][j] + (p[0][i+1]<p[0][i]) で埋めていけばいい
// j以上の白ボールの個数 = j+1以上の白ボールの個数 - jの白が黒のi+1より左にあるかどうか
// dp[i][j] = min(dp[i-1][j]+b[i-1][j], dp[i][j-1]+w[i][j-1]) で更新すればok

int n, t, p[2][2020], b[2020][2020], w[2020][2020], dp[2020][2020];
char c;

int main() {
	cin >> n;
	rep(i,n*2) {
		cin >> c >> t;
		p[c=='W'][t-1] = i;
	}
	
	rep(i,n) {
		reps(j,i+1,n) if (p[0][j]<p[0][i]) b[i][n]++;
		for (int j=n-1; j>=0; --j) b[i][j] = b[i][j+1] + (p[1][j]<p[0][i]);
	}
	rep(i,n) {
		reps(j,i+1,n) if (p[1][j]<p[1][i]) w[n][i]++;
		for (int j=n-1; j>=0; --j) w[j][i] = w[j+1][i] + (p[0][j]<p[1][i]);
	}
	
	rep(i,2020) rep(j,2020) dp[i][j] = inf;
	dp[0][0] = 0;
	rep(i,n+1) rep(j,n+1) chmin(dp[i+1][j], dp[i][j]+b[i][j]), chmin(dp[i][j+1], dp[i][j]+w[i][j]);
	cout << dp[n][n];
}