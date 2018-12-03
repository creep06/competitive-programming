#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(ll (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto &(itr):(v))
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
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

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

// dp[i][j]: i項目を見ている時点でj個括弧が開いているときのそこまでの式の値の最大値
// +の直後に括弧を開いても意味はない また-の直後には必ず括弧を開いても問題ない(すぐ閉じればなかったことにできるため)
// こうすると括弧が偶数個開いているときは項の正負はそのまま、奇数個開いているときは逆転するので括弧を開いている場所を保持しなくて済む
// 括弧は0,1,2個の3通りだけ考えればいい 3つ目の括弧を開くのは今開いている2つの括弧を閉じて新しい括弧を1つ開くのと同じなため
// 例えば -(1-(3-(4.. は -(1-(3))-(4.. と同じ

ll n, f, a[114514], p[114514], dp[114514][3];
char c;

signed main() {
	cin >> n >> f;
	rep(i,n-1) {
		cin >> c >> a[i];
		p[i] = (c=='+');
	}
	rep(i,n) rep(j,3) dp[i][j] = -linf;
	dp[0][0] = f;
	rep(i,n-1) {
		if (p[i]) {
			dp[i+1][2] = dp[i][2] + a[i];
			dp[i+1][1] = max(dp[i+1][2], dp[i][1] - a[i]);
			dp[i+1][0] = max(dp[i+1][1], dp[i][0] + a[i]);
		} else {
			dp[i+1][2] = dp[i][1] + a[i];
			dp[i+1][1] = tmax(dp[i+1][2], dp[i][0] - a[i], dp[i][2] - a[i]);
			dp[i+1][0] = max(dp[i+1][1], dp[i][1] + a[i]);
		}
	}
	cout << *max_element(dp[n-1], dp[n-1]+3) << ln;
}