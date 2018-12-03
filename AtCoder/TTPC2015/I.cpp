#include <bits/stdc++.h>
using namespace std;

int n, a[55];
vector<pair<int,int> > res;

signed main() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=n-1; i>=0; i--) while (a[i]!=i+1) {
		res.push_back({i+1-a[i], i+1});
		swap(a[i-a[i]], a[i]);
	}
	cout << res.size() << endl;
	for (auto i:res) cout << i.first << ' ' << i.second << endl;
}
