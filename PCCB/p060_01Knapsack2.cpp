#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i);(i)<(n);(i)++)
const int inf = 1145141919;

// dp[i+1][j]: i番目までの品物から価値の総和がjとなるように選んだ時の重さの総和の最小値 (存在しない場合INF)
int n, w[100], v[100], W, dp[101][10101], r;

int main() {
	cin >> n;
	rep(i,n) cin >> w[i] >> v[i];
	cin >> W;
	
	rep(i,n+1) fill(dp[i], dp[i]+10001, inf);
	dp[0][0] = 0;
	rep(i,n) {
		rep(j,10001) {
			if (j<v[i]) dp[i+1][j] = dp[i][j];
			// 1) i-1番目までの品物から価値の総和がjとなるように選ぶ
			// 2) i-1番目までの品物から価値の総和がj-v[i]となるように選び、i番目の品物を加える
			else dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i]);
		}
	}
	rep(i,10001) if (dp[n][i]<=W) r = i;
	cout << r << endl;
}