#include <cstdio>
#include <algorithm>
#define inf 1001001001
using namespace std;
int N, s, dp[100000];
int main() {
	scanf("%d", &N);
	fill(dp, dp+N, inf);
	for (int i=0; i<N; i++) {
		scanf("%d", &s);
		*lower_bound(dp, dp+N, s) = s;
	}
	printf("%ld\n", (lower_bound(dp, dp+N, inf) - dp));
}