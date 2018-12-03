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

ll n, n1, n2, W, v[40], w[40], m = 1, r;
vector<pll> ps;

int main() {
	cin >> n >> W;
	rep(i,n) cin >> v[i] >> w[i];
	n1 = n/2, n2 = n-n1;
	rep(i,1<<n1) {
		ll tw = 0, tv = 0;
		rep(j,n1) if (i>>j & 1) tw += w[j], tv += v[j];
		if (tw<=W) ps.pb(mp(tw, tv));
	}
	sort(all(ps));
	reps(i,1,ps.size()) if (ps[m-1].se<ps[i].se) ps[m++] = ps[i];
	rep(i,1<<n2) {
		ll tw = 0, tv = 0;
		rep(j,n2) if (i>>j & 1) tw += w[n1+j], tv += v[n1+j];
		if (tw<=W) {
			ll p = ((lower_bound(ps.begin(), ps.begin()+m, mp(W-tw, linf)))-1)->se;
			chmax(r, tv+p);
		}
	}
	cout << r << ln;
}