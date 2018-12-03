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

int h, w, s, m, a[44][44];
pii dp[44][44][44][44];

int r(int li, int lj, int ri, int rj) {
	return a[ri][rj] - a[ri][lj-1] - a[li-1][rj] + a[li-1][lj-1];
}

pii rec(int li, int lj, int ri, int rj) {
	if (dp[li][lj][ri][rj].fi!=0) return dp[li][lj][ri][rj];
	pii res = mp(1,s-(m-r(li,lj,ri,rj)));
	reps(i,li,ri) { // ヨコに切る
		if (s-(m-r(li,lj,i,rj))<0) continue;
		if (s-(m-r(i+1,lj,ri,rj))<0) continue;
		pii x = rec(li,lj,i,rj), y = rec(i+1,lj,ri,rj);
		chmax(res, mp(x.fi+y.fi, min(x.se,y.se)));
	}
	reps(j,lj,rj) { // タテに切る
		if (s-(m-r(li,lj,ri,j))<0) continue;
		if (s-(m-r(li,j+1,ri,rj))<0) continue;
		pii x = rec(li,lj,ri,j), y = rec(li,j+1,ri,rj);
		chmax(res, mp(x.fi+y.fi, min(x.se,y.se)));
	}
	return dp[li][lj][ri][rj] = res;
}

signed main() {
	while (1) {
		cin >> h >> w >> s;
		if (h==0) break;
		m = 0;
		repst(i,1,h) repst(j,1,w) {
			cin >> a[i][j];
			m += a[i][j];
		}
		repst(i,1,h) repst(j,1,w) a[i][j] += a[i][j-1];
		repst(j,1,w) repst(i,1,h) a[i][j] += a[i-1][j];
		rep(i,33) rep(j,33) rep(k,33) rep(l,33) dp[i][j][k][l] = mp(0,inf);
		pii res = rec(1,1,h,w);
		cout << res.fi << ' ' << res.se << ln;
	}
}