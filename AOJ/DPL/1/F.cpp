#include<bits/stdc++.h>
using namespace std;
int N, W, v, w, a, dp[101][10001];

int main() {
	scanf("%d %d", &N, &W);
	fill(dp[0], dp[0]+N*100+1, 1001001001);
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &v, &w);
		for (int j = 0; j <= N*100; ++j) {
			if (j<v) dp[i+1][j] = dp[i][j];
			else dp[i+1][j] = min(dp[i][j], dp[i][j-v]+w);
		}
	}
	for (int j = 0; j <= N*100; ++j)
		if (dp[N][j]<=W) a = j;
	printf("%d\n", a);
}