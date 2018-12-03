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

ll n, W, v[200], w[200], dp[202][200200];;

ll a() {
	int n1 = n/2, n2 = n - n1;
	pll ps[1<<n1];
	rep(i,1<<n1) {
		ll sw = 0, sv = 0;
		rep(j,n1) if (i>>j & 1) sw += w[j], sv += v[j];
		ps[i] = mp(sw, sv);
	}
	sort(ps, ps+(1<<n1));
	int m = 1;
	reps(i,1,1<<n1) if (ps[m-1].se < ps[i].se) ps[m++] = ps[i];
	ll res = 0;
	rep(i,1<<n2) {
		ll sw = 0, sv = 0;
		rep(j,n2) if (i>>j & 1) sw += w[n1+j], sv += v[n1+j];
		if (sw<=W) {
			ll tv = (lower_bound(ps, ps+m, mp(W-sw, linf))-1)->se;
			chmax(res, tv+sv);
		}
	}
	return res;
}

ll b() {
	rep(i,n) rept(j,W) {
		if (j<w[i]) dp[i+1][j] = dp[i][j];
		else dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
	}
	return dp[n][W];
}

ll c() {
	rep(i,n+1) fill(dp[i], dp[i]+200200, linf);
	dp[0][0] = 0;
	rep(i,n) rep(j,200200) {
			if (j<v[i]) dp[i+1][j] = dp[i][j];
			else dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i]);
	}
	ll res = 0;
	rep(i,200200) if (dp[n][i]<=W) res = i;
	return res;
}

signed main() {
	cin >> n >> W;
	rep(i,n) cin >> v[i] >> w[i];
	if (n<=30) cout << a() << ln;
	else if (*max_element(w,w+n)<=1000) cout << b() << ln;
	else cout << c() << ln;
}