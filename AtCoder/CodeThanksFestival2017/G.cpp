#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rept(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
#define repst(i,s,n) for(int (i)=(s);(i)<=(int)(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define each(itr,v) for(auto (itr):(v))
#define all(c) c.begin(),c.end()
#define pb push_back
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln << "\n"
#define show(x) cout << #x << " = " << x ln
#define dbg(x) cout<<#x"="<<x ln

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

// ⊂ニニニニニニニニニニニニニ( ^ω^)ニニニニニニニニニニニニニ⊃

int n, m, ans;
// e[i]のj桁目: 頂点iからjへの道があれば1
ll e[40];

// sel: 採用した頂点のビットが1 これのビットカウントでansを更新
// yet: dfsの中でまだ調査していない ∴ まだ使える頂点のビットが1
void dfs(ll sel, ll yet) {
	
	// まず次数が1以下の点(独立)は必ず採用して、その点と繋がっている点も使えないようにしていく
	bool cont = true;
	while (cont) {
		cont = false;
		rep(i,n) {
			if ((yet & 1ll<<i) && __builtin_popcountll(e[i]&yet)<=1) {
				sel |= 1ll<<i;	// 次数が1以下の頂点iを採用リストに追加
				yet ^= 1ll<<i;	// 今後頂点iを使えないようにする
				yet &= ~e[i];	// iと繋がっている点(1個か0個)も使えないようにする
				cont = true;
			}
		}
	}
	chmax(ans, __builtin_popcountll(sel));
	
	// ここまでで残っている点は全て次数が2以上
	// 次数が最も大きい頂点を選ぶ (もし存在しなければ終了)
	// 次数が大きいものを潰した方がその後次数が1以下の点が増えて分岐が減るから？
	int idx = -1, deg = 0;
	rep(i,n) {
		int d = __builtin_popcountll(e[i]&yet);	// iの次数
		if (yet & 1ll<<i && d>=2) {
			if (deg<d) {
				idx = i, deg = d;
			}
		}
	}
	
	if (idx>=0) {
		ll nsel = sel | 1ll<<idx;
		ll nyet = (yet ^ 1ll<<idx) & ~e[idx];
		dfs(nsel, nyet);	// 次数が最も大きい頂点を採用した状態でdfs
		dfs(sel, yet^(1ll<<idx));	// 採用しない状態でdfs
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	rep(i,m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a] |= 1ll<<b;
		e[b] |= 1ll<<a;
	}
	
	ll yet = (1ll<<n) - 1;
	dfs(0, yet);
	cout << ans ln;
}