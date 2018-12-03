#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

string s;

int main() {
	getline(cin, s);
	rep(i,s.length()) if ('a'<=s[i] && s[i]<='z') s[i] = s[i] - 'a' + 'A';
	cout << s << '\n';
}