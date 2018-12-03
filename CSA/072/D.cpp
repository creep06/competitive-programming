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

int h, w, s, t;

signed main() {
	cin >> h >> w;
	int a[h][w];
	rep(i,h) rep(j,w) cin >> a[i][j];
	// デフォのsum
	rep(i,h-1) rep(j,w-1) s += a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1];
	// デカイのを内側に持ってくるのが最善
	// 4炭は1回、辺上は2回、内側は4回足される
	// 外側の4辺を内側のどれかと交換することになる （するとしたら)
	
	// まずタテを見る 1行目を交換して増える値
	int ta[h];
	int tmp = 0;
	rep(i,w) tmp += (i==0||i==w-1 ? a[0][i] : a[0][i]*2);
	reps(i,1,h-1) {
		int sum = 0;
		rep(j,w) sum += (j==0||j==w-1 ? a[i][j] : a[i][j]*2);
		ta[i] = tmp - sum;
		chmax(t,ta[i]);
	}
	// h-1行目
	tmp = 0;
	rep(i,w) tmp += (i==0||i==w-1 ? a[h-1][i] : a[h-1][i]*2);
	int tah[h];
	reps(i,1,h-1) {
		int sum = 0;
		rep(j,w) sum += (j==0||j==w-1 ? a[i][j] : a[i][j]*2);
		tah[i] = tmp - sum;
		chmax(t,tah[i]);
	}
	// 0列目
	tmp = 0;
	rep(i,h) tmp += (i==0||i==h-1 ? a[i][0] : a[i][0]*2);
	int yo[w];
	reps(i,1,w-1) {
		int sum = 0;
		rep(j,h) sum += (j==0||j==h-1 ? a[j][i] : a[j][i]*2);
		yo[i] = tmp - sum;
		chmax(t,yo[i]);
	}
	// w-1列目
	tmp = 0;
	rep(i,h) tmp += (i==0||i==h-1 ? a[i][w-1] : a[i][w-1]*2);
	int yoh[w];
	reps(i,1,w-1) {
		int sum = 0;
		rep(j,h) sum += (j==0||j==h-1 ? a[j][i] : a[j][i]*2);
		yoh[i] = tmp - sum;
		chmax(t,yoh[i]);
	}
	cout << s+t << ln;
}