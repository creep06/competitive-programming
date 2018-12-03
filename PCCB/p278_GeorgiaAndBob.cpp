#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int n, p[1000], x;

int main() {
	cin >> n;
	rep(i,n) cin >> p[i];
	
	// 2つずつ駒をまとめて、2駒間の距離を各山の石の個数と考えるとNimに帰着される
	// 右の駒を左に動かすことがNimの山から石を取ることに対応する
	// 左の駒を左に動かすと山の石の個数が増えることになるが、返しのターンで右の駒を同じだけ動かして元に戻せるので考えなくていい
	if (n%2==1) p[n++] = 0;
	sort(p, p+n);
	for (int i = 0; i < n-1; i += 2) {
		x ^= (p[i+1] - p[i] - 1);
	}
	if (x==0) cout << "Bob will win" << endl;
	else cout << "Georgia will win" << endl;
}