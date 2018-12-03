#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
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

int res = inf, es[1001001];
vi so[1001001], p;
int PS;

void sieve() {
	fill(es, es+1000001, 1);
	es[0] = es[1] = 0;
	for (int i = 2; i*i <= 1000001; ++i) {
		if (es[i]) {
			for (int j = 2*i; j <= 1000001; j += i) es[j] = false;
		}
	}
	rep(i,1000001) if (es[i]) p.pb(i);
	PS = p.size();
}

void pf(int N) {
	int n = N;
	for (int i = 0; i<PS && (ll)p[i]*(ll)p[i] <= n; i++) {
		if (n%p[i]==0) so[N].pb(p[i]);
		while (n%p[i]==0) n /= p[i];
	}
	if (n!=1) so[N].pb(n);
}

int x2;

signed main() {
	cin >> x2;
	// psそれぞれについて(c-ps,c]がX1の候補 100万以下の制約ならpsは最大で7通りしかない
	// X1の素因数のひとつpについて、pの倍数のうちX0以上の最小値がX1であるものが
	sieve();
	repst(i,2,1000000) pf(i);
	
	each(i,so[x2]) {
		repst(x1,x2-i+1,x2) {
			if (es[x1]) continue;
			each(j,so[x1]) {
				//cout << "i:" << i << "x1:" << x1 << " j:" << j << " x0:" << x1-j+1 << ln;
				chmin(res,x1-j+1);
			}
		}
	}
	
	cout << res << ln;
}