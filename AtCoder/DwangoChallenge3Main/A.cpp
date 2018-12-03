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



string s;
int n, k, dp[55][55][55][2];
bool fin[55][55][55][2];
const int M = 10000;

// [l,r]をk文字まで変えたときの最(b?大:小)値
int rec(int l, int r, int x, bool b) {
	if (fin[l][r][x][b]) return dp[l][r][x][b];
	fin[l][r][x][b] = 1;
	int &res = dp[l][r][x][b];
	res = (b ? -M : M);
	// どう変えても正しい式にならない場合
	if ((r-l+1)%2==0) return res;
	// 1桁の場合
	if (l==r) {
		if (x) res = (b ? 9 : 0);
		else if (isdigit(s[l])) res = s[l]-'0';
		return res;
	}
	// 一番右の文字は+か-にする
	int xp = x - (s[r]!='+'), xm = x - (s[r]!='-');
	// 2つの式の和の最大値は (最大)+(最大) or (最大)-(最小)
	if (b) {
		reps(i,l,r-1) {
			rep(j,xp+1) {
				int tx = rec(l,i,j,1), ty = rec(i+1,r-1,xp-j,1);
				if (tx!=-M && ty!=-M) chmax(res, tx+ty);
			}
			rep(j,xm+1) {
				int tx = rec(l,i,j,1), ty = rec(i+1,r-1,xm-j,0);
				if (tx!=-M && ty!=M) chmax(res, tx-ty);
			}
		}
	}
	// 最小値は (最小)+(最小) or (最小)-(最大)
	else {
		reps(i,l,r-1) {
			rep(j,xp+1) {
				int tx = rec(l,i,j,0), ty = rec(i+1,r-1,xp-j,0);
				if (tx!=M && ty!=M) chmin(res, tx+ty);
			}
			rep(j,xm+1) {
				int tx = rec(l,i,j,0), ty = rec(i+1,r-1,xm-j,1);
				if (tx!=M && ty!=-M) chmin(res, tx-ty);
			}
		}
	}
	return res;
}

signed main() {
	cin >> k >> s;
	n = s.size();
	int res = rec(0,n-1,k,1);
	if (res==-M) cout << "NG" << endl;
	else cout << "OK" << endl << res << endl;
}
