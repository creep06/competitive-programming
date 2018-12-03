#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto &(itr):(v))
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
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

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

// 長さxの区間について
// 1) x<cのとき 長さ1の区間をx個作っても変わらない
// 2) x==cのとき その区間の最小値ぶん得
// 3) c<x<2cのとき 長さcの区間1個と長さ1の区間x-c個でも変わらない
// 4) x==2cのとき 長さcの区間を2個取った方が明らかに得
// (例えば1,2 / 1,2だと変わらない、1,2 / 3,4だとそっちのほうが得 全区間の最小値2個より各区間の最小値1個ずつの方が大きい)
// こんな感じで考えると結局区域は長さ1かcだけ考えればいいことがわかる
// dp[i]: [0,i)の範囲をいい感じに分割したときのコストの最小値
// これを累積和とRMQを使ってi->i+1とi->i+cの遷移で更新すればO(n)

// RMQ<int> rmq(114514);
template<typename V> struct RMQ {
	private:
	int n;
	vector<V> node;
	public:
	RMQ(int sz) {
		n=1;while(n<sz)n*=2;
		node.resize(2*n-1,inf);
	}
	void update(int x, V val) {
		x+=n-1,node[x]=val;
		while(x>0) x=(x-1)/2,node[x]=min(node[2*x+1],node[2*x+2]);
	}
	V q(int a, int b, int k=0, int l=0, int r=-1) {
		if(r<0) r=n;
		if(r<=a||b<=l) return inf;
		if(a<=l&&r<=b) return node[k];
		return min(q(a,b,2*k+1,l,(l+r)/2),q(a,b,2*k+2,(l+r)/2,r));
	}
};

ll n, c, a[114514], s[114514], dp[114514];
RMQ<ll> rmq(114514);

signed main() {
	cin >> n >> c;
	rep(i,n) {
		cin >> a[i];
		rmq.update(i,a[i]);
		s[i] = (i>0 ? s[i-1] : 0) + a[i];
	}
	fill(dp, dp+n+1, linf);
	dp[0] = 0;
	rep(i,n) {
		chmin(dp[i+1], dp[i] + a[i]);
		if (i+c<=n) chmin(dp[i+c], dp[i] + s[i+c-1] - (i>0 ? s[i-1] : 0) - rmq.q(i,i+c));
	}
	cout << dp[n] << ln;
}