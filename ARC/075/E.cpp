#include <bits/stdc++.h>
using namespace std;

#define int long long
#define reps(i,s,n) for(ll (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,n+1)
#define repst(i,s,n) reps(i,s,n+1)
#define reprt(i,n,t) for(ll (i)=(n);(i)>=t;--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb emplace_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) for(int (i)=0;i<n;++i){cout<<x[i]<<(i==n-1?'\n':' ');}

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

// a[l], a[l+1], ..., a[r-1]の平均がk以上 というのは↓のように言い換えられる
// https://drive.google.com/open?id=1TXSdOrUMMpPNGxPieiC2hORo8_wAEIJi
// 配列b[0,n]をO(n)で作ってからbの値を[1,n+1]に圧縮して、
// あとはBITで各iについてb[0], b[1], ..., b[i-1]のうちb[i]以下のものだけカウントして答えに加算していく感じで
// ※圧縮後の値は最大でn+1個だからnのままBIT使うとバグるケースが1個だけ(b14)ある
// 式変形がポイントの問題

int n, k, a[200200], b[200200], r;
pii c[200200];
int bit[200200];

int sum(int i) {
	int s = 0;
	while (i>0) {
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x) {
	while (i<=n+2) {
		bit[i] += x;
		i += i & -i;
	}
}

signed main() {
	cin >> n >> k;
	rep(i,n) cin >> a[i];
	repst(i,1,n) {
		a[i] += a[i-1];
		b[i] = a[i-1] - i*k;
		c[i].fi = b[i], c[i].se = i;
	}
	sort(c, c+1+n);
	// 同じ値があるときに注意
	int s = 1;
	rept(i,n) {
		if (i>0 && c[i].fi!=c[i-1].fi) s++;
		b[c[i].se] = s;
	}
	rept(i,n) {
		r += sum(b[i]);
		add(b[i],1);
	}
	cout << r << ln;
}