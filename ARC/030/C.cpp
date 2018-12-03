#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rept(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
#define repst(i,s,n) for(int (i)=(s);(i)<=(int)(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > mat;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double eps = 1e-10;

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

const int MAX_V = 300;

int v, e, a, b, K, s, t;
char c[300];
vector<int> g[MAX_V];	// グラフの隣接リスト表現
vector<int> rg[MAX_V];	// 辺の向きを逆にしたグラフ
vector<int> vs;			// 帰りがけ順(post-order)の並び
bool used[MAX_V];		// 既に調べたか
int cmp[MAX_V];			// 属する強連結成分のトポロジカル順序
vector<int> dg[MAX_V];	// 各強連結成分を頂点とみなしたDAGの有向辺
string dp[333][333];

void add_edge(int from, int to) {
	g[from].push_back(to);
	rg[to].push_back(from);
}

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) dfs(g[v][i]);
	}
	vs.push_back(v);
}

void rdfs(int v, int k) {
	used[v] = true;
	cmp[v] = k;
	for (int i = 0; i < rg[v].size(); ++i) {
		if (!used[rg[v][i]]) rdfs(rg[v][i], k);
	}
}

int scc() {
	memset(used, 0, sizeof(used));
	vs.clear();
	for (int i = 0; i < v; ++i) {
		if (!used[i]) dfs(i);
	}
	memset(used, 0, sizeof(used));
	int k = 0;
	for (int i = vs.size()-1; i >= 0; --i) {
		if (!used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}

void dag(int v) {
	used[v] = true;
	int from = cmp[v];
	rep(i,g[v].size()) {
		int u = g[v][i];
		int to = cmp[u];
		if (from!=to) dg[from].pb(to);
		if (used[u]) continue;
		dag(g[v][i]);
	}
}

vi tsort(int v, vi *e) {
	stack<int> st;
	int ny[v] = {0};
	rep(i,v) each(j,e[i]) ny[j]++;
	rep(i,v) {
		if (ny[i]) continue;
		st.push(i);
	}
	vi res;
	while (!st.empty()) {
		int ne = st.top(); st.pop();
		res.pb(ne);
		each(j,e[ne]) if (--ny[j]==0) st.push(j);
	}
	return res;
}

signed main() {
	cin >> v >> e >> K;
	rep(i,v) cin >> c[i];
	rep(i,e) {
		cin >> a >> b;
		add_edge(a-1,b-1);
	}
	
	// 強連結成分ごとに文字を分類
	// 次のグループに進んだら前のグループには戻れない制約の下でk個好きな順番で回収して辞書順最小にしたい
	// 事前にソートしておけば各グループで手前から何個取るかだけ考えればよくなる
	s = scc();
	vector<string> cs(s);
	rep(i,v) cs[cmp[i]] += c[i];
	rep(i,s) sort(all(cs[i]));
	// cmpの番号を基にDAGを作る
	memset(used, 0, sizeof(used));
	rep(i,v) if (!used[i]) dag(i);
	// その頂点をトポロジカルソート
	vi to = tsort(s, dg);
	
	// dpで答えを作る
	// トポロジカル順序の後ろから「その点以降の辞書順最小の文字列」を確定させていけばいい
	repr(I,s-1) {
		int i = to[I];
		rept(j,cs[i].length()) {
			// i番目の強連結成分のj文字のみから作るパターン
			string tp = cs[i].substr(0,j);
			if (dp[i][j].empty() || dp[i][j]>tp) dp[i][j] = tp;
			// to[i]から行ける点m以降で作れる辞書順最小のl文字の手前にj文字くっつけてj+l文字を作り更新
			each(m,dg[i]) {
				rept(l,K-j) {
					if (l>0 && dp[m][l].empty()) break;
					// まだi番目以降で辞書順最小のj+l文字の候補が存在しない、または既存のものより辞書順で小さい場合更新
					string tmp = tp + dp[m][l];
					if (dp[i][j+l].empty() || dp[i][j+l]>tmp) dp[i][j+l] = tmp;
				}
			}
		}
	}
	
	string ans;
	rep(i,s) {
		if (dp[i][K].empty()) continue;
		if (ans.empty() || ans>dp[i][K]) ans = dp[i][K];
	}
	if (ans.empty()) cout << -1 << ln;
	else cout << ans << ln;
}