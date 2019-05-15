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
#define endl "\n"

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




int T, h, w;
vector<pair<int,int> > p;
bool sw;

void yes() {
	cout << "POSSIBLE" << endl;
	each(i,p) {
		if (sw) swap(i.first, i.second);
		cout << i.first << ' ' << i.second << endl;
	}
}

void no() {
	cout << "IMPOSSIBLE" << endl;
}

signed main() {
	cin >> T;
	reps(TT,1,T+1) {
		cout << "Case #" << TT << ": ";
		cin >> h >> w;
		sw = 0;
		if (h>w) swap(h,w), sw = 1;
		if (h==2) {
			if (w==5) {
				p = {{2,3}, {1,1}, {2,4}, {1,2}, {2,5}, {1,3}, {2,1}, {1,5}, {2,2}, {1,4}};
				yes();
			}
			else no();
		} else if (h==3) {
			if (w==3) no();
			else if (w==4) {
				p = {{2,1}, {3,3}, {1,4}, {2,2}, {3,4}, {1,3}, {3,2}, {2,4}, {1,2}, {3,1}, {2,3}, {1,1}};
				yes();
			}
			else if (w==5) {
				p = {{1,1}, {3,2}, {1,3}, {2,5}, {3,3}, {2,1}, {3,5}, {1,4}, {2,2}, {3,4}, {1,5}, {2,3}, {3,1}, {1,2}, {2,4}};
				yes();
			}
		} else if (h==4) {
			if (w==4) {
				p = {{1,1}, {2,3}, {3,1}, {1,2}, {2,4}, {4,3}, {2,2}, {1,4}, {3,3}, {4,1}, {3,4}, {1,3}, {4,2}, {2,1}, {4,4}, {3,2}};
				yes();
			} else if (w==5) {
				p = {{1,1}, {4,2}, {2,3}, {4,4}, {1,5}, {3,4}, {2,2}, {1,4}, {3,5}, {4,3}, {3,1}, {2,4}, {3,2}, {1,3}, {4,5}, {2,1}, {3,3}, {1,2}, {2,5}, {4,1}};
				yes();
			}
		} else if (h==5) {
			p = {{1,1}, {5,2}, {1,3}, {5,4}, {1,5}, {2,2}, {3,5}, {4,3}, {2,4}, {3,2}, {5,1}, {4,5}, {3,1}, {2,3}, {4,4}, {2,5}, {4,2}, {2,1}, {3,4}, {5,3}, {1,4}, {5,5}, {1,2}, {3,3}, {4,1}};
			yes();
		}
	}
}
