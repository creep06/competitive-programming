#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i);(i)<(n);(i)++)

int n, a[20], k;

// i:今見てる要素 s:今まで選んだ数の合計
bool rec(int i, int s) {
	// 0〜n-1番目全て見終わったらkと一致するかチェックして終了
	if (i==n) return s==k;
	// i番目の数を足さない場合と足す場合に分かれる
	return rec(i+1, s) || rec(i+1, s+a[i]);
}

int main() {
	cin >> n;
	rep(i,n) cin >> a[i];
	cin >> k;
	
	if (rec(0,0)) cout << "Yes" << endl;
	else cout << "No" << endl;
}