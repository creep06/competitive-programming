#include <bits/stdc++.h>
using namespace std;

#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define each(itr,v) for(auto &(itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define dbg(x) cout<<#x" = "<<(x)<<ln<<flush
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ')<<flush;}}

typedef complex<double> P;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
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

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m;for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}
bool ool(int x,int y,int h,int w) {return((x<0)||(h<=x)||(y<0)||(w<=y));}
bool deq(double a,double b) {return abs(a-b)<eps;}

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
pair<pair<int,int>,int> p[114514];
vector<pair<int,int> > e[114514];

int prim() {
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	bool used[n];
	memset(used, 0, sizeof(used));
	q.push({0,0});
	int res = 0;
	while (!q.empty()) {
		int cost = q.top().first, v = q.top().second; q.pop();
		if (used[v]) continue;
		used[v] = true;
		res += cost;
		for (auto &i:e[v]) q.push({i.second, i.first});
	}
	return res;
}

signed main() {
	cin >> n;
	rep(i,n) {
		cin >> p[i].fi.fi >> p[i].fi.se;
		p[i].se = i;
	}
	sort(p,p+n);
	rep(i,n-1) e[p[i].se].push_back({p[i+1].se, p[i+1].fi.fi-p[i].fi.fi}), e[p[i+1].se].push_back({p[i].se, p[i+1].fi.fi-p[i].fi.fi});
	rep(i,n) swap(p[i].fi.fi, p[i].fi.se);
	sort(p,p+n);
	rep(i,n-1) e[p[i].se].push_back({p[i+1].se, p[i+1].fi.fi-p[i].fi.fi}), e[p[i+1].se].push_back({p[i].se, p[i+1].fi.fi-p[i].fi.fi});
	cout << prim();
}