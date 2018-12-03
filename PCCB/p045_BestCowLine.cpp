#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i);(i)<(n);(i)++)

int n, l, r;
string s, t, ans;

int main() {
	cin >> n >> s;
	r = n-1;
	while (l<=r) {
		if (s[l]<s[r]) ans += s[l++];
		else if (s[l]>s[r]) ans += s[r--];
		// 先頭と末尾が一緒ならsubstrとその反転の比較でどっちを切り取るか決める
		// 例えばACBAなら反転したABCAの方が辞書順で小さいので末尾のAを切り取る
		else {
			ans += s[l];
			t = s.substr(l,r-l+1);
			reverse(t.begin(), t.end());
			if (s.substr(l,r-l+1) < t) l++;
			else r--;
		}
	}
	cout << ans << endl;
}