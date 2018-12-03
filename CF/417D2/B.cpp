#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
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
#define bln(i,n) (i==n-1?'\n':' ')
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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

int n, m, d, l[15], r[15], ret = inf;
string t[15];
vst s;

signed main() {
	cin >> n >> m;
	memset(l,-1,sizeof(l)), memset(r,-1,sizeof(r));
	repr(i,n-1) cin >> t[i];
	rep(i,n) {
		bool z = true;
		rep(j,m+2) if (t[i][j]=='1') z = false;
		if (!z) s.pb(t[i]);
	}
	bool st = false;
	repr(i,n-1) {
		bool z = true;
		rep(j,m+2) if (t[i][j]=='1') z = false;
		if (!z) st = true;
		if (st && z) d++;
	}
	n = s.size();
	if (n==0) return cout << 0 << ln, 0;
	rep(i,n) {
		rep(j,m+2) if (s[i][j]=='1') r[i] = j;
		repr(j,m+1) if (s[i][j]=='1') l[i] = j;
	}
	rep(i,1<<n) {
		int x = 0, sum = d;
		rep(j,n) {
			if (j==n-1) sum += (x==0 ? r[j] : x-l[j]);
			else if (i>>j&1) { // 右
				if (x==0) sum += m+1 + 1, x = m+1;
				else sum += (x-l[j])*2 + 1;
			} else { // 左
				if (x==0) sum += r[j]*2 + 1;
				else sum += m+1 + 1, x = 0;
			}
		}
		chmin(ret,sum);
	}
	cout << ret << ln;
}