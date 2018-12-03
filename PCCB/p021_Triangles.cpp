#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i);(i)<n;(i)++)

int n, a[100], ans;

int main() {
	cin >> n;
	rep(i,n) cin >> a[i];
	rep(i,n) rep(j,n) rep(k,n) {
		int len = a[i] + a[j] + a[k];
		int mx = max(a[i], max(a[j], a[k]));
		if (mx < len-mx) ans = max(ans, len);
	}
	cout << ans << endl;
}