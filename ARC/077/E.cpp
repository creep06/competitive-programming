#include <bits/stdc++.h>
using namespace std;

#define int long long
#define reps(i,s,n) for(ll (i)=(s);(i)<(ll)(n);++(i))
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

// 順送りボタンのみで明るさをaからbにすると、a<=bならb-a回、a>bならm-a+b回ボタンを押す必要がある
// まとめると(m+b-a)%m回と書ける
// またaとbの間(bは含む)にxがあるときのみお気に入りボタンを押した方が得で、そのときはボタンを1+(m+b-x)%m回押すことになる
// お気に入りの明るさをxからx+1にするとどうなるか？
// 1) b==xのとき お気に入りボタンを1回押すだけでよかったのが順送りボタンを(m+x-a)%m回押さないといけなくなる
// 2) aとbの間(両端を含まない)にxがあるとき 順送りボタンを押す回数が1回減る
// 3) その他 変わらない
// まとめると、a[i+1]がxであるi全てについて(m+a[i+1]-a[i])%m-1回増え、a[i]とa[i+1]の間にxがあるようなiの数回減る
// b[i]:前者の和 c[i]:後者の累積和 を事前に求めて、x==1のときだけ素直に計算すれば、あとは⇡のようにx=2,3,...の場合もO(1)で計算できる

int n, m, a[114514], b[114514], c[114514], t, r;

signed main() {
	cin >> n >> m;
	rep(i,n) cin >> a[i];
	rep(i,n-1) {
		b[a[i+1]] += (m+a[i+1]-a[i])%m - 1;
		if (a[i]<a[i+1]) c[a[i]+1]++, c[a[i+1]]--;
		else c[a[i]+1]++, c[0]++, c[a[i+1]]--;
	}
	rep(i,m) c[i+1] += c[i];
	// x==1の場合を求める
	rep(i,n-1) t += min((m+a[i+1]-a[i])%m, 1+(m+a[i+1]-1)%m);
	r = t;
	// xを1増やしつつ答えを更新してく
	repst(x,2,m) {
		t = t + b[x-1] - c[x-1];
		chmin(r, t);
	}
	cout << r << ln;
}