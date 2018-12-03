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

ll n, a[114514], c[114514], m, r = 1, s, t;

ll mpow(ll x, ll n) {
	ll res = 1;
	while (n>0) {
		if (n&1) res = res * x %mod;
		x = x * x %mod;
		n >>= 1;
	}
	return res;
}

signed main() {
	cin >> n >> a[0];
	c[a[0]]++;
	m = a[0];
	reps(i,1,n) {
		cin >> a[i];
		c[a[i]]++;
		chmax(m, a[i]);
	}
	if (a[0]!=0 || c[0]>=2) {
		cout << 0 << ln;
		return 0;
	}
	
	// 2頂点間に辺を張れる条件は、2点の原点からの距離の差が1以下であること 0と1で場合分けする
	// ∵ 2以上のとき辺を張ると原点から2点のうち遠い方への最短距離が変わっちゃうから
	repst(i,1,m) {
		s = c[i-1], t = c[i];
		// <距離の差が0の場合>
		// 張っても張らなくても何も影響がない
		// a[i]=cであるiがk個あるとすると距離cの頂点間の辺の張り方は2^(k*(k-1)/2)通り
		r *= mpow(2, t*(t-1)/2);
		r %= mod;
		// <距離の差が1の場合>
		// 距離i+1の点たちからは最低1本はiの頂点のどれかに辺が張られている必要がある(そうじゃないと連結にならない)
		// それ以外は張っても張らなくてもいい
		// これは原点からの距離の差がiである点の数をs, i+1である点の数をtとすると(2^s - 1)^t通り
		r *= mpow(mpow(2, s) - 1, t);
		r %= mod;
	}
	cout << r << ln;
}