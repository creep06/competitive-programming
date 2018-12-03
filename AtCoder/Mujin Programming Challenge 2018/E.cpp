#include <bits/stdc++.h>
using namespace std;

#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto &(itr):(v))
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define bln(i,n) (((i)==(n)-1)?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln<<flush
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ')<<flush;}}
#define zero(a) memset(a,0,sizeof(a))
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())

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

// 現在の秒数から、上下左右それぞれに進むのにかかるコストが決まる
// 今いる場所は関係ない どのマスでも同じ

int h, w, k, e[4][100100], res[1001001];
vector<int> id[4];
string d, s[1010];

int dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii> > que;
	fill(res, res+h*w, linf);
	int si = 0, sj = 0, gi = 0, gj = 0;
	rep(i,h) rep(j,w) {
		if (s[i][j]=='S') si = i, sj = j;
		if (s[i][j]=='G') gi = i, gj = j;
	}
	res[si*w+sj] = 0;
	que.push({0,si*w+sj});
	while(!que.empty()) {
		pii p = que.top(); que.pop();
		int v = p.second, dis = p.first;
		int x = v/w, y = v%w;
		if (res[v] < dis) continue;
		for (int i = 0; i < 4; ++i) {
			int xx = x + dx[i], yy = y + dy[i];
			if (ool(xx,yy,h,w) || s[xx][yy]=='#') continue;
			int u = xx*w+yy, cost = e[i][dis%k];
			if (res[u] > res[v] + cost) {
				res[u] = res[v] + cost;
				que.push({res[u],u});
			}
		}
	}
	return res[gi*w+gj];
}

signed main() {
	cin >> h >> w >> k >> d;
	d += d;
	rep(i,h) cin >> s[i];
	rep(i,d.size()) {
		if (d[i]=='R') id[0].push_back(i);
		else if (d[i]=='D') id[1].push_back(i);
		else if (d[i]=='L') id[2].push_back(i);
		else id[3].push_back(i);
	}
	rep(j,4) rep(i,k) {
		auto it = lower_bound(all(id[j]),i);
		if (it==id[j].end()) e[j][i] = linf;
		else e[j][i] = *it-i+1;
	}
	int ans = dijkstra();
	cout << (ans==linf ? -1 : ans) << ln;
}