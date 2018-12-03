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

// NがL桁の整数だと仮定すると、L桁の整数nとNの大小はstr(n)とstr(N)の大小と一致する
// 10nとNの大小は？ n<Nのときstr(10n)<str(N) n>=Nのときstr(10n)>str(N)
// つまり"? 10n"に対してYが返ってくるL桁の最小の整数nがNってことになる 桁数Lがわかれば二分探索できる
// Lは"? 10^(k-1)"にYが返ってくる最大のkで求められる
// ただしNが10^aって形の場合は例外で "? 10^k"に対してはkをどこまで大きくしてもYが返ってきてしまう
// この場合だけ"? 2*10^k"でYが返ってくる最小のkがL

int l, le, ri;

bool q(ll n) {
	cout << "? " << n << ln << flush;
	char c;
	cin >> c;
	return c=='Y';
}

void fin(ll n) {
	cout << "! " << n << ln << flush;
}

signed main() {
	bool ten = false;
	rep(i,10) {
		if (!q(pow(10ll,i))) {
			l = i-1;
			break;
		}
		if (i==9) ten = true;
	}
	// N = 10^a
	if (ten) {
		rep(i,10) {
			if (q(pow(10ll,i)*2)) {
				fin(pow(10ll,i));
				return 0;
			}
		}
	}
	// N != 10^a
	le = pow(10ll,l), ri = le*10;
	while (ri-le>1) {
		int m = (le+ri)/2;
		if (q(m*10)) ri = m;
		else le = m;
	}
	fin(ri);
}