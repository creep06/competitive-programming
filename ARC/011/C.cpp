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

string s[1010];
int n, l, d[1010], f[1010];
vi e[1010];
queue<pii> q;

signed main() {
	cin >> s[0] >> s[1] >> n;
	l = s[0].length();
	if (s[0]==s[1]) {
		cout << 0 << ln << s[0] << ln << s[1] << ln;
		return 0;
	}
	repst(i,2,n+1) cin >> s[i];
	// 移動できる2頂点間を結んでbfs
	rept(i,n+1) {
		repst(j,i,n+1) {
			int dif = 0;
			rep(k,l) dif += (s[i][k] != s[j][k]);
			if (dif==1) e[i].pb(j), e[j].pb(i);
		}
	}
	fill(d, d+1010, inf);
	fill(f, f+1010, -1);
	d[0] = 0;
	q.push(mp(0,0));
	while (!q.empty()) {
		int dis = q.front().fi, v = q.front().se;
		q.pop();
		each(to,e[v]) if (d[to]>dis+1) {
			d[to] = dis + 1;
			f[to] = v;
			q.push(mp(dis+1, to));
		}
	}
	if (d[1]==inf) cout << -1 << ln;
	else {
		vi r;
		int i = 1;
		while (i!=0) {
			r.pb(i);
			i = f[i];
		}
		cout << r.size()-1 << ln << s[0] << ln;
		repr(k,r.size()-1) cout << s[r[k]] << ln;
	}
}