#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i);(i)<(n);(i)++)

// dp[i][j]: i番目までの和でjを作る際に余る最大のi番目の個数 (作れない場合は-1)
int n, a[101], m[101], k, dp[101][101010];

int main() {
	cin >> n;
	rep(i,n) cin >> a[i] >> m[i];
	cin >> k;
	
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	rep(i,n) {
		rep(j,k+1) {
			// i-1番目までで既にjを作れてるならi番目は1個も使わなくていい
			if (dp[i][j]>=0) dp[i+1][j] = m[i];
			// a[i]が作りたい数を超えてる or j-a[i]が作れない or j-a[i]を作った時点でa[i]を使い切った場合は無理
			else if (j<a[i] || dp[i][j-a[i]]<=0) dp[i+1][j] = -1;
			// それ以外ならj-a[i]を作るためにa[i]を使った個数から更にもう1個使って作れる
			else dp[i+1][j] = dp[i][j-a[i]] - 1;
		}
	}
}