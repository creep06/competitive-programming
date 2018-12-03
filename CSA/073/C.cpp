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

int t, n, p, dep, dep2;

void rec(int v, int m, vi *e, vi *d) {
	d[m].pb(e[v].size());
	chmax(dep,m);
	each(i,e[v]) rec(i,m+1,e,d);
}

void rec2(int v, int m, vi *e, vi *d) {
	d[m].pb(e[v].size());
	chmax(dep2,m);
	each(i,e[v]) rec2(i,m+1,e,d);
}

signed main() {
	cin >> t;
	while (t--) {
		cin >> n;
		int p1 = 0, p2 = 0;
		vi e[n];
		rep(i,n) {
			cin >> p;
			if (p==0) {
				p1 = i;
				continue;
			}
			e[p-1].pb(i);
		}
		vi e2[n];
		rep(i,n) {
			cin >> p;
			if (p==0) {
				p2 = i;
				continue;
			}
			e2[p-1].pb(i);
		}
		dep = dep2 = 0;
		vi d[100000], d2[100000];
		rec(p1,0,e,d), rec2(p2,0,e2,d2);
		if (dep!=dep2) {
			cout << 0 << ln;
			goto fin;
		}
		rept(i,dep) {
			int si = d[i].size();
			if (si!=d2[i].size()) {
				cout << 0 << ln;
				goto fin;
			}
			sort(all(d[i])), sort(all(d2[i]));
			rep(j,si) if (d[i][j]!=d2[i][j]) {
					cout << 0 << ln;
					goto fin;
				}
		}
		cout << 1 << ln;
		fin:;
	}
}