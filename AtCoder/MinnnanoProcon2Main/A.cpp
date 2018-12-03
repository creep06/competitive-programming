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

// aをiで割り切れるならiの倍数全てのカウントを1減らす O(N*sqrt(N)^2 == N^2)くらい？
// これを高速化するには？セグ木とかでいける？
// aごとにやるんじゃなく1〜10^5全てについて一気に求める的な？


int n, m, a[100100], w[100100], y[100100];
vi p[100100];

void primefactor(int n) {
	int N = n;
	map<int,bool> f;
	for (int i = 2; i*i <= n; i++) {
		if (n%i!=0) continue;
		p[N].pb(i), f[i] = true;
		while (n%i==0) n /= i;
	}
	if (n!=1 && !f[n]) p[N].pb(n);
}

vi pf(int n) {
	int N = n;
	vi res;
	map<int,bool> f;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i!=0) continue;
		res.pb(i), f[i] = true;
		while (n%i==0) n /= i;
	}
	if (n!=1 && !f[n]) res.pb(n);
	return res;
}

void divisor(int n) {
	for (int i = 1; i <= sqrt(n); ++i) {
		if (n%i==0) {
			y[i]++;
			if (i!=n/i) y[n/i]++;
		}
	}
}


signed main() {
	repst(i,2,100000) primefactor(i);
	cin >> n >> m;
	rep(i,n) {
		cin >> a[i];
		divisor(a[i]);
		each(j,p[a[i]]) w[j]++;
	}
	cout << n << ln;
	// これだと例えばi==6のときn-(2で割り切れるaの個数)-(3で割り切れるaの個数)を求めることになる
	// 2でも3でも割り切れるaを2重に引いてしまう
	// 重複しないようにするには？
	// 10^5以下の整数は素因数がたかだか6種類しかないらしい 2^6 = 64
	// これらのうち2個以上の積で割り切れるものの個数を足してやればいい
	repst(i,2,m) {
		vi pi = pf(i);
		int r = n;
		each(j,pi) r -= w[j];
		rep(j,1<<p[i].size()) {
			int c = __builtin_popcount(j);
			if (c<=1) continue;
			int s = 1;
			rep(k,p[i].size()) if (j>>k&1) s *= p[i][k];
			if (c%2==0) r += y[s];
			else r -= y[s];
		}
		cout << r << ln;
	}
}