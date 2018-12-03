#include <bits/stdc++.h>
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

typedef complex<double> P;
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

template < typename T > std::string to_string( const T& n )
{
	std::ostringstream stm ;
	stm << n ;
	return stm.str() ;
}

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

ll s, l = -1, r = linf;

// mまでの文字列の長さ
ll len(ll m) {
	if (m==0) return 0;
	ll f = 0, b = 0, fb = 0, nm = 0, le = 1, ri = 10, sz = 1;
	while (ri<=m) {
		ll tf = (ri-1)/3 - f, tb = (ri-1)/5 - b, tfb = (ri-1)/15 - fb;
		f += tf, b += tb, fb += tfb;
		nm += ((ri-le) - (tf+tb-tfb))*sz;
		le *= 10, ri *= 10, sz++;
		if (nm>linf) return linf;
	}
	ri = m;
	ll tf = ri/3 - f, tb = ri/5 - b, tfb = ri/15 - fb;
	f += tf, b += tb;
	nm += ((ri-le+1) - (tf+tb-tfb))*sz;
	double sum = 1.*f*4 + 1.*b*4 + 1.*nm;
	if (sum>linf) return linf;
	else return f*4 + b*4 + nm;
}

string mk(ll m) {
	string res;
	while (res.size()<=20+s) {
		if (m%15==0) res += "FizzBuzz";
		else if (m%3==0) res += "Fizz";
		else if (m%5==0) res += "Buzz";
		else res += to_string(m);
		m++;
	}
	return res;
}

signed main() {
	cin >> s;
	while (r-l>1) {
		ll m = (r+l)/2;
		if (len(m)<s) l = m;
		else r = m;
	}
	s -= len(l)+1;
	cout << mk(l+1).substr(s,20) << ln;
}