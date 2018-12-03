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
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<n;++i){cout<<x[i]<<(i==n-1?'\n':' ');}}

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
const ll mod = 998244353ll;
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

// n-|S|というのは "Sの凸包に含まれる点からS自体を除いた集合Ts" の要素数に等しい
// つまり "2^(n-|S|)の総和" は "Tsの部分集合の個数の総和" に等しい
// 凸包の内部(境界を含まない)の点は選んでも選ばなくても凸包の形状は変わらないが、その凸包を生成する選び方の組み合わせを倍にすることができる
// このことから求めるものは "凸包の面積が正の部分集合の個数" と等しい(というかスコアがこれに対応してる)ことがわかる
// 全部分集合2^n個から面積が0の集合の個数を引けばいい

int n, x[200], y[200], f[234], r;
bool us[200][200];

// (3点の面積)*2
int area(int i, int j, int k) {
	return (x[i]-x[k])*(y[j]-y[k]) - (y[i]-y[k])*(x[j]-x[k]);
}

signed main() {
	cin >> n;
	rep(i,n) cin >> x[i] >> y[i];
	
	f[0] = 1;
	repst(i,1,n) f[i] = f[i-1]*2 %mod;
	// 頂点数0or1or2の集合はとりあえず除く
	r = (f[n] + mod - (1 + n + n*(n-1)/2))%mod;
	// 同一直線状の点を3個以上選んでできる部分集合も除く必要がある
	rep(i,n) reps(j,i+1,n) if (!us[i][j]) {
		vi v;
		v.pb(i), v.pb(j);
		rep(k,n) if (i!=k && j!=k && area(i,j,k)==0) v.pb(k);
		each(k,v) each(l,v) us[k][l] = true;
		int t = v.size();
		if (t>=3) r = (r + mod - f[t] + 1 + t + t*(t-1)/2) %mod;
	}
	cout << r << ln;
}