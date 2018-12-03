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
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double eps = 1e-10;

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m; assert(b>=0); for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
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

// 地図作って(クソ面倒)上からdpするだけ
// 毎回地図作り直す必要なかった
int n, m, si, sj, s[2000][2000], dp[2000][2000];
bool p[1000001];

// エラトステネスの篩 O(NloglogN)
void sieve() {
	fill(p, p+1000001, true);
	p[0] = p[1] = false;
	for (int i = 2; i*i <= 1000000; ++i)
		if (p[i]) for (int j = 2*i; j <= 1000000; j += i) p[j] = false;
}

// 地図作成 再帰10^6回だとスタックオーバーフローになる
void mm() {
	memset(s,0,sizeof(s));
	s[1000][1000] = 1;
	if (m==1) si = 1000, sj = 1000;
	int i = 1000, j = 1001, d = 0;
	repst(p,2,n) {
		s[i][j] = p;
		if (p==m) si = i, sj = j;
		if (p==n) return;
		int i0 = i + dx[d], j0 = j + dy[d], i1 = i + dx[(d+1)%4], j1 = j + dy[(d+1)%4];
		if (s[i1][j1]) i = i0, j = j0;
		else i = i1, j = j1, d++, d %= 4;
	}
}

signed main() {
	sieve();
	while (1) {
		cin >> n >> m;
		if (n==0) break;
		mm();
		memset(dp,-1,sizeof(dp));
		dp[si][sj] = p[m];
		int l = 0, r = 0;
		reps(i,si,1999) reps(j,1,1999) if (s[i][j] && dp[i][j]!=-1) {
			repst(d,-1,1) if (s[i+1][j+d]) chmax(dp[i+1][j+d], dp[i][j] + p[s[i+1][j+d]]);
			if (dp[i][j]>l) l = dp[i][j], r = s[i][j];
			else if (dp[i][j]==l && p[s[i][j]]) chmax(r, s[i][j]);
		}
		cout << l << ' ' << (l==0 ? 0 : r) << ln;
	}
}