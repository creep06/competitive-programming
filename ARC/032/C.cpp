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
typedef tuple<int,int,int> tp;

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

int n, a[100100], b[100100], c, ne;
pii dp[1001001];
vi m[1001001];

signed main() {
	cin >> n;
	rep(i,n) {
		cin >> a[i] >> b[i];
		m[a[i]].pb(i);
	}
	// 時刻i以降で同時にできる仕事の最大値、インデックスの最小値
	dp[1000000] = {0,inf};
	repr(i,999999) {
		pii p = dp[i+1];
		// 開始時刻がiの仕事それぞれのインデックス
		each(j,m[i]) {
			if (dp[b[j]].fi+1 > p.fi) {
				p.fi = dp[b[j]].fi+1;
				p.se = j+1;
			} else if (dp[b[j]].fi+1 == p.fi) {
				chmin(p.se, j+1);
			}
		}
		dp[i] = p;
	}
	c = dp[0].fi;
	cout << c << ln;
	rep(i,c) {
		pii p = dp[ne];
		cout << p.se;
		if (i==c-1) cout << ln;
		else {
			cout << ' ';
			ne = b[p.se-1];
		}
	}
}