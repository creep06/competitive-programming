#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rept(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
#define repst(i,s,n) for(int (i)=(s);(i)<=(int)(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > mat;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
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

ll n, x[100000], y[100000], minx = linf, miny = linf, maxx = -linf, maxy = -linf, d, px[2], py[2], X, Y;

signed main() {
	cin >> n;
	rep(i,n) {
		cin >> x[i] >> y[i];
		chmin(minx, x[i] + y[i]);
		chmax(maxx, x[i] + y[i]);
		chmin(miny, x[i] - y[i]);
		chmax(maxy, x[i] - y[i]);
	}
	// 回転後の正方形の1辺の長さ
	d = max(maxx-minx, maxy-miny) / 2;
	px[0] = maxx-d, px[1] = minx+d, py[0] = maxy-d, py[1] = miny+d;
	rep(i,2) {
		rep(j,2) {
			X = (px[i] + py[j])/2, Y = (px[i] - py[j])/2;
			bool f = true;
			reps(k,1,n) {
				if (abs(x[k-1]-X) + abs(y[k-1]-Y) != abs(x[k]-X) + abs(y[k]-Y)) {
					f = false;
					break;
				}
			}
			if (f) {
				cout << X << " " << Y << ln;
				return 0;
			}
		}
	}
}