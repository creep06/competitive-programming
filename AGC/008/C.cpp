#include <bits/stdc++.h>
using namespace std;

long long i, o, j, l, t;

signed main() {
	cin >> i >> o >> t >> j >> l;
	cout << o + max(i/2*2 + j/2*2 + l/2*2, (i&&j&&l ? (i-1)/2*2 + (j-1)/2*2 + (l-1)/2*2 + 3 : 0));
}