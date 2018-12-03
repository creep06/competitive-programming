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
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<n;++i){cout<<x[i]<<(i==n-1?'\n':' ');}}

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
 * 完全2分木の頂点を交互に塗っていくゲームと言い換えられる
 * ある点が塗られている場合その先祖と子孫は全て塗れない 自分のターンが回ってきたときに塗れる点がなければ負け
 * 初期状態で塗れる点の部分木がいくつかあるとき、それらのgrundy数のxor和を求めればいける
 * 解説放送いわくgrundy数の法則は理論で見つけて証明するのは超大変だから実験して法則を見つけるべきらしい
 * 実際に考えてみると部分木の深さをd、そのときのgrundy数をg[d]とおくと、
 * g = {1, 2, 1, 4, 1, 2, 1, 8, ...} (d>=1) となる
 * このことから g[d] = (dを割り切れる最大の2の冪) = d&-d と予想できる
 */

int n, g[200200][2], cnt = 1;
string s;
ll l, x;

int rec(int v, int d) {
	if (g[v][0]==-1 && g[v][1]==-1) return 0;
	else if (g[v][0]==-1) x ^= (l-d)&-(l-d), rec(g[v][1], d+1);
	else if (g[v][1]==-1) x ^= (l-d)&-(l-d), rec(g[v][0], d+1);
	else rec(g[v][0], d+1), rec(g[v][1], d+1);
}

signed main() {
	cin >> n >> l;
	memset(g,-1,sizeof(g));
	rep(i,n) {
		cin >> s;
		int v = 0;
		each(j,s) {
			int c = j-'0';
			if (g[v][c]==-1) g[v][c] = cnt++;
			v = g[v][c];
		}
	}
	rec(0,0);
	cout << (x ? "Alice" : "Bob") << ln;
}