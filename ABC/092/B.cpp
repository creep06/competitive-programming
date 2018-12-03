#include <bits/stdc++.h>
using namespace std;

int n, d, x, a, r;

int main() {
	cin >> n >> d >> x;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		for (int j = 1; j <= d; j += a) r++;
	}
	r += x;
	cout << r << endl;
}