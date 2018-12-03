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

ll r, c, x, y, d, l, nck[1000][1000], ans;

int main() {
	cin >> r >> c >> x >> y >> d >> l;
	
	// パスカルの三角形
	nck[0][0] = 1;
	repst(i,1,r*c) {
		nck[i][0] = 1;
		repst(j,1,r*c) {
			nck[i][j] = (nck[i][j] + nck[i-1][j-1] + nck[i-1][j])%mod;
		}
	}
	
	// https://drive.google.com/open?id=1kY6ZMNoh3JIs_BH575ygL6Q7iK0k6Vhw
	// 包除原理で答えを求める 求めたいのは"上下左右全ての列を使う"っていう部分
	// つまり⇡の図の円と1つも重なっていない部分全て
	// これを求めるには偶数個の円が重なっている部分を足して、奇数個の円と重なっている部分を引けばいい
	// 具体的なiの値で言うと
	// 0000 - (0001+0010+0100+1000) + (0011+0110+1100+1010+0101+1001) - (1110+0111+1011+1101) + 1111
	// iのそれぞれのビットは上/下/左/右の列が空であることに対応
	rep(i,1<<4) {
		ll xx = x, yy = y, cnt = 0;
		if (i>>0 & 1) xx--, cnt++;	// 上の列を使わない
		if (i>>1 & 1) xx--, cnt++;	// 下の列を使わない
		if (i>>2 & 1) yy--, cnt++;	// 左の列を使わない
		if (i>>3 & 1) yy--, cnt++;	// 右の列を使わない
		if (xx<0 || yy<0) continue;
		
		ll comb = nck[xx*yy][d+l] * nck[d+l][d] % mod;
		if (cnt%2==0) ans = (ans + comb)%mod;
		else ans = (ans - comb + (comb/mod+1)*mod)%mod;
	}
	
	ans = (ans * (r-x+1)*(c-y+1))%mod;
	cout << ans << ln;
}