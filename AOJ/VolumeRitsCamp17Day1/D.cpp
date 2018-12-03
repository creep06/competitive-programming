#include <bits/stdc++.h>
using namespace std;

int n;
string t;
set<string> s;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		int m = t.size();
		for (int l = 1; l <= 4; ++l) {
			for (int j = 0; j+l <= m; ++j) {
				s.insert(t.substr(j,l));
			}
		}
	}
	string res = "a";
	while (1) {
		if (!s.count(res)) return cout << res << endl, 0;
		for (int i = res.size()-1; i >= 0; --i) {
			if (res[i]<'z') {
				res[i]++;
				break;
			} else res[i] = 'a';
			if (i==0) res.push_back('a');
		}
	}
}