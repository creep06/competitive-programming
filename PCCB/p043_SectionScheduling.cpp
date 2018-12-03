#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i);(i)<(n);(i)++)

int n, t, ans;
pair<int, int> p[100000];

int main() {
	cin >> n;
	rep(i,n) cin >> p[i].second >> p[i].first;
	sort(p, p+n);
	// t: 最後に選んだ仕事の終了時間
	// 終了時間が早い順に貪欲に選ぶ
	rep(i,n) {
		if (t<p[i].second) {
			ans++;
			t = p[i].first;
		}
	}
	cout << ans << endl;
}