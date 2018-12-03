#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(ll (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,n+1)
#define repst(i,s,n) reps(i,s,n+1)
#define reprt(i,n,t) for(ll (i)=(n);(i)>=t;--(i))
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
#define dbga(x,n) cout<<#x" : "<<ln,for(int (i)=0;i<n;++i){cout<<x[i]<<(i==n-1?'\n':' ');}

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

/*
 * 少なくとも片方の点が盤面の周上にない組は無視していい ↓こんな感じで変形すればないのと同じ
 * https://drive.google.com/open?id=11LEYHGAANXY512nmcvHTOI3528ufQdvz
 * 両方の点が盤面の周上にある場合、それらを繋ぐとどうやっても盤面を2分するので繋げないペアが生まれる可能性がある
 * 点を(0,0)から周上の時計回りの距離の昇順に点を並べて、2点i,jについてi,j,i,jとなっていたらどうやっても交差する
 */

int h, w, n, xa, ya, xb, yb, m;
vpii p;
stack<int> s;

// (x,y)が周上にあるかどうか
bool online(int x, int y) {return x%w==0 || y%h==0;}

// 周上の原点からの距離
int d(int x, int y) {
	if (y==0) return x;
	if (x==w) return w+y;
	if (y==h) return w+h+(w-x);
	return w+h+w+(h-y);
}

signed main() {
	cin >> w >> h >> n;
	rep(i,n) {
		cin >> xa >> ya >> xb >> yb;
		if (online(xa,ya) && online(xb,yb)) {
			int da = d(xa,ya), db = d(xb,yb);
			p.pb({da,m}), p.pb({db,m++});
		}
	}
	sort(all(p));
	s.push(-1);
	each(i,p) {
		if (s.top()==i.se) s.pop();
		else s.push(i.se);
	}
	cout << (s.size()==1 ? "YES" : "NO") << ln;
}