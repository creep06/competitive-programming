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

// dp[i][j][k]: i番目までで積んであるブロックの種類の集合がjで最後にk色のブロックを積んだ場合のスコアの最大値
int n, m, com, zen, p[10], dp[2][1<<10][11], r = -inf;
char cs;
map<char, int> c;
string s;

signed main() {
	cin >> n >> m >> com >> zen;
	rep(i,m) {
		cin >> cs >> p[i];
		c[cs] = i;
	}
	cin >> s;
	
	rep(i,2) rep(j,1<<m) rept(k,m) dp[i][j][k] = -inf;
	dp[0][0][m] = 0;
	rep(i,n) {
		int no = i%2, ne = (i+1)%2, col = c[s[i]];
		rep(j,1<<m) rep(k,m) dp[ne][j][k] = -inf;
		rep(j,1<<m) {
			rept(k,m) {
				// 存在しない状態
				if (dp[no][j][k]==-inf) continue;
				chmax(dp[ne][j][k], dp[no][j][k]);
				// 色ボーナスとコンボボーナス(あれば)
				int bon = p[col] + (col==k ? com : 0);
				chmax(dp[ne][j|(1<<col)][col], dp[no][j][k] + bon);
			}
		}
	}
	rep(j,1<<m) {
		rept(k,m){
			if (j==(1<<m)-1) dp[n%2][j][k] += zen;
			chmax(r, dp[n%2][j][k]);
		}
	}
	cout << r << ln;
}