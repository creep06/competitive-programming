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
#define bln(i,n) ((i)==(n-1)?'\n':' ')
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

// q[0]はpの偶数番目の要素のうちの最小値で、q[1]はpの奇数番目かつq[0]として採用したものより右にある要素のうちの最小値
// 前者のpにおける位置をi、後者をjとすると、これらを採用した後pは[0,i), [i+1,j), [j+1,n)の3つの区間に分割される
// q[2]は各区間の偶数番目の要素のうちの最小値で、q[3]は同じ区間の奇数番目かつq[2]より右にある要素のうちの最小値
// でまた区間が分割される これの繰り返し
// 偶数番目と奇数番目で分けてセグ木を作ってからこの操作を繰り返していき、
// 区間を分割する度にpriority_queueに新しくできる区間を"各区間の偶数番目の要素の最小値"をキーにして突っ込んでおく
// これでO(Nlogn)で解ける

struct RMQ {
	private:
	int n;
	vector<int> node;
	public:
	RMQ(int sz) {
		n=1;while(n<sz)n*=2;
		node.resize(2*n-1,inf);
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

// revで1〜nの値がpの何番目にあたるかを取得できる
int n, p[200200], rev[200200];
vi ans;
RMQ ev(200200), od(200200);
priority_queue<pair<int,pii>> q;

// 区間[l,r)からp[xi],p[yi]を採用して区間を最大3つ [l,xi),[xi+1,yi),[yi+1,r) に分割
void query(int l, int r) {
	if (l%2==0) {
		int x = ev.q(l,r), xi = rev[x];
		int y = od.q(xi,r), yi = rev[y];
		ans.pb(x), ans.pb(y);
		ev.update(xi,inf), od.update(yi,inf);
		if (l<xi) q.push({-ev.q(l,xi), {l, xi}});
		if (xi+1<yi) q.push({-od.q(xi+1,yi), {xi+1, yi}});
		if (yi+1<r) q.push({-ev.q(yi+1,r), {yi+1, r}});
	} else {
		int x = od.q(l,r), xi = rev[x];
		int y = ev.q(xi,r), yi = rev[y];
		ans.pb(x), ans.pb(y);
		od.update(xi,inf), ev.update(yi,inf);
		if (l<xi) q.push({-od.q(l,xi), {l, xi}});
		if (xi+1<yi) q.push({-ev.q(xi+1,yi), {xi+1, yi}});
		if (yi+1<r) q.push({-od.q(yi+1,r), {yi+1, r}});
	}
}

signed main() {
	cin >> n;
	rep(i,n) {
		cin >> p[i];
		rev[p[i]] = i;
		if (i%2==0) ev.update(i,p[i]), od.update(i,inf);
		else ev.update(i,inf), od.update(i,p[i]);
	}
	q.push({-ev.q(0,n),{0,n}});
	while (!q.empty()) {
		int l = q.top().se.fi, r = q.top().se.se; q.pop();
		query(l,r);
	}
	rep(i,n) cout << ans[i] << (i==n-1 ? '\n' : ' ');
}