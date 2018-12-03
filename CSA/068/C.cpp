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
#define pb emplace_back
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

#define mt(x,y,z) make_tuple(x,y,z)

int n, x, y, r[100000], ans[100000];
tuple<int,int,int> p[100000];
pair<double,int> k[100000];
int jun[114514];

int bit[114514];

int sum(int i) {
	int s = 0;
	while (i>0) {
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x) {
	while (i<=n) {
		bit[i] += x;
		i += i & -i;
	}
}


signed main() {
	cin >> n;
	rep(i,n) {
		cin >> x >> y;
		p[i] = mt(x,y,i);
	}
	sort(p, p+n);
	// 座標p[i]では、それより手前の0,1,...,i-1番目の座標それぞれについて
	// 0-p[i]の傾きをkとすると、y<=kxならp[i]がその点を含む
	// つまりは自分より左側の、傾きが自分より小さいものの数を数え上げればいい
	// 全ての点の傾きを列挙しておけば各点が何個の三角形に含まれるかは二分探索とかでわかる
	// 傾きはdoubleになるけどintなら10^5のBIT使えばいけそう
	// 傾きはたかだか10^5個しかないからint型に圧縮できる？
	rep(i,n) {
		int id;
		tie(x,y,id) = p[i];
		double kata = 1.*y/x;
		k[i] = {kata,i};
	}
	sort(k, k+n);
	// p[i]の傾きは全傾きの中でi番目に小さい
	rep(i,n) {
		jun[k[i].se] = i;
	}
	rep(i,n) {
		r[i] = sum(jun[i]+1);
		add(jun[i]+1,1);
		int id;
		tie(x,y,id) = p[i];
		ans[id] = r[i];
	}
	rep(i,n) cout << ans[i] << ln;
}