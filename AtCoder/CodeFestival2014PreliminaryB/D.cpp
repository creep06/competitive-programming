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



template<typename V> struct SPA {
	private:
	vector<vector<V> > sp;
	public:
	SPA(int sz) { sp = vector<vector<V> >(sz, vector<V>(30,0));}
	void init(int n, V a[]) {
		for (int i = 0; i < n; ++i) sp[i][0] = a[i];
		for (int k = 1; k < 30; ++k)
			for (int i = 0; i < n-1; ++i)
				if (i+(1<<(k-1))<n) sp[i][k] = max(sp[i][k-1], sp[i+(1<<(k-1))][k-1]);
	}
	V query(int l, int r) { // max [l,r)
		int m = 0;
		while (1<<(1+m)<=r-l) m++;
		return max(sp[l][m], sp[r-(1<<m)][m]);
	}
};

int n, h[100100];
SPA<int> spa(100100);

signed main() {
	cin >> n;
	rep(i,n) cin >> h[i];
	spa.init(n,h);
	rep(i,n) {
		int res = 0, l = 0, r = i+1;
		while (r-l>1) {
			int m = (r+l)/2;
			if (spa.query(i-m,i+1)==h[i]) l = m;
			else r = m;
		}
		res += l;
		l = 0, r = n-i;
		while (r-l>1) {
			int m = (r+l)/2;
			if (spa.query(i,i+m+1)==h[i]) l = m;
			else r = m;
		}
		res += l;
		cout << res << endl;
	}
}
