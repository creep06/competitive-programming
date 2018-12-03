#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define rept(i,n) for(ll (i)=0;(i)<=(ll)(n);(i)++)
#define reps(i,s,n) for(ll (i)=(s);(i)<(ll)(n);(i)++)
#define repst(i,s,n) for(ll (i)=(s);(i)<=(ll)(n);(i)++)
#define repr(i,n) for(ll (i)=(n);(i)>=0;(i)--)
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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

ll n, a[50], b[50], k[50], x, y, X = 1, Y, t, m;

int main() {
	cin >> n >> x >> y;
	rep(i,n) cin >> a[i];
	sort(a, a+n);
	if (x==1) {
		rep(i,n) cout << a[i] << ln;
		return 0;
	}
	// m: a[0]..a[n-2]それぞれにxをかけていって全てa[n-1]以上にするために必要な操作回数
	rep(i,n) {
		b[i] = a[i];
		while (b[i]<a[n-1]) b[i] *= x, m++;
	}
	// yがm以下なら素直にシミュレート
	if (y<=m) {
		rep(i,y) {
			a[0] *= x;
			sort(a, a+n);
		}
		rep(i,n) cout << a[i]%mod << ln;
		return 0;
	}
	sort(b, b+n);
	rep(i,n) b[i] %= mod;
	// yがmより大きいなら、m回操作してaをソートした後はa[0],a[1],...,a[n-1],a[0],a[1],...と順番にかけていくことになる
	// aの全要素にX = x^((y-m)/n)をかけて、あとは手前の(y-m)%n個にxを1回ずつかければok
	// 昇順出力だから手前の(y-m)%n個はそのまま後ろに移動
	k[0] = x;
	repst(i,1,30) k[i] = (k[i-1]*k[i-1])%mod;
	Y = (y-m)/n;
	rept(i,30) if (Y>>i&1) X = (X*k[i])%mod;
	rep(i,n) b[i] = (b[i]*X)%mod;
	rep(i,(y-m)%n) b[i] = (b[i]*x)%mod;
	reps(i,(y-m)%n, n) cout << b[i] << ln;
	rep(i,(y-m)%n) cout << b[i] << ln;
}