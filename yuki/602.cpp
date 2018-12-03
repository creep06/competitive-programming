#include <bits/stdc++.h>
using namespace std;

int n, x, y, t;
long long D;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;
	vector<long long> even, odd;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t%2==0) even.push_back(t);
		else odd.push_back(t);
	}
	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());
	cin >> x >> y;
	D = abs(x) + abs(y);
	
	if (D==0) {
		cout << 0 << "\n";
		return 0;
	}
	if (binary_search(even.begin(), even.end(), D)
		|| binary_search(odd.begin(), odd.end(), D)) {
		cout << 1 << "\n";
		return 0;
	}
	for (auto itr: even) {
		long long fr = abs(itr-D), to = itr + D;
		if ((to%2==0 && lower_bound(even.begin(), even.end(), to)
					   - lower_bound(even.begin(),even.end(), fr) > 0) ||
				(to%2==1 && lower_bound(odd.begin(), odd.end(), to)
							- lower_bound(odd.begin(),odd.end(), fr) > 0)) {
			cout << 2 << "\n";
			return 0;
		}
	}
	for (auto itr: odd) {
		long long fr = abs(itr-D), to = itr + D;
		if ((to%2==0 && lower_bound(even.begin(), even.end(), to)
						- lower_bound(even.begin(),even.end(), fr) > 0) ||
			(to%2==1 && lower_bound(odd.begin(), odd.end(), to)
						- lower_bound(odd.begin(),odd.end(), fr) > 0)) {
			cout << 2 << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
}