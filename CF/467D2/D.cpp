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

// 頂点sからスタートして10^6以下の奇数回の移動で出次数0の頂点に移動できればWIN
// それは無理だけどループして時間稼ぎできる場所があるならDRAW それも無理ならLOSE
// メモ化再帰

int n, m, c, t, s, vis[100100][2], dp[100100][2];
vi e[100100], r;

int rec(int v, int st) {
	if (vis[v][st]) return dp[v][st];
	vis[v][st] = 1;
	int res = 0;
	if (e[v].empty()) {
		if (st==0) res = -1;
		else {
			r.pb(v+1);
			res = 1;
		}
	} else {
		int draw = 0;
		each(to,e[v]) {
			res = rec(to, 1-st);
			if (res==1) {
				r.pb(v+1);
				return dp[v][st] = 1;
			} else if (res==0) draw = 1;
		}
		res = (draw ? 0 : -1);
	}
	return dp[v][st] = res;
}

signed main() {
	cin >> n >> m;
	rep(i,n) {
		cin >> c;
		rep(j,c) {
			cin >> t;
			e[i].pb(t-1);
		}
	}
	cin >> s; s--;
	int res = rec(s,0);
	if (res==-1) cout << "Lose" << ln;
	else if (res==0) cout << "Draw" << ln;
	else {
		cout << "Win" << ln;
		repr(i,r.size()-1) cout << r[i] << (i==0 ? '\n' : ' ');
	}
}