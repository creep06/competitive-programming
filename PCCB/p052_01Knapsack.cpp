/*
4
2 3
1 2
3 4
2 2
5
 */
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

// dp[i+1][j]: i番目までの品物から重さの総和がj以下となるように選んだときの価値の総和の最大値
int n, w[100], v[100], W, dp[101][10001];

int main() {
	cin >> n;
	rep(i,n) cin >> w[i] >> v[i];
	cin >> W;
	
	rep(i,n) {
		rep(j,W+1) {
			if (j<w[i]) dp[i+1][j] = dp[i][j];
			else dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
			cout << dp[i+1][j] << " ";
		}
		cout << endl;
	}
	cout << dp[n][W] << endl;
}