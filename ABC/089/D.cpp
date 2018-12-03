#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,st,n) for(int (i)=(st);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto &(itr):(v))
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
#define bln(i,n) (i==n-1?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
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

// d>300なら愚直に計算すればいい O((HW)^2 /D)
// d<=300のときは累積和

int h, w, d, a[300][300], q, l, r;
ll imo[301][90001];
pii rev[100100];

signed main() {
	cin >> h >> w >> d;
	rep(i,h) rep(j,w) {
		cin >> a[i][j];
		rev[a[i][j]] = {i,j};
	}
	
	if (d>=300) {
		cin >> q;
		rep(i,q) {
			cin >> l >> r;
			ll ans = 0, x = rev[l].fi, y = rev[l].se;
			while (l<r) {
				int nx = rev[l+d].fi, ny = rev[l+d].se;
				ans += abs(nx-x) + abs(ny-y);
				x = nx, y = ny, l += d;
			}
			cout << ans << ln;
		}
	} else {
		// iからスタートしてdごとに進みjまで行くコスト
		rep(i,d) {
			for (int t = i+d; t <= h*w; t+=d) {
				if (t==d) continue;
				int x = rev[t].fi, y = rev[t].se, nx = rev[t-d].fi, ny = rev[t-d].se;
				imo[i][t] = abs(x-nx) + abs(y-ny);
			}
			repst(j,1,300*300) imo[i][j] += imo[i][j-1];
		}
		cin >> q;
		rep(i,q) {
			cin >> l >> r;
			int s = l%d;
			ll ans = imo[s][r] - imo[s][l];
			cout << ans << ln;
		}
	}
}