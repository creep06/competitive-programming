#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int n, m, o;
pair<int,int> p[100];
bool f;

int main() {
	while (scanf("%d %d",&n,&m) && (n||m)) {
		vector<int> r[1010];
		f = true;
		rep(i,m) p[i] = make_pair(0, i);
		rep(i,n) {
			rep(j,m) {
				scanf("%d",&o);
				p[j].first += o;
			}
		}
		rep(i,m) r[p[i].first].push_back(p[i].second);
		for (int i = n; i >= 0; --i) {
			sort(r[i].begin(), r[i].end());
			rep(j,r[i].size()) {
				if (!f) printf(" ");
				printf("%d",r[i][j]+1);
				f = false;
			}
		}
		printf("\n");
	}
}