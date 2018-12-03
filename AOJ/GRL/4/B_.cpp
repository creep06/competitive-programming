#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<int> e[10000];

vector<int> tsort(int n, vector<int> *e) {
	stack<int> st;
	int ny[n] = {};
	for (int i=0; i<n; ++i) for (auto j:e[i]) ny[j]++;
	for (int i=0; i<n; ++i) if (ny[i]==0) st.push(i);
	vector<int> res;
	while (!st.empty()) {
		int ne = st.top(); st.pop();
		res.push_back(ne);
		for (auto i:e[ne]) if (--ny[i]==0) st.push(i);
	}
	return res;
}

int main() {
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		e[a].push_back(b);
	}
	vector<int> r = tsort(n, e);
	for (int i=0; i<n; ++i) cout << r[i] << endl;
}