#include <bits/stdc++.h>
using namespace std;

// initで頂点数を指定してsccで成分分解を実行 返り値は強連結成分の個数==grpのサイズ
// grp[i]:i番目の強連結成分に含まれる頂点一覧
// cmp[i]:頂点iが属する強連結成分の番号 この番号も⇡のiもトポロジカル順
class SCC {
	public:
	static const int MV = 100100;
	vector<vector<int> > grp; int NV,cmp[MV];
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) {vis[cu]=1; cmp[cu]=ind; grp[ind].push_back(cu);
		for(int i=0;i<RE[cu].size();++i) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	int scc() {
		int c=0; grp.clear(); grp.resize(MV); NUM.clear();
		memset(vis,0,sizeof(vis)); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		memset(vis,0,sizeof(vis)); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]])
			{ grp[c].clear(); revdfs(NUM[i],c); sort(grp[c].begin(),grp[c].end()); c++;}
		grp.resize(c); return c;
	}
};

int n, m, a, b, q;
SCC s;

int main() {
	cin >> n >> m;
	s.init(n);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		s.add(a,b);
	}
	s.scc();
	cin >> q;
	while (q--) {
		cin >> a >> b;
		cout << (s.cmp[a]==s.cmp[b]) << endl;
	}
}