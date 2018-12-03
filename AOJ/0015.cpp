#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int n;
string s, t, ans;

string p(const string &s, const string &t) {
	string res;
	int l1 = s.length()-1, l2 = t.length()-1;
	int L = max(l1, l2);
	int pre = 0;
	for (int i = 0; i <= L; ++i) {
		int sum = pre;
		sum += (l1>=0 ? s[l1--]-'0' : 0);
		sum += (l2>=0 ? t[l2--]-'0' : 0);
		pre = sum/10;	// 繰り上げ分
		sum -= pre*10;
		res += '0' + sum;
	}
	if (pre) res += '0' + pre;
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	rep(T,n) {
		cin >> s >> t;
		ans = p(s, t);
		if (ans.length() > 80) cout << "overflow" << endl;
		else cout << ans << endl;
	}
}