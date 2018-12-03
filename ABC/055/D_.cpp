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

int n;
bool m[114514];
string s;

void p(bool x, bool y) {
	bool h[114514] = {};
	h[0] = x, h[1] = y;
	reps(i,1,n) h[i+1] = (h[i]==m[i]) ? h[i-1] : 1-h[i-1];
	reps(i,1,n-1) if ((h[i]&&((m[i]&&h[i-1]!=h[i+1])||(!m[i]&&h[i-1]==h[i+1])))
			|| !h[i]&&((m[i]&&h[i-1]==h[i+1])||(!m[i]&&h[i-1]!=h[i+1]))) return;
	if ((h[0]&&((m[0]&&h[n-1]!=h[1])||(!m[0]&&h[n-1]==h[1])))
		|| !h[0]&&((m[0]&&h[n-1]==h[1])||(!m[0]&&h[n-1]!=h[1]))) return;
	if ((h[n-1]&&((m[n-1]&&h[n-2]!=h[0])||(!m[n-1]&&h[n-2]==h[0])))
		|| !h[n-1]&&((m[n-1]&&h[n-2]==h[0])||(!m[n-1]&&h[n-2]!=h[0]))) return;
	rep(i,n) cout << (h[i] ? 'S' : 'W');
	cout << ln;
	exit(0);
}

signed main() {
	cin >> n >> s;
	rep(i,n) m[i] = s[i]=='o';
	rep(i,2) rep(j,2) p(i,j);
	cout << -1 << ln;
}