#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ヒストグラム中の長方形の面積の最大値を求めたい
//
// 面積最大の長方形の左端がL、右端がR、高さがHであるとする 区間[L,R)
// h[L-1]>=Hであれば左端をL-1にした方が長方形が大きくなるから、h[L-1]<Hであることがわかる
// 同様にh[R]<Hであることもわかる
// またHは min(h[i] | L<=i<R) である
//
// 長方形の高さを与えるiを固定して考える (長方形の高さはh[i])
// そういう長方形の中で面積最大のものの左端Lと右端Rは、↑のように考えると
// L: h[j-1]<h[i]であるような最大のj(<=i)
// R: h[j]<h[i]であるような最小のj(>i)
// となる
//
// L[i] = (j<=iかつh[j-1]<h[i]となるような最大のj)
// R[i] = (i<jかつh[j]<h[i]となるような最小のj)
// これらを計算できれば面積の最大値は max{h[i]*(R[i]-L[i]) | 0<=i<n} として求められる
// これはスタックを用いることで効率的に計算できる
//
// 空のスタックを用意し、次の性質を常に満たすようにすることで、この先Lの値となりうる要素をその順に保持する
// ・スタックに入っている値を上から順にx[i]としたとき、x[i]>x[i+1] かつ h[x[i]]>h[x[i+1]]
// L[i]を計算する際には、まずスタックの一番上の値jがh[j]>=h[i]である間取り出し続け、
// スタックが空になったらL[i]=0, h[j]<h[i]となったらL[i]=j+1とする
// その後スタックにiを追加する
// これで各L[i]がO(n)で計算でき、R[i]も同様に計算できる

int n, h[100100], l[100100], r[100100], st[100100], t;
stack<int> s;
long long res;

void pccb() {
	for (int i=0; i<n; i++) {
		while (t && h[st[t-1]]>=h[i]) t--;
		l[i] = (t==0 ? 0 : st[t-1]+1);
		st[t++] = i;
	}
	t = 0;
	for (int i=n-1; i>=0; i--) {
		while (t && h[st[t-1]]>=h[i]) t--;
		r[i] = (t==0 ? n : st[t-1]);
		st[t++] = i;
	}
	for (int i=0; i<n; i++) res = max(res, (long long)h[i] * (r[i]-l[i]));
	cout << res << endl;
}

void my() {
	for (int i=0; i<n; i++) {
		while (!s.empty() && s.top()>=h[i]) s.pop();
		l[i] = (s.empty() ? 0 : s.top()+1);
		s.push(i);
	}
	while (!s.empty()) s.pop();
	for (int i=n-1; i>=0; i--) {
		while (!s.empty() && s.top()>=h[i]) s.pop();
		r[i] = (s.empty() ? n : s.top());
		s.push(i);
	}
	for (int i=0; i<n; i++) res = max(res, (long long)h[i] * (r[i]-l[i]));
	cout << res << endl;
}

int main() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> h[i];
	my();
}
