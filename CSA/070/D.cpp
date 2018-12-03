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

// 1,2,1,2,...として、その合計をsとし、(n-s)/kを全体に足し、x,x+1,x,x+1,....になったとする
// この合計をtとするとn-t回 x+1の項を++ -> xの項を++
// x+1,x,x+1,x,...バージョンも同じように作って最大値と最小値の差が小さい方を出力
// 実装もうちょっとスマートにできると思う

ll n, k, e[100000], o[100000], es, os, ne, no;

signed main() {
	cin >> n >> k;
	rep(i,k) es += e[i] = 1+i%2, os += o[i] = 2-i%2;
	if (n<es) return cout << -1 << ln, 0;
	rep(i,k) e[i] += (n-es)/k, o[i] += (n-os)/k;
	ne = n - accumulate(e, e+k, 0ll), no = n - accumulate(o, o+k, 0ll);
	rep(i,min(ne,k/2)) e[i*2+1]++;
	rep(i,max(0ll,ne-k/2)) e[i*2]++;
	rep(i,min(no,(k+1)/2)) o[i*2]++;
	rep(i,max(0ll,no-(k+1)/2)) o[i*2+1]++;
	ll de = *max_element(e,e+k) - *min_element(e,e+k), dio = *max_element(o,o+k) - *min_element(o,o+k);
	if (de<=dio) rep(i,k) cout << e[i] << (i==k-1 ? '\n' : ' ');
	else rep(i,k) cout << o[i] << (i==k-1 ? '\n' : ' ');
}