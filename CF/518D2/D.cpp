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

//#define int long long
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
const ll mod = 998244353;
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



// k=0: a[i-1]>a[i] k=1: a[i-1]=a[i] k=2: a[i-1]<a[i]
int n, a[100100], dp[100100][222][3];

signed main() {
	cin >> n;
	rep(i,n) cin >> a[i];
	if (a[0]!=-1) dp[1][a[0]][2] = 1;
	else reps(i,1,201) dp[1][i][2] = 1;
	reps(i,1,n) {
		if (a[i]==-1) {
			reps(j,1,201) rep(k,3) {
				if (k!=2) {
					if (j>=2) (dp[i+1][1][0] += dp[i][j][k]) %= mod,
							  (dp[i+1][j][0] += mod-dp[i][j][k]) %= mod;
					(dp[i+1][j][1] += dp[i][j][k]) %= mod;
					if (j<=199) (dp[i+1][j+1][2] += dp[i][j][k]) %= mod;
				}
				else {
					(dp[i+1][j][1] += dp[i][j][k]) %= mod;
					if (j<=199) (dp[i+1][j+1][2] += dp[i][j][k]) %= mod;
				}
			}
			rep(k,3) if (k!=1) reps(j,1,201) (dp[i+1][j][k] += dp[i+1][j-1][k]) %= mod;
		} else {
			reps(j,1,201) rep(k,3) {
				if (k!=2) (dp[i+1][a[i]][a[i]==j ? 1 : (j<a[i] ? 2 : 0)] += dp[i][j][k]) %= mod;
				else if (j<=a[i]) (dp[i+1][a[i]][(a[i]==j ? 1 : 2)] += dp[i][j][k]) %= mod;
			}
		}
	}
	int res = 0;
	reps(i,1,201) rep(j,2) (res += dp[n][i][j]) %= mod;
	cout << res << endl;
}
