#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(ll (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vld;
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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// Xの辺をa回、Yの辺をb回通ったときのS->Tの(整数が書いてある辺の重みのみを考慮した)最短距離をf(ab)とすると
// X=x,Y=yのときの最短距離は Dx,y = min(xa+yb+f(a,b)) となる
// dがたかだか100だからa・bの範囲は[0,100]で十分
// 頂点0〜100をXの辺で、101〜201をYの辺でつなぎ、
// S(0〜100)とT(101〜201)をコストfabの辺で繋ぐと総コストSX+(T-101)Y+fabのパスができる
// fabは任意の1<=x<=A, 1<=y<=Bに対しdxy<=xa+yb+fabを満たす条件の中で最も小さくするのが最善
// ∴ fab = max( 0, max(dxy-xa-yb) ) (0<=a,b<=100)
// これに従って辺を伸ばした後にちゃんとdを満たしているか確認すればok

int A, B, d[11][11], f[101][101];

signed main() {
	cin >> A >> B;
	repst(i,1,A) repst(j,1,B) {
		cin >> d[i][j];
		rept(a,100) rept(b,100) chmax(f[a][b], d[i][j]-i*a-j*b);
	}
	repst(i,1,A) repst(j,1,B) {
		int m = inf;
		rept(a,100) rept(b,100) chmin(m, i*a+j*b+f[a][b]);
		if (m!=d[i][j]) return cout << "Impossible" << ln, 0;
	}
	cout << "Possible" << ln << "202 10401" << ln;
	repst(i,1,100) cout << i << ' ' << i+1 << " X" << ln;
	repst(i,1,100) cout << i+101 << ' ' << i+102 << " Y" << ln;
	rept(a,100) rept(b,100) cout << a+1 << ' ' << b+102 << ' ' << f[a][100-b] << ln;
	cout << "1 202" << ln;
}