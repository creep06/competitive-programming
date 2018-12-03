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

// クエリの範囲r-l+1をsとして、その範囲のi,jの組はs(s-1)/2個ある
// 元々その範囲にt個のinversionがあったとすると、操作後にinversionはs(s-1)/2 - t個になる
// 元々のinversionの個数はn^2で計算可能 累積和とっとけばO(1)で[l,r]の範囲のinversionの個数はわかる
// でもクエリごとに順列の並びが変わるから最初に計算したinversionの個数もどんどん変わっていく?
// 求められてるのは個数の偶奇のみってことは厳密な値は必要ない？

int n, a[1555], m, l, r, inv[1555], t, tt;
bool od;

signed main() {
	cin >> n;
	repst(i,1,n) cin >> a[i];
	repst(i,1,n-1) {
		repst(j,i+1,n) if (a[i]>a[j]) inv[i]++;
	}
	rept(i,n-1) inv[i+1] += inv[i];
	if (inv[n]%2) od = true;
	cin >> m;
	rep(i,m) {
		cin >> l >> r;
		tt = (r-l+1)*(r-l)/2;
		if (tt%2) od = 1 - od;
		if (od) cout << "odd" << ln;
		else cout << "even" << ln;
	}
}