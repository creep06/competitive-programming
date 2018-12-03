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

class RotatingBot {
public:
	int minArea(vector<int> m) {
		int n = m.size(), a[222][222] = {}, x = 100, y = 100, b[4];
		memset(b, -1, sizeof(b));
		a[100][100] = 1;
		rep(i,n) {
			int d = i%4;
			rep(j,m[i]) {
				int xx = x + dx[d], yy = y + dy[d];
				if (a[xx][yy] || (d%2 && b[d]==xx) || (d%2==0 && b[d]==yy))
					return -1;
				a[xx][yy] = 1;
				x = xx, y = yy;
				if (i<n-1 && j==m[i]-1) {
					xx += dx[d], yy += dy[d];
					if (a[xx][yy]) continue;
					if (b[d]==-1) {
						if ((d==2 && 100<y) || (d==3 && 100<x)) return -1;
						b[d] = (d%2 ? xx : yy);
					}
					else if ((d%2 && b[d]!=xx) || (d%2==0 && b[d]!=yy))
						return -1;
				}
			}
		}
		int lx = 1<<30, ly = 1<<30, rx = 0, ry = 0;
		rep(i,222) rep(j,222) if (a[i][j])
			chmin(lx,i), chmin(ly,j), chmax(rx,i), chmax(ry,j);
		return (rx-lx+1)*(ry-ly+1);
	}
};
