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
#define show(x) cout << #x << " = " << x ln
#define dbg(x) cout<<#x"="<<x ln

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

// a:鋭角 b:直角 c:鈍角の数
ll n, x[2000], y[2000], a, b, c;

int main() {
	cin >> n;
	rep(i,n) cin >> x[i] >> y[i];
	
	// 直角、鈍角となる角ABCの組の個数を求めれば直角三角形・鈍角三角形の個数がわかり、
	// それらを全体の三角形の個数n(n-1)(n-2)/6から引くと鋭角三角形の個数がわかる
	double eps = 1e-10;	// 相対打ち切り誤差
	rep(i,n) {
		vector<double> an;
		rep(j,n) if (i!=j) an.pb(atan2(y[j]-y[i], x[j]-x[i]));
		sort(all(an));
		rep(j,n-1) an.pb(an[j] + 2*M_PI);
		rep(j,n-1) {
			// 90度未満の角の中で最も大きいもの
			int x = lower_bound(all(an), an[j] + M_PI/2 - eps) - an.begin();
			// 90度以上の角の中で最も小さいもの
			int y = upper_bound(all(an), an[j] + M_PI/2 + eps) - an.begin();
			// 180度以上の角の中で最も小さいもの
			int z = lower_bound(all(an), an[j] + M_PI) - an.begin();
			b += y - x;
			c += z - y;
		}
	}
	a = n*(n-1)*(n-2)/6 - (b + c);
	cout << a << " " << b << " " << c << ln;
}