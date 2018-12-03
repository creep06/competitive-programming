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



int h, w, mx, sx, sy, gx, gy, d[1010][1010], ng[1010][1010];
string s[1010];

signed main() {
	cin >> h >> w >> mx;
	memset(ng, -1, sizeof(ng));
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
	rep(i,1010) rep(j,1010) ng[i][j] = inf;
	rep(i,h) {
		cin >> s[i];
		rep(j,w) {
			if (s[i][j]=='S') sx = i, sy = j;
			if (s[i][j]=='G') gx = i, gy = j;
			if (s[i][j]=='@') ng[i][j] = 1, que.push({0, i*10000 + j});
		}
	}
	while(!que.empty()) {
		int v = que.top().second, dis = que.top().first; que.pop();
		int x = v/10000, y = v%10000;
		if (ng[x][y]<dis) continue;
		rep(i,4) {
			int xx = x+dx[i], yy = y+dy[i], p = dis+1;
			if (s[xx][yy]=='#') continue;
			if (p<=mx && ng[xx][yy] > p) {
				ng[xx][yy] = p;
				que.push({p, xx*10000+yy});
			}
		}
	}
	rep(i,1010) rep(j,1010) d[i][j] = inf;
	d[sx][sy] = 0;
	que.push({0, sx*10000+sy});
	while (!que.empty()) {
		int v = que.top().second, dis = que.top().first; que.pop();
		int x = v/10000, y = v%10000;
		if (d[x][y]<dis) continue;
		rep(i,4) {
			int xx = x+dx[i], yy = y+dy[i], p = dis+1;
			if (s[xx][yy]=='#' || ng[xx][yy]!=inf) continue;
			if (d[xx][yy] > p) {
				d[xx][yy] = p;
				que.push({p, xx*10000+yy});
			}
		}
	}
	cout << (d[gx][gy]==inf ? -1 : d[gx][gy]) << endl;
}
