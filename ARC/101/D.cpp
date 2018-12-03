#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <string.h>
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
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define bln(i,n) (((i)==(n)-1)?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln<<flush
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ')<<flush;}}
#define zero(a) memset(a,0,sizeof(a))
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())

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



// ある数列の中央値がmのとき、
// 数列の長さが偶数のとき) m以上の要素
// 奇数のとき) m以下の要素
// を1つ追加した数列の中央値もm

// (m以下の要素数) - (m以上の要素数) = 0,1ならmが中央値
// 各要素の右側と左側の↑の値の個数がわかれば
// 例えば左側に↑の値が2になる場所が3個、右側に-1になる場所と-2になる場所が計4個あるならmは3*4回中央値になる と計算できる
// これがわかったとしても要素ごとにO(N)かかる
// 二分探索でk以下の要素が中央値になる回数を求めると？
// k以下の数とk超過の数の2通りだけ考えればよくなる
// (k以下の数) - (k超過の数) >= 1ならok

template<class T, int ME> class BIT {
	public:
	T bit[1<<ME],val[1<<ME];
	T sum(int e) {T s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	T add(int e,T v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	T set(int e,T v) { add(e,v-val[e]);}
	int lb(T v) {
		T tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<v) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};

int n, a[100100], m, l = -1, r;
map<int,int> c, d;
set<int> s;
BIT<int,20> f;

int cnt(int k) {
	int sum = 0, ret = 0;
	reps(i,-100100,100100) f.set(i+114514,0);
	f.add(114514,1);
	rep(i,n) {
		sum += (a[i]<=k ? 1 : -1);
		f.add(sum+114514,1);
		ret += f.sum(sum+114513);
	}
	return ret;
}

signed main() {
	cin >> n;
	rep(i,n) cin >> a[i];
	rep(i,n) s.insert(a[i]);
	each(i,s) c[i] = m, d[m] = i, m++;
	rep(i,n) a[i] = c[a[i]];
	r = m-1;
	while (r-l>1) {
		int md = (l+r)/2;
		if (cnt(md) > n*(n+1)/4) r = md;
		else l = md;
	}
	cout << d[r] << endl;
}
