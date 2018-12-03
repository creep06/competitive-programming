#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define each(itr,v) for(auto &(itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define dbg(x) cout<<#x" = "<<(x)<<ln<<flush
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ')<<flush;}}

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

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// 0がない) 二分探索
// 0がある) 0じゃない数が1個ならYes 0個ならNo そうじゃなければ0が1個ならそれについてだけ探索、2個以上なら無理
// 積がMAXllを超えるなら1個変えたくらいじゃ絶対積>>和を解消できないからNo

class PerfectSequences {
	public:
	string fixIt(vector<int> a) {
		ll n = a.size(), s = accumulate(all(a),0ll), p = 1, z = count(all(a),0);
		if (n==1) return "Yes";
		each(i,a) if (i!=0) {
			if (LONG_LONG_MAX/i<p) return "No";
			else p *= i;
		}
		
		if (z) {
			if (n-z==0) return "No";
			if (n-z==1) return "Yes";
			if (z>=2) return "No";
			// 1個だけある0を変える
			ll l = 0, r = min(LONG_LONG_MAX/p, LONG_LONG_MAX-s);
			while (1<r-l) {
				ll m = (l-r)/2+r;
				if (s+m>=p*m) l = m;
				else r = m;
			}
			if (s+l==p*l) return "Yes";
			return "No";
		}
		
		each(i,a) {
			s -= i, p /= i;
			ll l = 0, r = min(LONG_LONG_MAX/p, LONG_LONG_MAX-s);
			while (1<r-l) {
				ll m = (l-r)/2+r;
				if (s+m>=p*m) l = m;
				else r = m;
			}
			cout << i << ' ' << l << " / ";
			if (s+l==p*l && l!=i) return "Yes";
			s += i, p *= i;
		}
		return "No";
	}
};