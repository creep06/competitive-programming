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



int l, r, k, cnt[1<<10], ten[33];

int dig(const string &s, int x, int y) {
	int n = s.size(), dp[22][2][2][1<<10] = {};
	dp[0][0][0][0] = 1;
	rep(i,n) rep(j,2) rep(l,2) rep(b,1<<10) if (dp[i][j][l][b]) {
		if (i==x) {
			if (cnt[b|(1<<y)]>k) continue;
			if (j==0 && s[i]-'0'<y) continue;
			(dp[i+1][j|(s[i]-'0'>y)][1][b|(1<<y)] += dp[i][j][l][b]) %= mod;
		} else {
			rep(t,(j ? 10 : (s[i]-'0')+1)) {
				int bit = (l==0 && t==0 ? b : b|(1<<t));
				if (cnt[bit]>k) continue;
				(dp[i+1][j|(s[i]-'0'>t)][l|(t!=0)][bit] += dp[i][j][l][b]) %= mod;
			}
		}
	}
	int res = 0;
	rep(i,2) rep(l,2) rep(j,1<<10) (res += dp[n][i][l][j]) %= mod;
	return res;
}

int ans(int n) {
	string s = to_string(n);
	int res = 0, m = s.size();
	rep(i,m) reps(j,1,10) {
		if (i==0 && s[i]-'0'<j) continue;
		(res += dig(s,i,j) * ten[m-i-1] %mod * j) %= mod;
	}
	return res;
}

signed main() {
	rep(i,1<<10) cnt[i] = __builtin_popcount(i);
	ten[0] = 1;
	reps(i,1,33) ten[i] = ten[i-1]*10 %mod;
	cin >> l >> r >> k;
	cout << (ans(r) - ans(l-1) + mod) %mod << endl;
}
