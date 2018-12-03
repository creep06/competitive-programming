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

int k, x, y, d[300000];
string s;
// ある座標から上下左右に進んで止まる座標
map<pair<pii,int>, pii> t;

void q(int x, int y) {
	// (x,y)の上下左右
	rep(i,4) if (t.find(mp(mp(x, y), i)) == t.end()) t[mp(mp(x, y), i)] = {x+dx[i], y+dy[i]};
	// 上下左右の下上右左
	rep(i,4) {
		pii p = t[mp(mp(x, y), i)];
		t[mp(mp(p.fi, p.se), (i+2)%4)] = t[mp(mp(x, y), (i+2)%4)];
	}
}

signed main() {
	cin >> k >> s;
	rep(i,k) {
		if (s[i]=='U') d[i] = 0;
		else if (s[i]=='R') d[i] = 1;
		else if (s[i]=='D') d[i] = 2;
		else d[i] = 3;
	}
	
	q(0,0);
	rep(i,k) {
		pii p = t[mp(mp(x,y),d[i])];
		x = p.fi, y = p.se;
		q(x,y);
	}
	cout << x << ' ' << y << ln;
}