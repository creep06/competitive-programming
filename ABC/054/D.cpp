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

// dp[i][j][k]: i番目までの薬でタイプAがjグラム、タイプBがkグラムになるような組み合わせの買い方の最小コスト 存在しなければinf
int n, ma, mb, a[44], b[44], c[44], dp[44][444][444];

int main() {
	cin >> n >> ma >> mb;
	repst(i,1,n) cin >> a[i] >> b[i] >> c[i];
	
	rept(i,10*n) rept(j,10*n) dp[0][i][j] = inf;
	dp[0][0][0] = 0;
	repst(i,1,n) {
		rept(j,10*n) {
			rept(k,10*n) {
				dp[i][j][k] = dp[i-1][j][k];
				if (j>=a[i] && k>=b[i]) chmin(dp[i][j][k], dp[i-1][j-a[i]][k-b[i]]+c[i]);
			}
		}
	}
	int ans = inf;
	repst(i,1,10*n) repst(j,1,10*n) if (i*mb==j*ma) chmin(ans, dp[n][i][j]);
	if (ans==inf) ans = -1;
	cout << ans << ln;
}