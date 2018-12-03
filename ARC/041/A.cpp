#include <iostream>
using namespace std;

int x, y, k;

signed main() {
	cin >> x >> y >> k;
	cout << x + min(y,k) - max(0,k-y) << '\n';
}