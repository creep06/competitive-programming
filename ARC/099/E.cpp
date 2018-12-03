#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define each(itr,v) for(auto &(itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define dbg(x) cout<<#x" = "<<(x)<<ln<<flush
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ')<<flush;}}

typedef complex<double> P;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
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

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m;for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}
bool ool(int x,int y,int h,int w) {return((x<0)||(h<=x)||(y<0)||(w<=y));}
bool deq(double a,double b) {return abs(a-b)<eps;}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// 高州・橋州に属する街の数がx,y個のとき、題意の道の本数はx(x-1)/2 + y(y-1)/2
// これを最小化するにはなるべく均等に分けた方が良い
// 問題文を言い換えると、補グラフになるべく多くの辺を足して完全二部グラフが作れればいい
// まず初期状態の補グラフが二部グラフじゃなかったら無理
// 二部グラフだったら各連結成分がSとTに分けられ、どっちをどっちの州にするか自由に決められる
// これをなるべく均等に分ければいいから答えを部分和dp?で探す

int n, m, a, b, d[777][777], c[777], s[777], t[777], k, res = inf;
bool u[777], dp[777][777];

bool col(int v, int x) {
	c[v] = x;
	rep(i,n) {
		if (i==v || d[v][i]) continue;
		if (c[i]==x) return 0;
		if (!c[i] && !col(i,-x)) return 0;
	}
	return 1;
}

void rec(int v) {
	u[v] = 1;
	(c[v]==1 ? s : t)[k]++;
	rep(i,n) if (!d[v][i] && !u[i]) rec(i);
}

int main() {
	cin >> n >> m;
	rep(i,m) {
		cin >> a >> b;
		a--, b--;
		d[a][b] = d[b][a] = 1;
	}
	rep(i,n) if (!c[i] && !col(i,1)) return cout << -1, 0;
	rep(i,n) if (!u[i]) rec(i), k++;
	dp[0][0] = 1;
	rep(i,k) rep(j,n) if (dp[i][j]) dp[i+1][j+s[i]] = dp[i+1][j+t[i]] = 1;
	rep(i,n) if (dp[k][i]) chmin(res, i*(i-1)/2 + (n-i)*(n-i-1)/2);
	cout << res;
}