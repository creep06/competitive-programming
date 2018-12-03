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

// dp[i][j]: 小さい方からi桁目までを繰り上がりあり(j==1)なし(j==0)で埋める組み合わせの数
// 求めるものはdp[n][0] 8通り場合分けは遷移がかなりややこしい ?の個数でまとまりそう
// i==n-1のとき0は使っちゃいけない、C[i]==9かつj==1もあり得ない

int n;
const char q = '?';
ll dp[55][2];
string a, b, c;

void rec(int sx, int sy, int sz, int x, int y, int z, int id, int l) {
	if (l==0) {
		if (sx) reps(i,(id==n-1),10) rec(sx,sy,sz,i,y,z,id,l+1);
		else rec(sx,sy,sz,a[n-id-1]-'0',y,z,id,l+1);
	} else if (l==1) {
		if (sy) reps(i,(id==n-1),10) rec(sx,sy,sz,x,i,z,id,l+1);
		else rec(sx,sy,sz,x,b[n-id-1]-'0',z,id,l+1);
	} else if (l==2) {
		if (sz) reps(i,(id==n-1),10) rec(sx,sy,sz,x,y,i,id,l+1);
		else rec(sx,sy,sz,x,y,c[n-id-1]-'0',id,l+1);
	} else {
		if (x+y==z) (dp[id+1][0] += dp[id][0]) %= mod;
		else if (x+y+1==z) (dp[id+1][0] += dp[id][1]) %= mod;
		else if ((x+y)%10==z) (dp[id+1][1] += dp[id][0]) %= mod;
		else if ((x+y+1)%10==z) (dp[id+1][1] += dp[id][1]) %= mod;
	}
}

signed main() {
	while (1) {
		cin >> a;
		if (a=="0") break;
		cin >> b >> c;
		n = a.size();
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		
		rep(i,n) {
			char x = a[n-i-1], y = b[n-i-1], z = c[n-i-1];
			int sx = (x==q), sy = (y==q), sz = (z==q);
			rec(sx,sy,sz,0,0,0,i,0);
			//cout << dp[i+1][0] << ' ' << dp[i+1][1] << ln;
		}
		cout << dp[n][0] << ln;
	}
}