#include <bits/stdc++.h>
using namespace std;

//#define int long long
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

// それぞれの直方体(nimの山にあたる)で、まず全てのハバネロを含む最小の直方体を切り出す(↓のmnとmxで囲まれた部分)
// その直方体の6面の外側ならどこでも切って食える つまりこれらの切れる部分の長さの和がnimの石の個数にあたる
// だからこれを列挙してxorをとってgrundy数を求めれば勝敗がわかる

int n, a[3], m, h[3], mn[3], mx[3], grundy;

signed main() {
	cin >> n;
	rep(i,n) {
		rep(j,3) cin >> a[j];
		cin >> m;
		fill(mn, mn+3, inf);
		fill(mx, mx+3, 0);
		rep(j,m) {
			rep(k,3) {
				cin >> h[k];
				chmin(mn[k], h[k]);
				chmax(mx[k], h[k]);
			}
		}
		rep(j,3) {
			grundy ^= mn[j];
			grundy ^= a[j] - mx[j] - 1;
		}
	}
	if (grundy) cout << "WIN" << ln;
	else cout << "LOSE" << ln;
}