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
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}
bool ool(int x,int y,int h,int w) {return((x<0)||(h<=x)||(y<0)||(w<=y));}
bool deq(double a,double b) {return abs(a-b)<eps;}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;



struct UF {vector<int> par;
    UF(int NV) { par.clear(); rep(i,NV) par.push_back(i); }
    void reset() { rep(i,par.size()) par[i] = i; }
    int operator[](int x) { return par[x] == x ? x : par[x] = operator[](par[x]); }
    void operator()(int x, int y) {x = operator[](x); y = operator[](y);if (x != y) par[x] = y;}};

// con:連結性 ple:完全性

int n, q, t, x, y;
vector<int> g[100100];
set<int> e[100100];
UF con(100100), ple(100100);

signed main() {
	cin >> n >> q;
	rep(i,n) g[i].push_back(i);
	while (q--) {
		cin >> t >> x >> y;
		x--, y--;
		if (t==1) {
			e[x].insert(y), e[y].insert(x);
			if (con[x]==con[y] || ple[x]==ple[y]) continue;
			int xx = con[x], yy = con[y];
			if (g[xx].size()>g[yy].size()) swap(g[xx],g[yy]);
			each(i,g[xx]) g[yy].push_back(i);
			con(x,y);
		}
		else if (t==2) {
			int xx = con[x], sz = g[xx].size();
			reps(i,1,sz) ple(g[xx][0], g[xx][i]);
			rep(i,sz-1) g[xx].pop_back();
		} else cout << (e[x].count(y) || ple[x]==ple[y] ? "Yes" : "No") << endl;
	}
}
