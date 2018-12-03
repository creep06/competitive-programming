#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int a, b, c, z;
	cin >> a >> b >> c;
	if (a==b) z = c;
	else if (b==c) z = a;
	else z = b;
	cout << z << endl;
}