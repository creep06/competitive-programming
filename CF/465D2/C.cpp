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

double rad, fx, fy, mx, my;
double rx, ry, r;

// (bx,by)が中心(ax,ay)半径rの円の内側にあるかどうか
bool in(double ax, double ay, double r, double bx, double by) {
	return (ax-bx)*(ax-bx)+(ay-by)*(ay-by) <= r*r;
}

signed main() {
	cin >> rad >> fx >> fy >> mx >> my;
	if (!in(fx,fy,rad,mx,my)) {
		printf("%.10lf %.10lf %.10lf\n",fx,fy,rad);
		return 0;
	}
	if (fx==mx && fy==my) {
		printf("%.10lf %.10lf %.10lf\n",fx+rad/2,fy,rad/2);
		return 0;
	}
	double kx = mx-fx, ky = my-fy;
	r = (rad + sqrt((fx-mx)*(fx-mx) + (fy-my)*(fy-my)))/2.0;
	if (kx==0) {
		rx = fx;
		if (fy<my) ry = (my + fy-rad)/2.0;
		else ry = (my + fy+rad)/2.0;
	} else if (ky==0) {
		ry = fy;
		if (fx<mx) rx = (fx-rad + mx)/2.0;
		else rx = (fx+rad + mx)/2.0;
	} else {
		double ka = ky/kx;
		double sx = sqrt((r*r)/(1.0+ka*ka));
		double sy = ka*sx;
		if (fx<mx) {
			rx = mx-sx, ry = my-sy;
		} else {
			rx = mx+sx, ry = my+sy;
		}
	}
	printf("%.10lf %.10lf %.10lf\n",rx,ry,r);
}