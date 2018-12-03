#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <string.h>
#include <numeric>
using namespace std;

#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(i,v) for(auto &(i):(v))
#define eachr(i,v) for(auto &(i)=(v).rbegin();(i)!=(v).rend();(i)++)
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

//typedef complex<double> P;
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
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double eps = 1e-10;

ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
bool ool(int x,int y,int h,int w) {return((x<0)||(h<=x)||(y<0)||(w<=y));}
bool deq(double a,double b) {return abs(a-b)<eps;}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;



int n, mod, dp[3030][3030], p[10010010], res;

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m;for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}

const int MAXS = 10010;
ll fact[MAXS+1], factr[MAXS+1], inv[MAXS+1];
ll comb(ll n, ll r) {
	if (fact[0]==0) {
		fact[0] = factr[0] = inv[1] = 1;
		for (int i=2; i<=MAXS; i++) inv[i] = inv[mod%i] * (mod-mod/i) %mod;
		for (int i=1; i<=MAXS; i++) fact[i] = fact[i-1]*i %mod, factr[i] = factr[i-1]*inv[i] %mod;
	}
	if (r<0 || n<r) return 0;
	return fact[n]*factr[r] %mod *factr[n-r] %mod;
}

int f(int k) {
	int ret = 0;
	rep(x,k+1) (ret += dp[k][x] * p[(n-k)*x] %mod) %= mod;
	return ret * mop(2,mop(2,n-k,mod-1)) %mod;
}

signed main() {
	cin >> n >> mod;
	dp[0][0] = 1;
	reps(i,1,n+1) rep(j,n+1) {
			if (j) (dp[i][j] += dp[i-1][j-1]) %= mod;
			(dp[i][j] += dp[i-1][j]*(j+1)) %= mod;
	}
	p[0] = 1;
	reps(i,1,10010010) p[i] = p[i-1]*2 %mod;
	rep(k,n+1) (res += comb(n,k) * f(k) * (k%2 ? -1 : 1) %mod + mod) %= mod;
	cout << res << endl;
}
