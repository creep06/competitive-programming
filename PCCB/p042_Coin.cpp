#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i);(i)<(n);(i)++)

int c[6], v[] = {1, 5, 10, 50, 100, 500}, a, r;

int main() {
	rep(i,6) cin >> c[i];
	cin >> a;
	for (int i = 5; i >= 0; i--) {
		int t = min(a/v[i], c[i]);
		a -= t * v[i];
		r += t;
	}
	cout << r << endl;
}