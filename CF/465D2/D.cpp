#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(ll (i)=(n);(i)>=(t);--(i))
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

// m種類の文字からなるサイズnの文字列S1,S2がある
// 何文字か消えていて、消えている文字は等確率でm種類のうちどれか つまりそれぞれ1/mの確率でi[1,m]
// S1がS2より辞書順で大きい確率を求めよ(全く同じじゃダメ)
// 消えている文字は0で表される

ll n, m, a[114514], b[114514], ans;

ll mpow(ll x, ll n=mod-2, ll m=mod) {
	ll res = 1;
	while (n>0) {
		if (n&1) res = res * x %m;
		x = x * x %m;
		n >>= 1;
	}
	return res;
}

signed main() {
	cin >> n >> m;
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];
	ll p = 1;
	rep(i,n) {
		if (a[i]==0 && b[i]==0) {
			p = p * mpow(m) %mod * mpow(m) %mod;
			ans = (ans + p*(m*(m-1)/2 %mod) %mod) %mod;
			p = p*m %mod;
		} else if (a[i]==0) {
			(p *= mpow(m)) %= mod;
			(ans += p*(m-b[i])) %= mod;
		} else if (b[i]==0) {
			(p *= mpow(m)) %= mod;
			(ans += p*(a[i]-1)) %= mod;
		} else {
			if (a[i]>b[i]) {
				(ans += p) %= mod;
				break;
			}
			if (a[i]<b[i]) break;
		}
	}
	cout << ans << ln;
}