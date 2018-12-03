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

int n, x[100100], mn = inf, mx = -inf;

signed main() {
	cin >> n;
	rep(i,n) {
		cin >> x[i];
		chmin(mn,x[i]), chmax(mx,x[i]);
	}
	if (mx-mn<=1) {
		cout << n << ln;
		rep(i,n) cout << x[i] << bln(i,n);
		return 0;
	}
	// 真ん中を分配するか両端を真ん中に寄せるかの二択
	int l = 0, m = 0, r = 0;
	rep(i,n) {
		if (x[i]==mn) l++;
		else if (x[i]==mx) r++;
		else m++;
	}
	if (m/2*2 < min(l,r)*2) {
		int tmp = min(l,r);
		l = r = tmp;
		cout << n - (min(l,r)*2) << ln;
		rep(i,n) {
			if (x[i]==mn && l) x[i] = mn+1, l--;
			else if (x[i]==mx && r) x[i] = mx-1, r--;
			cout << x[i] << bln(i,n);
		}
	} else {
		int tmp = m/2*2;
		l = r = tmp/2;
		cout << n - tmp << ln;
		rep(i,n) {
			if (x[i]==mn+1) {
				if (l) x[i] = mn, l--;
				else if (r) x[i] = mx, r--;
			}
			cout << x[i] << bln(i,n);
		}
	}
}