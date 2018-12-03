#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i);(i)<(n);(i)++)
const int inf = 1145141919;

// dp[i]: 長さがi+1であるような増加部分列における最終要素の最小値 存在しない場合はinf
int n, a[1010], dp[1010];

int main() {
	cin >> n;
	rep(i,n) cin >> a[i];
	
	fill(dp, dp+n, inf);
	rep(i,n) *lower_bound(dp, dp+n, a[i]) = a[i];
	cout << lower_bound(dp, dp+n, inf) - dp << endl;
}