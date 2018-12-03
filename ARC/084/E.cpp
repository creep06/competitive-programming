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

// 1) kが偶数のとき
// 最初の整数がk/2以下である数列とk/2+1以上である数列の個数は等しいため、
// 求める数列は前者の一番最後 ∴ k/2の後にkがn-1個続く数列
// 2) kが奇数のとき
// 最初の整数が(k+1)/2-1以下の数列と(k+1)/2+1以上の数列の個数は等しいから最初の数は(k+1)/2で確定
// このグループの中で(k+1)/2がn個続く数列bの前後にある数列の個数の差はいくらか？
// bの前にある数列xについて、各要素x[i]をk+1-x[i]に置き換えると、xがbのprefixでない限り常にbの後ろの数列になる
// 逆にbの後ろにある数列yについても同じように置き換えると常にbの前の数列になる
// このことからbの前後にある数列はbのprefixを除いて1:1対応してることがわかる
// つまりbの前にはbのprefixの個数 ∴ n-1個だけ数列が多く存在するので、bを[(n-1)/2]==n/2回戻したものが答え

int k, n, b[300000];

signed main() {
	cin >> k >> n;
	if (k%2==0) {
		cout << k/2 << ' ';
		rep(i,n-1) cout << k << (i==n-2 ? '\n' : ' ');
		return 0;
	}
	fill(b,b+n,(k+1)/2);
	int l = n-1, m = n/2;
	while (m--) {
		if (b[l]==1) l--;
		else {
			b[l]--;
			reps(i,l+1,n) b[i] = k;
			l = n-1;
		}
	}
	rept(i,l) cout << b[i] << (i==l ? '\n' : ' ');
}