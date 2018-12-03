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

int n, t;
ll os, es, res;
vl a;
vi od, ev, need, ans;

void solve() {
	bool ud = true;
	while (ud) {
		ud = false;
		while (!need[0]) ans.pb(1), need.erase(need.begin()), ud = true;
		while (!need[need.size()-1]) ans.pb(need.size()), need.erase(need.end()-1), ud = true;
		reps(i,1,need.size()-1) {
			if ((need[i-1] && need[i+1]) || (!need[i] && !need[i-1] && !need[i+1])) {
				ud = true;
				if (need[i-1] && need[i+1]) need[i] = 1;
				need.erase(need.begin()+i+1), need.erase(need.begin()+i-1);
				ans.pb(i+1);
				break;
			}
		}
	}
}

signed main() {
	cin >> n;
	a.resize(n), need.resize(n);
	rep(i,n) {
		cin >> a[i];
		if (a[i]<=0) continue;
		if (i%2==0) os += a[i], od.pb(i);
		else es += a[i], ev.pb(i);
	}
	if (od.empty() && ev.empty()) {
		int mx = -inf, mi = 0;
		rep(i,n) if (mx<a[i]) mx = a[i], mi = i;
		need[mi] = 1;
		res = mx;
	} else if (os<es) {
		each(i,ev) need[i] = 1;
		res = es;
	} else {
		each(i,od) need[i] = 1;
		res = os;
	}
	cout << res << ln;
	solve();
	cout << ans.size() << ln;
	each(i,ans) cout << i << ln;
}