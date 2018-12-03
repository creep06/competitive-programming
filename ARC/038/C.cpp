#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(ll (i)=(n);(i)>=(t);--(i))
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

// 各豆のgrundy数のxor和が知りたい
// 同じ値のxorは0だからi番目の更に豆が偶数個あるときはxor和は打ち消し合って0になり、奇数個あるときは1個分だけ残る
// i番目の皿のgrundy数をg[i]とすると、g[i]はg[i-c[i]]からg[i-1]に含まれない最小の非負整数 そのままやるとO(n^2)
// grundy数がxになるような最大のj(<i)をセグ木に追加していって二分探索すればちょっと重いO(nlogn)

struct RMQ {
	private:
	int n;
	vector<int> node;
	public:
	RMQ(int sz) {
		n=1;while(n<sz)n*=2;
		node.resize(2*n-1,-1);
	}
	void update(int x, int val) {
		x+=n-1,node[x]=val;
		while(x>0) x=(x-1)/2,node[x]=min(node[2*x+1],node[2*x+2]);
	}
	int q(int a, int b, int k=0, int l=0, int r=-1) {
		if(r<0) r=n;
		if(r<=a||b<=l) return inf;
		if(a<=l&&r<=b) return node[k];
		return min(q(a,b,2*k+1,l,(l+r)/2),q(a,b,2*k+2,(l+r)/2,r));
	}
};

int n, c[100100], a[100100], g[100100];
ll xs;
RMQ rmq(114514);

signed main() {
	cin >> n;
	reps(i,1,n) cin >> c[i] >> a[i];
	rmq.update(0,0);
	reps(i,1,n) {
		int x = i-c[i], y = 0;
		repr(j,19) if (rmq.q(0,y+(1<<j)) >= x) y += 1<<j;
		g[i] = y;
		rmq.update(y,i);
		if (a[i]%2) xs ^= g[i];
	}
	cout << (xs ? "First" : "Second") << ln;
}