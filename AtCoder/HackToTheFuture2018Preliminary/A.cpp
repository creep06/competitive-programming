#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,n+1)
#define repst(i,s,n) reps(i,s,n+1)
#define reprt(i,n,t) for(ll (i)=(n);(i)>=t;--(i))
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
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<n;++i){cout<<x[i]<<(i==n-1?'\n':' ');}}

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

/*
 * 10^4マスあって最大10^3クエリ 各クエリでそこそこ重い処理しつつ全マス見れる
 */

#define tp tuple<int,int,int>
#define mt(x,y,z) make_tuple(x,y,z)

const int n = 100;
int a[n][n];
vector<tp> res;

void input() {
	rep(i,n) rep(j,n) cin >> a[i][j];
}

void output() {
	int q = res.size();
	cout << q << ln;
	rep(i,q) {
		int A, B, C;
		tie(A,B,C) = res[i];
		cout << A << ' ' << B << ' ' << C << ln;
	}
}

ll score(int x, int y) {
	int b[n][n];
	rep(i,n) rep(j,n) b[i][j] = a[i][j];
	int h = min(100, a[y][x]);
	rep(i,n) rep(j,n) b[i][j] -= max(0, h-abs(x-j)-abs(y-i));
	ll ans = 0;
	rep(i,n) rep(j,n) ans += abs(a[i][j] - b[i][j]);
	return 200000000ll-ans;
}

// 全マス見て最大値が書いてあるマスを中心にH=min(100,最大値)で減らしていく貪欲
// 11msで終わってるから相当余裕がある
void greedy() {
	rep(Q,1000) {
		int mx = 0, x = 0, y = 0;
		// 最大値をサーチ
		rep(i,n) rep(j,n) chmax(mx, a[i][j]);
		if (mx<=0) break;
		// 最大値に近いマスを全てx,yとしてみて試し、スコアが最も高くなるものを採用する
		vi xx, yy;
		rep(i,n) rep(j,n) if (a[i][j]>max(0, mx - mx*3000/(1000*(Q+1)))) xx.pb(j), yy.pb(i);
		ll mxx = -linf;
		rep(i,xx.size()) {
			ll tmp = score(xx[i],yy[i]);
			if (tmp>mxx) {
				mxx = tmp;
				x = xx[i], y = yy[i];
			}
		}
		// 確定させる
		int h = min(100,a[y][x]);
		res.pb(mt(x,y,h));
		rep(i,n) rep(j,n) a[i][j] -= max(0, h-abs(x-j)-abs(y-i));
	}
}



signed main() {
	input();
	greedy();
	output();
}