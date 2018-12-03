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

ll v1, v2, v3, vm, a = -1;

int main() {
	cin >> v1 >> v2 >> v3 >> vm;
	v1 *= 2, v2 *= 2;
	ll mx = min(v2-1, v3*2);	// smallのサイズはv3以上mx以下じゃないといけない
	repst(i,v3,mx) {
		if (vm<=i && i<=vm*2 && 2*vm<v2) {
			cout << v1 << ln << v2 << ln << i << ln;
			return 0;
		}
	}
	cout << -1 << ln;
}