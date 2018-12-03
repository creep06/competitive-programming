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

// [a,b]に1つだけ4/7以外の数字を含む数が何個あるか 桁dp
// j:もう4/7以外を含んでいるかどうか k:sもうより小さいと確定してるかどうか l:もう0以外の数字が出たかどうか

class TheAlmostLuckyNumbersDivOne {
	public:
	ll dig(ll n) {
		string s = to_string(n);
		ll dp[20][2][2][2] = {};
		dp[0][0][0][0] = 1;
		rep(i,s.size()) rep(j,2) rep(k,2) rep(l,2) if (dp[i][j][k][l]) {
			if (j) {
				if (k || '4'<=s[i]) dp[i+1][j][k|('4'<s[i])][1] += dp[i][j][k][l];
				if (k || '7'<=s[i]) dp[i+1][j][k|('7'<s[i])][1] += dp[i][j][k][l];
			}
			else {
				int lim = (k ? 9 : s[i]-'0');
				rep(d,lim+1) dp[i+1][((!l && d!=0) || l) && d!=4 && d!=7][k|(d<lim)][l|(d!=0)] += dp[i][j][k][l];
			}
		}
		return dp[s.size()][0][0][1] + dp[s.size()][0][1][1] + dp[s.size()][1][0][1] + dp[s.size()][1][1][1];
	}
	
	ll find(ll a, ll b) {
		return dig(b) - dig(a-1);
	}
};