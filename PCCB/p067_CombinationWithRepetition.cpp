/*
dp[i+1][j]: i番目までの品物からj個選ぶ組み合わせの総数
とすると、i番目までの品物からj個選ぶためには、i-1番目までの品物からj-k個選んで、i番目の品物をk個加えればいいので
dp[i+1][j] = Σdp[i][j-k] ( kは0〜min(j, a[i]) )
= Σdp[i][j-1-k] + dp[i][j] - dp[i][j-1-a[i]] ( kは0〜min(j-1, a[i]) )
第1項) dp[i][j-k]のk=1〜a[i]+1の部分
第2項) dp[i][j-k]のk=0の部分
第3項) 第1項で足したdp[i][j-k]のk=a[i]+1の部分が余計なので引く
j-1<a[i]のときはdp[i][j-1-a[i]]が存在しないのでいらないことに注意
 */

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i);(i)<(n);(i)++)

int n, m, a[1010], M, dp[1010][1010];

int main() {
	cin >> n >> m;
	rep(i,n) cin >> a[i];
	cin >> M;
	
	rep(i,n+1) dp[i][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (j-1-a[i]>=0) dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][j-1-a[i]] + M) %M;
			else dp[i+1][j] = (dp[i+1][j-1] + dp[i][j]) %M;
		}
	}
	cout << dp[n][m] << endl;
}