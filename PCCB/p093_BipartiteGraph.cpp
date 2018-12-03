#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int n, m, a, b, color[1000];
vector<int> e[1000];

bool rec(int v, int c) {
	color[v] = c;
	rep(i,e[v].size()){
		if (color[e[v][i]]==c) return false;
		if (color[e[v][i]]==0 && !rec(e[v][i], -c)) return false;
	}
	return true;
}

int main() {
	cin >> n >> m;
	rep(i,m) {
		cin >> a >> b;
		e[a].push_back(b), e[b].push_back(a);
	}
	rep(i,n) {
		if (color[i]==0) {
			if (!rec(i,1)) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}