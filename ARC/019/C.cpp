#include <bits/stdc++.h>
using namespace std;

#define int long long
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

// d[0][i][j][k]: 村からマス(i,j)へ戦闘回数k回で移動するのに必要な最小移動回数 d[1],d[2]はそれぞれ出発点が祠、城
int H, W, K, si, sj, ci, cj, gi, gj, d[3][50][50][111], r = inf, t;
string s[50];

void bfs(int sx, int sy, int l) {
	queue<tuple<int,int,int>> q;
	q.push(make_tuple(sx, sy, 0));
	
	while (!q.empty()) {
		int x, y, k;
		tie(x,y,k) = q.front(); q.pop();
		rep(i,4) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx<0 || H<=xx || yy<0 || W<=yy || s[xx][yy]=='T') continue;
			if (s[xx][yy]=='E' && k==K) continue;
			if (d[l][xx][yy][k + (s[xx][yy]=='E')] <= d[l][x][y][k]+1) continue;
			d[l][xx][yy][k + (s[xx][yy]=='E')] = d[l][x][y][k] + 1;
			q.push(make_tuple(xx, yy, k + (s[xx][yy]=='E')));
		}
	}
}

/* これでなんでWA出るのかよくわかってない
void rec(int l, int k, int x, int y, int dis) {
	repst(i,k,K) d[l][i][x][y] = dis;
	if (l==1 && x==gi && y==gj) return;
	rep(t,4) {
		int xx = x + dx[t], yy = y + dy[t];
		if (xx<0 || H<=xx || yy<0 || W<=yy || s[xx][yy]=='T') continue;
		// 戦闘マス
		if (s[xx][yy]=='E') {
			if (k==K || d[l][k+1][xx][yy] <= dis+1) continue;
			s[xx][yy] = '.';
			rec(l, k+1, xx, yy, dis+1);
			s[xx][yy] = 'E';
		}
		// その他
		else {
			if (d[l | s[xx][yy]=='C'][k][xx][yy] <= dis+1) continue;
			rec(l | s[xx][yy]=='C', k, xx, yy, dis+1);
		}
	}
}
*/

signed main() {
	cin >> H >> W >> K;
	rep(i,H) {
		cin >> s[i];
		rep(j,W) {
			if (s[i][j]=='S') si = i, sj = j;
			if (s[i][j]=='G') gi = i, gj = j;
			if (s[i][j]=='C') ci = i, cj = j;
		}
	}
	// 村・祠・城の3点それぞれから全ての点への最短距離と必要な戦闘回数をBFSで求める
	rep(i,3) rep(j,H) rep(k,W) rept(l,K) d[i][j][k][l] = inf;
	d[0][si][sj][0] = d[1][ci][cj][0] = d[2][gi][gj][0] = 0;
	bfs(si, sj, 0), bfs(ci, cj, 1), bfs(gi, gj, 2);
	rep(i,H) rep(j,W) rept(k,K) d[1][i][j][k] *= 2;
	// 村→合流点、合流点→祠、祠→合流点、合流点→城 という経路の最小コストを求める
	// 全ての点(x,y)を合流点にしてみて調べる
	rep(x,H) rep(y,W) {
		if (s[x][y]=='T') continue;
		// k回戦闘して行ける点はk+1回以上戦闘しても行ける
		rep(i,3) rep(j,K) chmin(d[i][x][y][j+1], d[i][x][y][j]);
		// 村から合流点までi匹倒しながら行き、合流点から祠までj匹倒しながら行き、城から合流点までK-i-j匹倒しながら行く
		// i,jを0<=i+j<=Kの範囲で全探索
		// 合流点に敵がいる場合、 "村から合流点" と "城から合流点" それぞれのBFSで2重に倒したことになってることに注意
		if (s[x][y]=='E') {
			rept(i,K) rept(j,K-i) {
				t = d[0][x][y][i] + d[1][x][y][j+1] + d[2][x][y][K-i-j+1];
				chmin(r, t);
			}
		} else {
			rept(i,K) rept(j,K-i) {
				t = d[0][x][y][i] + d[1][x][y][j] + d[2][x][y][K-i-j];
				chmin(r, t);
			}
		}
	}
	if (r==inf) r = -1;
	cout << r << ln;
}