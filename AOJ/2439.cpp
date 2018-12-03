#include <bits/stdc++.h>
using namespace std;
#define int long long

int i, j, n, dp[202][202], mod = 1e9+7;
char c[202];

signed main() {
	cin >> n;
	for(i=0; i<n; i++) {
		cin >> c[i];
		if (c[i]=='-') i--, n--;
	}
	dp[0][0] = 1;
	for(i=0; i<n; i++) for(j=0; j<n; j++) {
		if (c[i]=='D') {
			if (j) (dp[i+1][j-1] += dp[i][j]*j %mod *j) %= mod;
			(dp[i+1][j] += dp[i][j]*j) %= mod;
		}
		else {
			(dp[i+1][j] += dp[i][j]*j) %= mod;
			(dp[i+1][j+1] += dp[i][j]) %= mod;
		}
	}
	cout << dp[n][0] << endl;
}
