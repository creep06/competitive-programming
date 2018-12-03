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

const int inf = 100100100;
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

// dp[n][k]: 最後にゲームを起動したのがn番目の時刻で、それまでにk回ゲームを起動しているときの知力の最大値
int n, x, t[5000];
ll dp[5010][5010];

int main() {
	cin >> n >> x;
	rep(i,n) cin >> t[i];
	
	// dpは"スタミナが満タンにならないギリギリ"か"スタミナが満タンになった直後"の2通りの遷移だけ考えればいい
	dp[0][1] = x;
	rep(i,n-1) {
		// l:満タンのギリギリ手前 r:満タンギリギリ直後
		ll l = i+1, r = i+1;
		reps(j,i+1,n) {
			if (t[j]-t[i]<=x) l = j;
			else {
				r = j;
				break;
			}
		}
		repst(j,1,n) {
			chmax(dp[l][j], dp[i][j-1] + min(x, t[l]-t[i]));
			chmax(dp[r][j], dp[i][j-1] + min(x, t[r]-t[i]));
		}
	}
	ll ans = 0;
	repst(i,1,n) {
		rept(j,n) chmax(ans, dp[j][i]);
		cout << ans << ln;
	}
}