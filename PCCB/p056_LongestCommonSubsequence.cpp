#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i);(i)<(n);(i)++)

// dp[i][j]: sのi文字目までとtのi文字目までのLCSの長さ
int n, m, dp[1010][1010];
string s, t;

int main() {
	cin >> n >> m >> s >> t;
	rep(i,n) {
		rep(j,m) {
			// sのi+1文字目とtのj+1文字目が一緒の場合のLCSは、
			// sのi文字目とtのj文字目までのLCSの末尾にs[i+1] = t[j+1]を足したもの
			if (s[i]==t[j]) dp[i+1][j+1] = dp[i][j] + 1;
			// そうでない場合 sのi文字目までとtのj+1文字目までのLCS　または
			// sのi+1文字目までとtのj文字目までのLCS　のどちらか大きい方と一緒
			else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
		}
	}
	cout << dp[n][m] << endl;
}