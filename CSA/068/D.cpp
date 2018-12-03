#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(ll (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,n+1)
#define repst(i,s,n) reps(i,s,n+1)
#define reprt(i,n,t) for(ll (i)=(n);(i)>=t;--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb emplace_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) for(int (i)=0;i<n;++i){cout<<x[i]<<(i==n-1?'\n':' ');}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
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

/*
 * まず各クエリはO(1)で処理する必要がある 累積和使いそうなこともわかる
 * ex1のq[0]みたいに三角形が行列をはみ出す場合があるから気をつけないといけない
 * 普通の二次元imosみたいに4点に++/--すると四角形になる
 * 題意の三角形を作るには？
 * 6点に++/--して斜め・たて・ヨコの順に累積和をとればいいっぽい
 */

// 行列は1-basedにしとく
ll n, q, r, c, l, s, m[2525][2525];

signed main() {
	cin >> n >> q;
	rep(i,q) {
		cin >> c >> r >> l >> s;
		m[r-1][c-1]-=s, m[r][c-1]+=s, m[r][c+l]-=s, m[r-1][c+l-1]+=s, m[r+l][c+l]+=s, m[r+l][c+l-1]-=s;
	}
	// 右下から順に左上へ、　左上から順に下へ、　左上から順に右へ
	reprt(j,2020,1) reprt(i,2020,1) m[i-1][j-1] += m[i][j];
	rep(j,2020) rep(i,2020) m[i][j+1] += m[i][j];
	rep(j,2020) rep(i,2020) m[i+1][j] += m[i][j];
	repst(y,1,n) {
		repst(x,1,n) cout << m[x][y] << (x==n ? '\n' : ' ');
	}
}