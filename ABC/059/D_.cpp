#include <bits/stdc++.h>
using namespace std;

long long x, y;

int main() {
	cin >> x >> y;
	cout << (abs(x-y)<=1 ? "Brown" : "Alice");
}