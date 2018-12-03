/*
dp[i][j]: jをi個以下の自然数に分割するパターンの総和 順序は無視
と定義すると↓こういう漸化式になる
dp[i][j] = dp[i][j-i] + dp[i-1][j]

右辺の2つの項について
1) jをi個に分割するパターンの総数
まずj個の品物からi個の箱へ1個ずつ入れてから、残ったj-i個をi個の箱へ振り分けていく
と考えられるのでdp[i][j-i]と書ける
2) jをi-1個以下に分割するパターンの総数
これはそのまんま dp[i-1][j]

本の解説はクソわかりづらい
http://techtipshoge.blogspot.jp/2011/01/blog-post_28.html
ここが参考になった
 */

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i);(i)<(n);(i)++)

int n, m, M, dp[1010][1010];

int main() {
	cin >> n >> m >> M;
	dp[0][0] = 1;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (j>=i) dp[i][j] = (dp[i-1][j] + dp[i][j-i]) % M;
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[m][n] << endl;
}