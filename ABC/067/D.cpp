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
#define dbg(x) cout<<#x" = "<<x ln

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

int n, a, b, t, l, r;
vector<vi> e(100000);
int d0[100000], dn[100000];

void dfs0(int v, int d) {
	d0[v] = d;
	rep(i,e[v].size()) {
		t = e[v][i];
		if (d0[t]==inf) dfs0(t, d+1);
	}
}

void dfsn(int v, int d) {
	dn[v] = d;
	rep(i,e[v].size()) {
		t = e[v][i];
		if (dn[t]==inf) dfsn(t, d+1);
	}
}

int main() {
	cin >> n;
	rep(i,n-1) {
		cin >> a >> b;
		a--, b--;
		e[a].pb(b);
		e[b].pb(a);
	}
	
	// dfsで0からの最短距離とn-1からの最短距離を全ての点について求める
	// d0[i]<=dn[i]なら先手(Fennecくん)がそのマスを塗れる
	fill(d0, d0+n, inf);
	dfs0(0, 0);
	fill(dn, dn+n, inf);
	dfsn(n-1, 0);
	rep(i,n) {
		if (d0[i]<=dn[i]) l++;
		else r++;
	}
	if (l>r) cout << "Fennec" << ln;
	else cout << "Snuke" << ln;
}