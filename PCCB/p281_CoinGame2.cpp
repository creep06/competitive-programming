#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int n, k, a[100], x[1000000], grundy[10001];

int main() {
	cin >> n >> k;
	rep(i,k) cin >> a[i];
	rep(i,n) cin >> x[i];
	
	// 今の状態から1手で行ける状態のgrundy数に含まれていない最小の非負整数が今の状態のgrundy数になる
	// つまりgrundy数がxの状態からはgrundy数が0, 1, ..., x-1の状態へ行ける
	// grundy数は増えることがあるという点がNimと異なる 今回は相手に増やされたらその分だけ減らして元に戻せるので問題にならないが、
	// 同じ状態に戻る(状態がループする)場合は勝ち/負けじゃなく引き分けになることに注意
	// で全ての山のgrundy数を求めたら、それらはそれぞれの山の石の数に対応しているので
	// grundy[x1] xor grundy[x2] xor ... xor grundy[xn] が0以外なら勝ち、0なら負け
	// ということになる このやり方で勝敗を判定できるゲームはたくさんあるらしい
	
	// 0枚で自分に回ってきたら負け
	grundy[0] = 0;
	int maxx = *max_element(x, x+n);
	// 石がj個ある状態のgrundy数をdpで求める
	for (int j = 1; j <= maxx; ++j) {
		// 今の状態から1手で行ける状態のgrundy数を列挙
		set<int> s;
		for (int i = 0; i < k; ++i) {
			if (a[i]<=j) s.insert(grundy[j-a[i]]);
		}
		// 今の状態から1手で行ける状態のgrundy数の集合に含まれていない最小の非負整数が今の状態のgrundy数
		int g = 0;
		while (s.count(g)) g++;
		grundy[j] = g;
	}
	int xr = 0;
	for (int i = 0; i < n; ++i) xr ^= grundy[x[i]];
	if (x!=0) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}