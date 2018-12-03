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

// タイプ1は閉路になってる部分があればそこに含まれる点は全部塗れない
// (a[i]を塗るためにはa[i]が塗られてないといけない、みたいなことになるから)
// 塗れない点の中にb[i]が含まれるならa[i]ももちろん塗れない
// 閉路検出はscc分解とか？
// タイプ2は "d[i]を塗らない" か "c[i]を塗ってからd[i]を塗る" の2通りの解釈ができる
// 最大10個しかないからどっちにするかは全列挙すればいい
// 後者はタイプ1と一緒 これ一つで色を塗る頂点の集合が "空" "c[i]" "c[i],d[i]" となる状況をカバーしているので、
// 残った"d[i]"をカバーするために前者でc[i]を禁止する必要がある

int n, A, B, x, y, a[100], b[100], c[10], d[10], r, t;
vi e[100];

class SCC {
	public:
	static const int MV = 100;
	vector<vector<int> > SC; int NV,GR[MV];
	private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
	public:
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
		rep(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0; SC.clear(); SC.resize(MV); NUM.clear();
		memset(vis,0,sizeof(vis)); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		memset(vis,0,sizeof(vis)); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
				SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
			}
		SC.resize(c);
	}
};

int calc(vi *e, bool *ng) {
	SCC scc;
	scc.init(n);
	rep(i,n) each(j,e[i]) scc.add_edge(i,j);
	scc.scc();
	// 同じ閉路に含まれる点は全て塗れない
	rep(i,scc.SC.size()) if (scc.SC[i].size()>1) each(j,scc.SC[i]) ng[j] = true;
	// 閉路(とか塗れない点全て)から繋がってる点も塗れない
	rep(i,n) rep(j,n) each(k,e[j]) ng[j] |= ng[k];
	return n - accumulate(ng, ng+n, 0);
}

signed main() {
	cin >> n >> A;
	rep(i,A) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
	}
	cin >> B;
	rep(i,B) {
		cin >> c[i] >> d[i];
		c[i]--, d[i]--;
	}
	
	rep(i,1<<B) {
		bool ng[n] = {};
		vi e[n];
		rep(j,A) e[a[j]].pb(b[j]);
		rep(j,B) {
			if (i>>j&1) e[d[j]].pb(c[j]);
			else ng[c[j]] = true;
		}
		chmax(r, calc(e,ng));
	}
	cout << r << ln;
}