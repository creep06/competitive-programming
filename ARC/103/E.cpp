#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
	cin >> s;
	n = s.size();
	if (s[0]=='0' || s[n-1]=='1') return cout << -1 << endl, 0;
	for(int i=1; i<n-1; i++) if (s[i-1]!=s[n-i-1]) return cout << -1 << endl, 0;
	int p = n;
	for (int i=n-1; i>=1; i--) {
		cout << i << ' ' << p << endl;
		if (s[i-1]=='1') p = i;
	}
}
