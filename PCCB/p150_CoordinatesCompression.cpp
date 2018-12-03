/*
10 10 5
1 6 4 4
1 10 8 8
4 4 1 10
9 9 1 5
10 10 6 10
 */
#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int w, h, n, X1[500], X2[500], Y1[500], Y2[500], ans;
bool fld[3000][3000];
queue<pair<int, int>> q;

// x1, x2を座標圧縮して圧縮された結果の幅を返す
int comp(int *x1, int *x2, int w) {
	vector<int> xs;
	rep(i,n) {
		for (int d = -1; d <= 1; ++d) {
			int tx1 = x1[i] + d, tx2 = x2[i] + d;
			if (1<=tx1 && tx1<=w) xs.push_back(tx1);
			if (1<=tx2 && tx2<=w) xs.push_back(tx2);
		}
	}
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	rep(i,n) {
		x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
		x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
	}
	return xs.size();
}

int main() {
	cin >> w >> h >> n;
	rep(i,n) cin >> X1[i] >> X2[i] >> Y1[i] >> Y2[i];
	
	// 座標圧縮
	w = comp(X1, X2, w);
	h = comp(Y1, Y2, h);
	
	// 線のある部分を塗りつぶし
	rep(i,n) {
		for (int y = Y1[i]; y <= Y2[i]; ++y) {
			for (int x = X1[i]; x <= X2[i]; ++x) {
				fld[y][x] = true;
			}
		}
	}
	
	//
	rep(i,h) {
		rep(j,w) {
			if (fld[i][j]) cout << '#';
			else cout << '.';
		}
		cout << endl;
	}
	
	// 領域を数えつつ塗りつぶす
	rep(y,h) {
		rep(x,w) {
			if (fld[y][x]) continue;
			ans++;
			q.push(make_pair(x, y));
			while (!q.empty()) {
				int sx = q.front().first, sy = q.front().second; q.pop();
				rep(i,4) {
					int tx = sx + dx[i], ty = sy + dy[i];
					if (tx<0 || w<=tx || ty<0 || h<=ty || fld[ty][tx]) continue;
					q.push(make_pair(tx, ty));
					fld[ty][tx] = true;
				}
			}
		}
	}
	cout << ans << endl;
}