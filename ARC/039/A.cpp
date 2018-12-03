#include <iostream>
using namespace std;

int a, b, ta, tb;

signed main() {
	cin >> a >> b;
	// aを最大化
	if (a/100<9) ta = 900 + a%100;
	else if (a%100/10<9) ta = 990 + a%10;
	else ta = 999;
	// bを最小化
	if (b/100>1) tb = 100 + b%100;
	else if (b%100/10>0) tb = 100 + b%10;
	else tb = 100;
	// ⇡の操作のうち結果が大きくなる方を採用
	cout << max(a-tb, ta-b) << '\n';
}