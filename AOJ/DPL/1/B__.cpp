// dp[W]
#include <iostream>
using namespace std;
int N, W, v, w;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> W;
	int dp[W+1] = {0};
	for (int i = 1; i <= N; ++i) {
		cin >> v >> w;
		for (int j = W; j >= w; --j)
			dp[j] = max(dp[j], dp[j-w]+v);
	}
	cout << dp[W] << "\n";
}