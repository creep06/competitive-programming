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

// 同一行/列上の2点がYならそれらの列/行数は互いの定数倍で表せる
// ex) R1C1 = A, R1C2 = B なら C1 = (A/B) C2
// つまり軸に平行な四角形を作る4点のうち3点の面積がわかればもう1点の面積もわかる
// Nの点の面積がわからなければそこをYにするってのを繰り返す

class RectangleArea {
	public:
	vector<string> s;
	int h, w, res;
	
	void rec(int r, int c) {
		rep(i,h) rep(j,w) if (i!=r && j!=c) {
			int t = (s[i][j]=='Y') + (s[i][c]=='Y') + (s[r][j]=='Y');
			if (t!=2) continue;
			if (s[i][j]=='N') s[i][j] = 'Y', rec(i,j);
			else if (s[i][c]=='N') s[i][c] = 'Y', rec(i,c);
			else s[r][j] = 'Y', rec(r,j);
		}
	}
	
	int minimumQueries(vector<string> ss) {
		s = ss, h = s.size(), w = s[0].size();
		rep(i,h) rep(j,w) if (s[i][j]=='Y') rec(i,j);
		rep(i,h) rep(j,w) if (s[i][j]=='N') s[i][j] = 'Y', rec(i,j), res++;
		return res;
	}
};