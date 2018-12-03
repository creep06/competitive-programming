#include <bits/stdc++.h>
using namespace std;

template<typename V> struct SPA {
	private:
	vector<vector<V> > sp;
	public:
	SPA(int sz) { sp = vector<vector<V> >(sz, vector<V>(30, (1<<31)-1));}
	void init(int n, V a[]) {
		for (int i = 0; i < n; ++i) sp[i][0] = a[i];
		for (int k = 1; k < 30; ++k)
			for (int i = 0; i < n-1; ++i)
				if (i+(1<<(k-1))<n) sp[i][k] = min(sp[i][k-1], sp[i+(1<<(k-1))][k-1]);
	}
	V query(int l, int r) { // min [l,r)
		int m = 0;
		while (1<<(1+m)<=r-l) m++;
		return min(sp[l][m], sp[r-(1<<m)][m]);
	}
};

int n, r[114514], a[114514];
long long m, x, d, ans;
string s[114514];
vector<pair<string,int>> p;
SPA<int> spa(114514);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		p.push_back({s[i],i});
	}
	
	sort(p.begin(), p.end());
	for (int i = 0; i < n; ++i) r[p[i].second] = i;
	
	for (int i = 0; i < n-1; ++i) {
		int j = 0;
		for (; j < min(p[i].first.size(), p[i+1].first.size()); ++j) {
			if (p[i].first[j]!=p[i+1].first[j]) break;
		}
		a[i] = j;
	}
	spa.init(n,a);
	cin >> m >> x >> d;
	for (int i = 1; i <= m; ++i) {
		long long a = x/(n-1), b = x%(n-1);
		if (a>b) swap(a,b);
		else b++;
		x = (x+d) % ((long long)n*(n-1));
		int ra = r[a], rb = r[b];
		if (ra>rb) swap(ra,rb);
		//cout << a << ' ' << b << ' ' << lcp.q(ra,rb) << endl;
		ans += spa.query(ra,rb);
	}
	cout << ans << endl;
}