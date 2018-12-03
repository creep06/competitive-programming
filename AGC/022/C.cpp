#include <bits/stdc++.h>
using namespace std;

#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto &(itr):(v))
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) if(x>y)x=y
#define chmax(x,y) if(x<y)x=y
#define log2(x) (log(x)/log(2))
#define ln '\n'
#define bln(i,n) ((i==n-1)?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
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

ll mop(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// 同じkで2回操作を行う必要もない
// それぞれ独立に最短経路を出してorすればいい？
// するとex1で19->0のコスト2を余計に加算してしまう
// 実際は10->3と14->4の操作のついでで19は0にできる
// 要はどれをベースにするかで変わってくる
// 10/14をベースに19を考えればコストは0にできる
// 上のビットから1個ずつ決めていく感じの方が良さげ
// kビット目を1にしないと絶対に到達できないa-bのペアがあれば仕方なく1にする
// a->bのルートは全部メモしておく

ll n, A[50], B[50], d[55][55], res;
vpii e[55];
vi r[55];

void rec(int v, int id, int c) {
	if (v==B[id]) {
		r[id].pb(c);
		return;
	}
	each(i,e[v]) {
		int u = i.fi, cost = i.se;
		if (c&cost) continue;
		rec(u,id,c|cost);
	}
}

signed main() {
	cin >> n;
	rep(i,n) cin >> A[i];
	rep(i,n) cin >> B[i];
	
	// exception
	bool sam = true;
	rep(i,n) {
		if (A[i]!=B[i]) sam = false;
		if (A[i]<B[i]) return cout << -1 << ln, 0;
	}
	if (sam) return cout << 0 << ln, 0;
	
	// impossible
	rept(i,50) rept(j,50) if (i!=j) d[i][j] = linf;
	rept(i,50) repst(k,1,50) chmin(d[i][i%k], 1ll<<k);
	rept(k,50) rept(i,50) rept(j,50)
	    chmin(d[i][j], d[i][k]+d[k][j]);
	rep(i,n) if (d[A[i]][B[i]]==linf) return cout << -1 << ln, 0;
	
	// solve
	rept(i,50) repst(k,1,50) if (i!=i%k) e[i].pb({i%k, 1ll<<k});
	rep(i,n) rec(A[i], i, 0);
	repr(k,50) {
		int c = 1ll<<k;
		bool need = true;
		rep(i,n) each(j,r[i]) if (!(j&c) && (((j>>k)<<k)|res)==res) need = false;
		if (need) res |= c;
	}
	cout << res << ln;
}