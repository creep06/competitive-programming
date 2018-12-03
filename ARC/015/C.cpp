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

int n;
double d[444][444], r, t;
string a, b, ra, rb;
vector<string> s;
map<string, int> m;	// 文字列の番号付け 1-based

signed main() {
	cin >> n;
	rep(i,n) {
		cin >> a >> t >> b;
		if (m.find(a)==m.end()) s.pb(a), m[a] = m.size()-1;
		if (m.find(b)==m.end()) s.pb(b), m[b] = m.size()-1;
		d[m[b]][m[a]] = t;
		d[m[a]][m[b]] = 1.0/t;
	}
	n = m.size();
	rep(j,2) rep(i,n) rep(x,n) rep(y,n) {
		if (d[x][y]==0 && d[x][i]>0 && d[i][y]>0) d[x][y] = d[x][i] * d[i][y];
		if (d[x][y]==0 && d[x][i]>0 && d[y][i]>0) d[x][y] = d[x][i] / d[y][i];
	}
	rep(i,n) rep(j,n) {
		if (r<d[i][j]) {
			r = d[i][j];
			ra = s[j], rb = s[i];
		}
	}
	cout << 1 << ra << "=" << (ll)(r+0.1) << rb << ln;
}