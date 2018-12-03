#include <bits/stdc++.h>
using namespace std;

int n, a[10101], b[10101], m, x, y, d[1010];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		for (int j = 0; j < n; ++j) if (x<=a[j] && b[j]<=y) d[i]++;
	}
	int mx = *max_element(d,d+m);
	if (mx==0) cout << 0 << endl;
	else for (int i = 0; i < m; ++i) if (d[i]==mx) cout << i+1 << endl;
}