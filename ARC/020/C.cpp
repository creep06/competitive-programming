#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rept(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
#define repst(i,s,n) for(int (i)=(s);(i)<=(int)(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > mat;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
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

// a[i](桁数がd[i])がl[i]個、a[i+1]がl[i+1]個、...と繰り返されている数字AをBで割った余りを求めたい
// 例えば123123123...なら123*(1 + 10^3 + 10^6 + ... + 10^(l-1)*3) と分解できる
// つまりa[i] * (10^l[i]d[i] - 1) / (10^d[i] - 1)
// Bが素数ならフェルマーの小定理で求められる(部分点) Bが素数じゃないときはダブリング
// ある数字が2^n回繰り返されたものから2^(n+1)回繰り返されたものを作るには、例えば123123から123123123123を作るとき
// 123123123123 = 123123000000 + 123123 = 123123 * ((10^3)^2 + 1)
// 一般化して、d桁の数aを2^n回繰り返したものの余りをr(a,n)とおくと
// r(a,n+1) = r(a,n) * (10^(d*2^n) + 1) %B
// 10^X %Bは二分累乗で求められる

ll n, a[100000], l[100000], d[100000], m;
ll re[50], ans;

// 10のn乗
ll ten(ll n) {
	ll res = 1, x = 10;
	while (n>0) {
		if (n&1) res = res * x %m;
		x = x * x %m;
		n >>= 1;
	}
	return res;
}

// a[j]を2^k回繰り返した数の%m のテーブルre[k]を作る
void mre(int j) {
	re[0] = a[j] %m;
	ll two = 1;
	reps(i,1,50) re[i] = re[i-1]*(ten(d[j]*two) + 1) %m, two *= 2;
}

// a[j]をl[j]回繰り返した数の%m
ll cal(int j) {
	ll res = 0, N = l[j], dig = 0, two = 1;
	rep(i,50) {
		if (N&1) {
			dig = two * d[j];
			res = (res*ten(dig) + re[i]) %m;
		}
		N >>= 1;
		if (N==0) break;
		two *= 2;
	}
	return res;
}

signed main() {
	cin >> n;
	rep(i,n) {
		cin >> a[i] >> l[i];
		d[i] = to_string(a[i]).length();
	}
	cin >> m;
	
	re[0] = 10%m;
	reps(i,1,50) re[i] = re[i-1]*re[i-1] %m;
	ll dig = 0;
	rep(i,n) {
		mre(i);
		dig = d[i]*l[i];
		ans = (ans*ten(dig) %m + cal(i)) %m;
	}
	cout << ans << ln;
}