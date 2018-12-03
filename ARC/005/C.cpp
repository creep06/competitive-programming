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

const int inf = 1001001001;
const int mod = 1000000007;
const ll linf = 1001001001001001001ll;
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

int h, w, si, sj, ti, tj;
bool d[500][500][3];	// マス(i,j)に計k回以上壁を壊して到達できた
string s[500];

bool rec(int x, int y, int b) {
	repst(i,b,2) d[x][y][i] = true;
	bool f = false;
	rep(i,4) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx<0 || h<=xx || yy<0 || w<=yy) continue;
		if (xx==ti && yy==tj) return true;
		if (s[xx][yy]=='.' && !d[xx][yy][b]) f += rec(xx, yy, b);
		else if (b<=1 && !d[xx][yy][b+1]) f += rec(xx, yy, b+1);
	}
	return f;
}

signed main() {
	cin >> h >> w;
	rep(i,h) {
		cin >> s[i];
		rep(j,w) {
			if (s[i][j]=='s') si = i, sj = j;
			if (s[i][j]=='g') ti = i, tj = j;
		}
	}
	if (rec(si, sj, 0)) cout << "YES" << ln;
	else cout << "NO" << ln;
}