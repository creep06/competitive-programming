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

class GooseInZooDivOne {
public:
	int h, w, n, m, d, dp[2][2525], res;
	bool f[2525];
	vector<int> x, y, a;

	int rec(int v) {
		f[v] = 1;
		int res = 1;
		rep(i,n) if (!f[i] && abs(x[v]-x[i])+abs(y[v]-y[i])<=d) res += rec(i);
		return res;
	}

	int count(vector<string> s, int d_) {
		d = d_, h = s.size(), w = s[0].size();
		rep(i,h) rep(j,w) if (s[i][j]=='v') x.push_back(i), y.push_back(j), n++;
		rep(i,n) if (!f[i]) a.push_back(rec(i)), m++;
		dp[0][0] = 1;
		rep(I,m) {
			int i = I&1;
			rep(j,n) if (dp[i][j]) {
				(dp[i^1][j+a[I]] += dp[i][j]) %= mod;
				(dp[i^1][j] += dp[i][j]) %= mod;
			}
			memset(dp[i], 0, sizeof(dp[i]));
		}
		int res = 0;
		reps(i,2,n+1) if (i%2==0) (res += dp[m&1][i]) %= mod;
		return res;
	}
};
