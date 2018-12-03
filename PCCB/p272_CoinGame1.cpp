#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int x, k, a[100];
bool dp[10101];

signed main() {
	cin >> x >> k;
	rep(i,k) cin >> a[i];
	
	// j枚のコインが残った状態で番が回ってきたとして、
	// 1) j=0なら負け
	dp[0] = false;
	for (int j = 1; j <= x; ++j) {
		dp[j] = false;
		for (int i = 0; i < k; ++i) {
			// 2) あるiについてj-a[i]が負けならjは勝ち (a[i]枚とって相手に番を渡せば相手は負ける)
			// 3) 全てのiについてj-a[i]が勝ちならjは負け (どんな取り方をしても相手に番を渡すと相手が勝つ)
			dp[j] |= (a[i]<=j && !dp[j-a[i]]);
		}
	}
	if (dp[x]) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}