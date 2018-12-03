#include <utility>
#include <iostream>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rept(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
#define repst(i,s,n) for(int (i)=(s);(i)<=(int)(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define each(itr,v) for(auto (itr):(v))
#define all(c) c.begin(),c.end()
#define pb push_back
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln << "\n"
#define show(x) cout << #x << " = " << x ln
#define dbg(x) cout<<#x"="<<x ln

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> PP;
struct edge {
	int to,cost;
	edge(int t, int c):to(t),cost(c) {}
};

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

//--------------------------------------------------

int w, h, ans, f[21][21];

void dfs(int s, int x, int y) {
	if (s>=ans) return;
	for (int i = 0; i < 4; ++i) {
		int mx = x + dx[i];
		int my = y + dy[i];
		// すぐ隣がブロックなら動かない
		if (mx<0 || w<=mx || my<0 || h<=my || f[my][mx]==1) continue;
		
		// そうじゃなければその方向に、盤外に出るか壁にぶつかるまで滑り続ける
		while (true) {
			// ゴールに着いた場合 答えを更新
			if (f[my][mx]==3) {
				ans = s;
				return;
			}
			mx += dx[i]; my += dy[i];
			// 盤外に出ちゃった場合
			if (mx<0 || w<=mx || my<0 || h<=my) break;
			// 壁にめりこんじゃった場合
			if (f[my][mx]==1) {
				// 壁を一時的に消して、
				f[my][mx] = 0;
				// めりこむ直前の座標でdfsし、
				dfs(s+1, mx-dx[i], my-dy[i]);
				// 終わったら壁をそっと元に戻す
				f[my][mx] = 1;
				break;
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	while (cin >> w >> h && (w||h)) {
		int sx,sy;
		rep(i,h) {
			rep(j,w) {
				cin >> f[i][j];
				if (f[i][j]==2) {
					sy = i;
					sx = j;
					f[i][j] = 0;
				}
			}
		}
		
		ans = 11;
		dfs(1, sx, sy);
		if (ans==11) cout << -1 ln;
		else cout << ans ln;
	}
}