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
const ll mod = (ll)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double eps = 1e-10;

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m;for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
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



int n, a, b, sz[5050], g = -1, gg = -1, f[5050], k, dp[5050][5050], res;
vector<int> e[5050], t;

const int MAXS = 5050;
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

int rec(int v, int p) {
	bool gp = 1;
	sz[v] = 1;
	each(i,e[v]) if (i!=p) {
		int tmp = rec(i,v);
		if (tmp>n/2) gp = 0;
		sz[v] += tmp;
	}
	if (gp && n-sz[v]<=n/2) {
		if (g==-1) g = v;
		else gg = v;
	}
	return sz[v];
}

int rec2(int v, int p) {
	each(i,e[v]) if (i!=p) sz[v] += rec(i,v);
	return sz[v];
}

signed main() {
	f[0] = 1;
	reps(i,1,5050) f[i] = f[i-1]*i %mod;
	cin >> n;
	rep(i,n-1) {
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b), e[b].push_back(a);
	}
	rec(0,-1);
	if (gg!=-1) return cout << f[n/2]*f[n/2] %mod, 0;
	memset(sz, 0, sizeof(sz));
	rec2(g,-1);
	each(i,e[g]) t.push_back(sz[i]), k++;
	dp[0][0] = 1;
	rep(i,k) {
		int sum = 0;
		rep(j,i) sum += t[j];
		rep(x,sum+1) rep(y,t[i]+1)
			(dp[i+1][x+y] += dp[i][x] * comb(t[i],y) %mod * comb(t[i],y) %mod * f[y]) %= mod;
	}
	rep(i,n) (res += dp[k][i] * f[n-i] * (i%2 ? -1 : 1)) %= mod;
	(res += mod) %= mod;
	cout << res << endl;
}
