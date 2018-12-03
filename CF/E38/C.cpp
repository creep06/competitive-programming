#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
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

// 行列がうんぬんの問題の答えはn^2 - [n/m]^2
// 変形すると(n-[n/m])と(n+[n/m])の積
// xの約数dについてdを前者、x/dを後者にあてはめてnとn/mを決め打ちしてn/mがこれを満たすようにmを設定できるか二分探索
// 約数列挙にO(√x)かかり各約数についてO(logd)かかる

ll t, x, n, m;

void solve() {
	for (ll i = 1; i*i <= x; ++i) {
		if (x%i) continue;
		ll a = i, b = x/i;
		if (a%2!=b%2) continue;
		ll tn = (a+b)/2, nm = b - tn;
		if (nm<1 || tn<nm) continue;
		ll l = 1, r = tn+1;
		while (r-l>1) {
			ll md = (r+l)/2;
			if (tn/md<nm) r = md;
			else l = md;
		}
		if (tn/l==nm) {
			n = tn, m = l;
			return;
		}
	}
	n = -1;
}

signed main() {
	
	cin >> t;
	while (t--) {
		cin >> x;
		if (x==0) {
			cout << "1 1" << ln;
			continue;
		}
		solve();
		if (n==-1) cout << -1 << ln;
		else cout << n << ' ' << m << ln;
	}
}