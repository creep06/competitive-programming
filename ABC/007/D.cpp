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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// dp[i][j][k]
// i) i桁目まで決まってる
// j) A未満であることがもう確定してるなら1
// k) 既に4か9が含まれてるなら1
string a, b;
int n, m, lim;
ll dp[20][2][2], dp2[20][2][2], ans;

int main() {
	cin >> a >> b;
	n = (int)a.length(), m = (int)b.length();
	
	dp[0][0][0] = 1;
	rep(i,n) {
		rep(j,2) {
			rep(k,2) {
				// もうa未満って確定してるならi桁目はどの数字でもいい
				// 確定してないならi桁目の数字までしか選べない
				lim = j ? 9 : a[i]-'0';
				rept(d,lim) {
					// i時点でa未満が確定してる or 今まで確定してなかったけど今lim未満の数字に決めることで確定した場合 はj==1
					// i時点で4か9が含まれてる or 今まで含まれてなかったけど今4か9を選んだ場合 はk==1
					dp[i+1][j|d<lim][k|d==4|d==9] += dp[i][j][k];
				}
			}
		}
	}
	
	dp2[0][0][0] = 1;
	rep(i,m) {
		rep(j,2) {
			rep(k,2) {
				lim = j ? 9 : b[i]-'0';
				rept(d,lim) {
					dp2[i+1][j|d<lim][k|d==4|d==9] += dp2[i][j][k];
				}
			}
		}
	}
	
	// (b以下で題意を満たす数字の数) - (a"未満"で題意を満たす数字の数)
	ans = dp2[m][1][1] + dp2[m][0][1] - dp[n][1][1];
	cout << ans << ln;
}