#include <bits/stdc++.h>
using namespace std;

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
#define ln "\n"
#define show(x) cout << #x << " = " << x ln
#define dbg(x) cout<<#x"="<<x ln

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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

int n, m, q;
pair<int, pii> es[200000], qs[100000];

//----------------↓UnionFind↓----------------

int par[100000], rnk[100000], saiz[100000];

void init(int n) {
	for (int i=0; i<n; i++) {
		par[i] = i;
		rnk[i] = 0;
		saiz[i] = 1;
	}
}

int find(int x) {
	if (par[x]==x) return x;
	else return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x==y) return;
	if (rnk[x]<rnk[y]) par[x] = y;
	else {
		par[y] = x;
		if (rnk[x]==rnk[y]) rnk[x]++;
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

//----------------↑UnionFind↑----------------

int main() {
	cin >> n >> m;
	rep(i,m) {
		int a, b, y;
		cin >> a >> b >> y;
		a--, b--;
		es[i] = mp(y, mp(a,b));
	}
	sort(es, es+m);
	reverse(es, es+m);
	//rep(i,m) cout << es[i].fi << " " << es[i].se.fi << " " << es[i].se.se << ln;
	cin >> q;
	rep(i,q) {
		int v, w;
		cin >> v >> w;
		v--;
		qs[i] = mp(w, mp(v,i));
	}
	sort(qs, qs+q);
	reverse(qs, qs+q);
	//rep(i,q) cout << qs[i].fi << " " << qs[i].se.fi << " " << qs[i].se.se << ln;
	
	// 辺もクエリも年の降順にソートした
	// こうすることでクエリを処理していくに連れて使える辺が単調に増えていく
	// unionfindで、クエリiではes[j].fiがqs[i].fiより大きい道を全て結合すればいい
	// 木一本に属している頂点の数を求めたいので、各頂点の根にサイズを格納しておく
	// 例えばサイズ3の木に属する点uとサイズ6の〜頂点vを結合するとき、uとvそれぞれの親がu'、v'であるとして
	// サイズ配列s[u']、s[v']それぞれに他方を足してやればいい
	
	init(n);
	int idx = 0;
	int ans[q];
	rep(i,q) {
		while(idx<m && es[idx].fi > qs[i].fi) {
			int x = es[idx].se.fi, y = es[idx].se.se;
			if (!same(x,y)) {
				int xp = find(x), yp = find(y);
				saiz[xp] = saiz[yp] = saiz[xp] + saiz[yp];
				unite(x,y);
			}
			idx++;
		}
		ans[qs[i].se.se] = saiz[find(qs[i].se.fi)];
	}
	rep(i,q) cout << ans[i] << ln;
}