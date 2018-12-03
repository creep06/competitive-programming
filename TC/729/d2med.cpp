#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
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
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<n;++i){cout<<x[i]<<(i==n-1?'\n':' ');}}

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

class SoManyRectangles {
	public:
	int maxOverlap(vi xa, vi ya, vi xb, vi yb) {
		int n = xa.size();
		vpii xxa, yya;
		rep(i,n) {
			xxa.pb({xa[i],i});
			yya.pb({ya[i],i});
			xxa.pb({xb[i],i+n});
			yya.pb({yb[i],i+n});
		}
		// 座圧
		sort(all(xxa)), sort(all(yya));
		int dxa = 1, dya = 1;
		rep(i,n*2) {
			bool ru = false;
			if (xxa[i].se>=n) xxa[i].se -= n, ru = true;
			if (i>0 && xxa[i].fi!=xxa[i-1].fi) dxa++;
			(ru ? xb : xa)[xxa[i].se] = dxa;
			
			ru = false;
			if (yya[i].se>=n) yya[i].se -= n, ru = true;
			if (i>0 && yya[i].fi!=yya[i-1].fi) dya++;
			(ru ? yb : ya)[yya[i].se] = dya;
		}
		int imo[300][300];
		memset(imo,0,sizeof(imo));
		rep(i,n) imo[xa[i]][ya[i]]++, imo[xb[i]][yb[i]]++, imo[xa[i]][yb[i]]--, imo[xb[i]][ya[i]]--;
		rep(i,n) imo[xb[i]][yb[i]]--;
		rep(y,3*n) rep(x,3*n) imo[x+1][y] += imo[x][y];
		rep(x,3*n) rep(y,3*n) imo[x][y+1] += imo[x][y];
		int res = 1;
		rep(i,3*n) rep(j,3*n) chmax(res,imo[i][j]);
		return res;
	}
};