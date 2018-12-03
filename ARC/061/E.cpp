#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(ll (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,n+1)
#define repst(i,s,n) reps(i,s,n+1)
#define reprt(i,n,t) for(ll (i)=(n);(i)>=t;--(i))
#define repr(i,n) reprt(i,n,0)
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
#define dbga(x,n) for(int (i)=0;i<n;++i){cout<<x[i]<<(i==n-1?'\n':' ');}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int> > mat;

const ll inf = (ll)1e9+10;
const ll linf = (ll)1e18+10;
const ll mod = (ll)(1e9+7);
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

// 一つのノードが複数の状態を持つグラフは状態ごとにノードを分割して解く
// 今回は会社1〜cmax全てから会社0にコスト1の辺を張ればいい 改札で乗り換えするイメージ
// ↓は素直に今いる路線と違う路線に乗るときコストを増やす実装

int n, m, p, q, c, d[100100];
vpii e[100100];
set<int> us[100100];

signed main() {
	cin >> n >> m;
	rep(i,m) {
		cin >> p >> q >> c;
		e[p].pb({q,c}), e[q].pb({p,c});
	}
	fill(d, d+n+1, inf);
	d[1] = 0;
	priority_queue<pii> q;
	q.push({0,1});
	while (!q.empty()) {
		int v = q.top().se, dis = -q.top().fi; q.pop();
		if (d[v]<dis) continue;
		each(i,e[v]) {
			int td = d[v];
			// 違う路線に乗り換え
			if (!us[v].count(i.se)) td++;
			if (td<d[i.fi]) {
				d[i.fi] = td;
				us[i.fi].clear();
				us[i.fi].insert(i.se);
				q.push({-d[i.fi],i.fi});
			}
			// i.fiへの行き方が同じコストで複数ある場合 都合良い方に乗ってきたことにすればいい
			else if (td==d[i.fi]) us[i.fi].insert(i.se);
		}
	}
	cout << (d[n]==inf ? -1 : d[n]) << ln;
}