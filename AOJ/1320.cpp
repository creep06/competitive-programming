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
#define chmin(x,y) if((x)>(y))(x)=(y)
#define chmax(x,y) if((x)<(y))(x)=(y)
#define ln '\n'
#define bln(i,n) (((i)==(n)-1)?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln<<flush
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ')<<flush;}}

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

int n, nm, dp[14][1<<14], cm[14][14], res;
bool b[14];
string s[14];

signed main() {
	while (1) {
		cin >> n;
		if (n==0) break;
		rep(i,n) cin >> s[i];
		
		// 部分文字列チェック
		nm = 0;
		memset(b,0,sizeof(b));
		rep(i,n) rep(j,n) if (i!=j && s[i].find(s[j])!=string::npos) b[j] = 1;
		rep(i,n) if (b[i]) s[i] = "_", nm++;
		sort(s,s+n);
		n -= nm;
		
		// 最後につけたのがi番目、付け終わった名前の集合がj
		rep(i,n) rep(j,1<<n) dp[i][j] = inf;
		rep(i,n) dp[i][1<<i] = s[i].size();
		rep(i,n) rep(j,n) cm[i][j] = s[j].size();
		rep(i,n) rep(j,n) if (i!=j)
			repst(d,1,min(s[i].size(),s[j].size())) if (s[i].substr(s[i].size()-d,d) == s[j].substr(0,d))
				chmin(cm[i][j], s[j].size() - d);
		reps(j,1,(1<<n)-1) rep(i,n)
			rep(k,n) if (!(j>>k&1))
				chmin(dp[k][j|(1<<k)], dp[i][j] + cm[i][k]);
		
		res = inf;
		rep(i,n) chmin(res,dp[i][(1<<n)-1]);
		cout << res << ln;
	}
}