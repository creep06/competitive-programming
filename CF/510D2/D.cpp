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



template<class T, int ME> class BIT {
	public:
	T bit[1<<ME],val[1<<ME];
	T sum(int e) {T s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	T add(int e,T v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	T set(int e,T v) { add(e,v-val[e]);}
	int lb(T v) {
		T tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<v) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};

// 必要な情報は累積和の数の種類数*2がたかだかだから座圧してBIT使えばいけそう
int n, t, a[200200], s[200200], ans, m;
set<int> x;
map<int,int> y;
BIT<int,20> b;

signed main() {
	cin >> n >> t;
	rep(i,n) {
		cin >> a[i];
		s[i] = (i==0 ? 0 : s[i-1]) + a[i];
		x.insert(s[i]), x.insert(s[i]+t-1);
	}
	each(i,x) y[i] = m++;
	rep(i,n) b.add(y[s[i]],1), ans += (s[i]<t);
	rep(i,n) {
		b.add(y[s[i]],-1);
		ans += b.sum(y[s[i]+t-1]);
	}
	cout << ans << endl;
}
