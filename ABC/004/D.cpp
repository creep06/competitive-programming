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

// dp[i][j]: 座標i-1000にいて残りマーブルが計j個のときの最小操作回数
int n, r, g, b, dp[2222][1111];

int main() {
	cin >> r >> g >> b;
	n = r + g + b;
	
	// dp[i][j] = min(dp[i-1][j], dp[i-1][j+1] + cost(i,j))
	// コストはj個残っているときにi-1000に入れるための移動回数
	// マーブルを並べ終わったときは間違いなく左からr,g,bって順番に並んでるはずだから、
	// if j>=g+b : 赤を移動させる必要がある x=-100から赤をx=i-1000に運ぶ ∴ abs(i-900)だけコストがかかる
	// else j>=b : 赤を全部移動させ終わってるから次はx=0から緑をx=i-1000に運ぶ ∴ abs(i-1000)
	// else : 赤も緑も運び終わってるから青をx=100からx=i-1000に運ぶ ∴ abs(i-1100)
	// 残り個数でどの色を運ぶかが一意に決まるってのがポイント
	rept(i,2000) fill(dp[i], dp[i]+n, inf);
	repst(i,1,2000) {
		rep(j,n) {
			int c;
			if (j>=g+b) c = abs(i-900);
			else if (j>=b) c = abs(i-1000);
			else c = abs(i-1100);
			dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]+c);
		}
	}
	int ans = inf;
	rept(i,2000) chmin(ans, dp[i][0]);
	cout << ans << ln;
}