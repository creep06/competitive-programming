#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i);(i)<(n);(i)++)

int n, w[100], v[100], W, dp[101][10001];

int main() {
	cin >> n;
	rep(i,n) cin >> w[i] >> v[i];
	cin >> W;
	
	rep(i,n) {
		rep(j,W+1) {
			if (j<w[i]) dp[i+1][j] = dp[i][j];
			else dp[i+1][j] = max(dp[i][j], dp[i+1][j-w[i]]+v[i]);
		}
	}
	cout << dp[n][W] << endl;
}