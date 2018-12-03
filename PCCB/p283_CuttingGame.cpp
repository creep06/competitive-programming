#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int w, h, mem[201][201];

int grundy(int w, int h) {
	if (mem[w][h]) return mem[w][h];
	set<int> s;
	// ヨコ幅がiとw-iになるように2枚に切る(どっちも2以上になるように) 全てのiについて切った後の状態のgrundy数を列挙 タテ幅も同様
	for (int i = 2; w-i >= 2; ++i) s.insert(grundy(i, h) ^ grundy(w-i, h));
	for (int i = 2; h-i >= 2; ++i) s.insert(grundy(w,i ) ^ grundy(w, h-i));
	int res = 0;
	while (s.count(res)) res++;
	return mem[w][h] = res;
}

int main() {
	cin >> w >> h;
	rep(i,w) fill(mem[i], mem[i]+h, -1);
	
	// 最初はw*hの紙が1枚あって、それを切って2枚に分け、それらのgrundy数がg1,g2だったとする
	// するとそれらの2枚の紙がある状態のgrundy数をg1 xor g2として1つの数値で表せる
	// Nimにおいては山が何個でどんな状況であろうと、xorした結果が同じであれば勝敗の判定への影響は同じ
	// grundy数でも同様で、今回みたいに分裂が起こる場合でもそれらのxorをとってやれば、
	// その1つのgrundy数で複数のゲームが合わさったその状態を扱うことができ、grundy数を同様に求めることが出来る
	// 単にxorに結合法則が成り立つからこうなるとも言える
	// でこのゲームに戻り、紙を切り出すとき、幅1または高さ1の紙を切り出すと次に必ず1*1の紙を切り出すことができるので、
	// その時点で負けであることがわかる したがって紙を分割するときは必ず幅も高さも2以上になるように切る必要がある
	// 逆にどうしてもそのように切れない場合は負け この場合はgrundy数の定義により、特別に扱わなくてもgrundy数が0になる
	// (条件を満たす切り方が存在しないときは集合sが空になって、sに含まれない最小の非負整数は0になるため)
	if (grundy(w,h)!=0) cout << "WIN" << endl;
	else cout << "LOSE" << endl;
}