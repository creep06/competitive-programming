#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int n, a[1000000], x;

int main() {
	cin >> n;
	rep(i,n) cin >> a[i];
	// Nimの勝敗の判別はxorを使って
	// a[1] xor a[2] xor ... xor a[n] != 0 -> 勝ちの状態
	// a[1] xor a[2] xor ... xor a[n] == 0 -> 負けの状態
	// つまり初期状態の全てのa[i]のxorが0でなければ先攻(Alice)が勝ち、0なら後攻(Bob)が勝つ
	// (1) xorが0の状態から1つ以上石を取るとxorは必ず0ではなくなる
	// (2) xor結果の最上ビットが立っている山から適切な個数だけ石を取るとxorを0にできる
	// これらから勝ち<=>負けの状態に自由に遷移できることがわかる
	rep(i,n) x ^= a[i];
	if (x!=0) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}
