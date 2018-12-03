#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(ll (i)=(n);(i)>=(t);--(i))
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

// dp[i][x]: 上からi個までの長方形を動かしていてi個目の長方形の横座標をxに動かした時点でのそこまでのコストの最小値
// dp[i][x] = |x-l[i]| + min dp[i-1][x'] (x-(r[i-1]-l[i-1]) <= x' <= x+(r[i]-l[i]))
// これでO(nx^2) 部分点
//
// dp[i-1]からdp[i]を求めるには以下の操作ができればいい
// 1) x軸方向に平行移動
// 2) ある一定長さの区間のminを取る
// 3) |x-l[i]|を足す
// dpの式に着目する dp[i]の式は|x-l|という形の式をi個足し合わせたものなので、下に凸で、
// 傾きはxが-∞のとき-i、そこから徐々に傾きが大きくなっていき、0になる範囲を経由し、xが∞のときiになる
// iが増える(|x-l|という形の式が増える)に連れて傾き0の部分が広がり、そのぶんだけ傾き負の部分は左にスライドし、正の部分は右にスライドする
// 移動量の総和を最小化するには各矩形は傾きが0の範囲のxのうち一番近い場所に移動すればいい
// 傾きが変わる点をset(正負で分ける)に入れといて、0の範囲が増える度に更新する

ll n, l[114514], r[114514];
multiset<ll> le, ri;
ll ls, rs, ans;

signed main() {
	cin >> n;
	rep(i,n) cin >> l[i] >> r[i];
	ls = rs = l[0];
	le.insert(l[0]), ri.insert(l[0]);
	reps(i,1,n) {
		ls -= r[i]-l[i], rs += r[i-1]-l[i-1];
		ll a = *le.rbegin(), b = *ri.begin();
		if (ls<=l[i] && l[i]<=rs) {
			le.insert(l[i]-(ls-a));
			ri.insert(l[i]-(rs-b));
			ls = rs = l[i];
		} else if (l[i]<ls) {
			ans += abs(l[i]-ls);
			le.insert(l[i]-(ls-a));
			le.insert(l[i]-(ls-a));
			ll left = *le.rbegin() + (ls-a);
			le.erase(--le.end());
			ri.insert(left-(rs-b));
			ls = *le.rbegin() + (ls-a);
			rs = left;
		} else {
			ans += abs(l[i]-rs);
			ri.insert(l[i]-(rs-b));
			ri.insert(l[i]-(rs-b));
			ll right = *ri.begin() + (rs-b);
			ri.erase(ri.begin());
			le.insert(right - (ls-a));
			ls = right;
			rs = *ri.begin() + (rs-b);
		}
		//cout << i << ' ' << ans << ln;
	}
	cout << ans << ln;
}