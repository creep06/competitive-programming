#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
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
#define log2(x) log(x)/log(2)
#define ln '\n'
#define bln(i,n) (i==n-1?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
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

// a[i,j] = y(i-1) + j
// a->bと移動するとき a<bならbは右か下、a>bならbは左か上のマスになる
// a<bでb==a+1のときは　横幅が1で下移動、または横幅が2以上で右移動しかあり得ない
// b>a+1のときは下移動しかありえないから横幅がb-aで確定する

int n, h = -1, w = -1;
ll a[200200];

signed main() {
	cin >> n;
	rep(i,n) cin >> a[i];
	if (n==1) return cout << "YES" << ln << a[0] << ' ' << 1 << ln, 0;
	reps(i,1,n) {
		int d = abs(a[i]-a[i-1]);
		if (d==1) continue;
		if (w!=-1) {
			if (d==w) continue;
			else return cout << "NO" << ln, 0;
		} else w = d;
	}
	// 幅1のやつが矛盾しないかチェック
	if (w==-1) return cout << "YES" << ln << *max_element(a,a+n) << ' ' << 1 << ln, 0;
	
	if (w==0) return cout << "NO" << ln, 0;
	
	reps(i,1,n) if (abs(a[i]-a[i-1])==1) {
		if ((a[i]-1)/w != (a[i-1]-1)/w) return cout << "NO" << ln, 0;
	}
	cout << "YES" << ln << 1000000000 << ' ' << w << ln;
}