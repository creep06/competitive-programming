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

int h, w, si, sj, ei, ej, p[] = {0, 1, 2, 3}, r;
int di[4], dj[4];
string m[50], s;
bool goaled, broke;

void rec(int x, int y, int K) {
	if (K==s.length()) return;
	int gx = x + di[s[K]-'0'], gy = y + dj[s[K]-'0'];
	if (gx<0 || h<=gx || gy<0 || w<=gy || m[gx][gy]=='#') {
		broke = true;
		return;
	}
	if (gx==ei && gy==ej) {
		goaled = true;
		return;
	}
	rec(gx, gy, K+1);
}

signed main() {
	cin >> h >> w;
	rep(i,h) {
		cin >> m[i];
		rep(j,w) {
			if (m[i][j]=='S') si = i, sj = j, m[i][j] = '.';
			if (m[i][j]=='E') ei = i, ej = j, m[i][j] = '.';
		}
	}
	cin >> s;
	do {
		rep(j,4) di[j] = dx[p[j]], dj[j] = dy[p[j]];
		goaled = broke = false;
		rec(si, sj, 0);
		if (goaled && !broke) r++;
	} while (next_permutation(p, p+4));
	cout << r << ln;
}