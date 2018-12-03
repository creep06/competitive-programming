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

int h, w, si, sj, ti, tj, d[500][500];
double l, r = 10, m, p[151515];
string s[500];

// m以上の明るさの区画だけを通ってゴールまで行けるか
bool bfs() {
	queue<pii> q;
	q.push(mp(si, sj));
	rep(i,h) fill(d[i], d[i]+w, inf);
	d[si][sj] = 0;
	while (!q.empty()) {
		int x = q.front().fi, y = q.front().se, dis = d[x][y];
		q.pop();
		rep(i,4) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx==ti && yy==tj) return true;
			if (xx<0 || h<=xx || yy<0 || w<=yy || s[xx][yy]=='#' || d[xx][yy]<=dis+1) continue;
			if ((s[xx][yy]-'0') * p[dis+1] < m) continue;
			d[xx][yy] = dis + 1;
			q.push(mp(xx, yy));
		}
	}
	return false;
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
	// 0.99のi乗
	p[0] = 1;
	repst(i,1,150000) p[i] = p[i-1] * 0.99;
	// 制限なしでもゴールに辿り着けない場合
	m = -1;
	if (!bfs()) {
		printf("-1\n");
		return 0;
	}
	// 通れる明るさの上限を二分探索
	while (r-l > 1e-10) {
		m = (r + l)/2;
		if (bfs()) l = m;
		else r = m;
	}
	printf("%.14lf\n",l);
}