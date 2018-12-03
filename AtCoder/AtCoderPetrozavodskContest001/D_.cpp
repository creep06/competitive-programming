#include <bits/stdc++.h>
using namespace std;

#define int long long
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

struct union_find {
	vector<int> p;
	union_find(int n) : p(n, -1) {};
	bool unite(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return false;
		if (p[u] > p[v]) swap(u, v);
		p[u] += p[v]; p[v] = u;
		return true;
	}
	bool same(int u, int v) { return find(u) == find(v); }
	int find(int u) { return p[u] < 0 ? u : p[u] = find(p[u]); }
	int usize(int u) { return -p[find(u)]; }
};

// まず最初の時点で何個の連結成分に分かれてるか、各連結成分に含まれる頂点の分類もする
// 一番大きい成分とその次に大きい成分を両成分のうち最も安価な2点でくっつけて何か問題ある？
// 例えばその2点のコストが100,101で、コスト1,1の2点を含む成分が別にあった場合
// 前者同士を接合するとコスト201、前者の2成分のうち残った点の中で最も安価なもののコストが102ならそこに1をつなげて103、合計304
// 後者の成分を橋にすると100+1, 101+1で計203 こういう場合に問題が起こる
//
// とりあえず連結成分でまとめた後、成分同士を繋ぐとしたら各成分に含まれる頂点をコストの昇順に使うのが最善なのは明らか
// となるとあとは成分を繋げる順番さえ考えればいいことになる
// 成分に含まれる点の中で2番目に安価な点のコストの昇順に繋げるべき？
// それが一番繋げた後のコストが減るやり方？
//
// 連結成分同士を既に繋いだかどうかはunionfindで管理？
// 繋いだ後はその2点のコストをinfとかにして使えなくする
// ここまで考えたけど他の人の解く速度的にもしかしてもっと単純なのでは？
// 最も安価な点2個をくっつけ続けるだけでいい？
// でもそうすると1点だけの成分で木を埋め尽くしてしまう可能性がある
// 1点の成分だけ後回しにすりゃいいのか？

int n, m, a[100000], x[100000], y[100000];
vi e[100000];

// 連結成分の分類
int cs;
vi c[100000];
bool used[100000];
vi cost[100000];
priority_queue<int, vector<int>, greater<int>> mon[100000];

void dfs(int v, int col) {
	used[v] = true;
	c[col].pb(v);
	each(i,e[v]) if (!used[i]) dfs(i,col);
}

signed main() {
	cin >> n >> m;
	rep(i,n) cin >> a[i];
	rep(i,m) {
		cin >> x[i] >> y[i];
		e[x[i]].pb(y[i]), e[y[i]].pb(x[i]);
	}
	rep(i,n) if (!used[i]) dfs(i,cs++);
	// 最初から連結な場合
	if (cs==1) {
		cout << 0 << ln;
		return 0;
	}
	// csごとに含まれる点のコストを昇順に並べとく
	// 2番目に低いコストとcs番号をキーにしてプライオリティーキューに突っ込む
	priority_queue<pii, vector<pii>, greater<pii>> que;
	vi ones;
	rep(i,cs) {
		if (c[i].size()==1) {
			ones.pb(i);
			continue;
		}
		each(j,c[i]) mon[i].push(a[j]);
		int mn = mon[i].top(); mon[i].pop();
		int mn2 = mon[i].top(); mon[i].push(mn);
		que.push(mp(mn2,i));
	}
	if (que.empty()) {
		cout << "Impossible" << ln;
		return 0;
	}
	//union_find uf(cs); // いらなくね？
	// mn2,mn1の昇順？
	int ans = 0;
	while (que.size()>1) {
		pii sm = que.top(); que.pop();
		pii bg = que.top(); que.pop();
		int ss = sm.se, bb = bg.se;
		// smとbgを繋ぐ
		int smc = mon[ss].top(); mon[ss].pop();
		int bgc = mon[bb].top(); mon[bb].pop();
		ans += smc + bgc;
		// bg側のコストを全部sm側に渡す
		if (mon[ss].size() < mon[bb].size()) swap(ss,bb);
		while (!mon[bb].empty()) {
			int ad = mon[bb].top(); mon[bb].pop();
			mon[ss].push(ad);
		}
		int mn = mon[ss].top(); mon[ss].pop();
		int mn2 = mon[ss].top(); mon[ss].push(mn);
		que.push(mp(mn2,ss));
	}
	int us = 0;
	int l = que.top().se;
	// 点を繋ぐ場所が足りない場合
	if (mon[l].size()<ones.size()) {
		cout << "Impossible" << ln;
		return 0;
	}
	each(i,ones) {
		int mn = mon[l].top(); mon[l].pop();
		ans += mn + a[i];
	}
	cout << ans << ln;
}