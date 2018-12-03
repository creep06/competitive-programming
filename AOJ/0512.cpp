#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

string s;

int main() {
	cin >> s;
	rep(i,s.length()) {
		s[i] -= 3;
		if (s[i]<'A') s[i] += 26;
	}
	cout << s << '\n';
}