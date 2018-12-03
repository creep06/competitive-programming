#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rept(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
#define repst(i,s,n) for(int (i)=(s);(i)<=(int)(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln "\n"
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

ll N, W, v[44], w[44], r;
pll ps[1<<20];

int main() {
	cin >> N >> W;
	rep(i,N) cin >> v[i] >> w[i];
	ll n1 = N/2;
	ll n2 = N - n1;
	rep(i,1<<n1) {
		ll sw = 0, sv = 0;
		rep(j,n1) if (i>>j & 1) sw += w[j], sv += v[j];
		ps[i] = mp(sw, sv);
	}
	
	// 考慮する必要のない要素を除外
	sort(ps, ps+(1<<n1));
	int m = 1;
	reps(i,1,1<<n1) if (ps[m-1].se < ps[i].se) ps[m++] = ps[i];
	
	rep(i,1<<n2) {
		ll sw = 0, sv = 0;
		rep(j,n2) if (i>>j & 1) sw += w[n1+j], sv += v[n1+j];
		if (sw<=W) {
			ll tv = (lower_bound(ps, ps+m, mp(W-sw, linf))-1)->se;
			chmax(r, tv+sv);
		}
	}
	cout << r << ln;
}