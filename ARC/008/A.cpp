#include <iostream>
using namespace std;
int n, t, r;
signed main() {
	cin >> n;
	t = n%10;
	r = n/10*100 + (t>=7 ? 100 : t*15);
	cout << r << '\n';
}