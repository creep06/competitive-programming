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

#define tpl tuple<int,int,int>
#define mt(a,b,c) make_tuple((a),(b),(c))

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// 町vまでタイプBの道をa本、b本(a<b)使って行けるルートがあるとすると
// b(b+1)/2 - a(a+1)/2 > n-1なら後者のルートは考えなくていい

int n, m;
vi e0[10000], e1[10000];
vi d(10000,INT_MAX);

signed main() {
	cin >> n >> m;
	rep(i,m) {
		int a, b, c;
		cin >> c >> a >> b;
		if (c) e1[a].pb(b), e1[b].pb(a);
		else e0[a].pb(b), e0[b].pb(a);
	}
	priority_queue<tpl, vector<tpl>, greater<tpl>> q;
	q.push(mt(0,0,0));
	while (!q.empty()) {
		int b, cost, cur;
		tie(b,cost,cur) = q.top(); q.pop();
		if (d[cur]<=cost) continue;
		d[cur] = cost;
		each(i,e0[cur]) if (cost+1<d[i]) q.push(mt(b, cost+1, i));
		each(i,e1[cur]) if (cost+b+1<d[i]) q.push(mt(b+1, cost+b+1, i));
	}
	rep(i,n) cout << d[i] << ln;
}