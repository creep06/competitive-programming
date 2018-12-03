#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(ll (i)=(n);(i)>=(t);--(i))
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

// x(==n!/k)番目の順列の一番最初の数は？
// 一番最初の数がiである順列は各iについて(n-1)!個あるから x/(n-1)! (0-based)
// これの余りをyとすると2番目の数も同様に考えて y/(n-2)!
// これを繰り返せば部分点は取れる
// xにn!/kを代入すると、一番最初の数は n!/k / (n-1)! = n/k これの余りをyとすると、
// 残りの数は(n-1)!通りの数値のうちy/kに当たるものを選びたい -> (n-1)*y/k
// こうやって筆算ぽく繰り返すと0-basedの配列fが出来上がる
// これは順列ではないから順列に戻す必要がある (例えばfが全て0なら1番目の順列=={1,2,3,...}に対応する)
// これはBITの二分探索を用いて"未使用の数値のうち下からf[i]番目"を求めていけばいい

// BIT<型,k> bt; [1,2^k)
template<class T, int ME> class BIT {
	public:
	T bit[1<<ME],val[1<<ME];
	T total(int e) {T s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	T add(int e,T v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	T set(int e,T v) { add(e,v-val[e]);}
	int lb(T v) {
		T tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<v) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};

ll n, k, f[100100];
BIT<int,20> bt;

signed main() {
	cin >> n >> k;
	repst(i,1,n) bt.add(i,1);
	ll p = 1;
	rep(i,n) {
		ll c = n-i;
		f[i] = c*p/k;
		p = c*p%k;
	}
	// ⇡で求めたものは0-basedのn!/k番目 == 1-basedのn!/k + 1だから1個戻す必要がある
	// prev_permutation使ってもよさげ
	repr(i,n-1) {
		if (f[i]) {
			f[i]--;
			break;
		}
		f[i] = n-i-1;
	}
	rep(i,n) {
		int x = bt.lb(f[i]);
		cout << x+1 << ln;
		bt.add(x,-1);
	}
}