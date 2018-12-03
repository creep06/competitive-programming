#include <bits/stdc++.h>
using namespace std;
long long a, b, c, k;

int main() {
	cin >> a >> b >> c >> k;
	cout << (k%2 ? b-a : a-b) << endl;
}