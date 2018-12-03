#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i);(i)<(n);(i)++)

int l, n, a, mx, mn;

int main() {
	cin >> l >> n;
	rep(i,n) {
		cin >> a;
		mx = max(mx, max(a, l-a));
		mn = max(mn, min(a, l-a));
	}
	cout << "min = " << mn << endl;
	cout << "max = " << mx << endl;
}