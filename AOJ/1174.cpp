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

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m; assert(b>=0); for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}
bool ool(int x,int y,int h,int w) {return((x<0)||(h<=x)||(y<0)||(w<=y));}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// 5回目はcに変えるの確定 その前の変え方6^4通りを試すだけ
int h, w, c, s[8][8], res;

int p(int d) {
	d += c*10000;
	int t[8][8] = {};
	rep(i,h) rep(j,w) t[i][j] = s[i][j];
	rep(k,5) {
		int l = t[0][0], r = d%10;
		d /= 10;
		if (l==r) continue;
		queue<pii> q;
		q.push({0,0});
		while (!q.empty()) {
			int x = q.front().fi, y = q.front().se; q.pop();
			t[x][y] = r;
			rep(i,4) {
				int xx = x + dx[i], yy = y + dy[i];
				if (ool(xx,yy,h,w) || t[xx][yy]!=l) continue;
				q.push({xx,yy});
			}
		}
	}
	queue<pii> q;
	q.push({0,0});
	bool u[8][8] = {};
	while (!q.empty()) {
		int x = q.front().fi, y = q.front().se; q.pop();
		u[x][y] = 1;
		rep(i,4) {
			int xx = x + dx[i], yy = y + dy[i];
			if (ool(xx,yy,h,w) || t[xx][yy]!=c || u[xx][yy]) continue;
			q.push({xx,yy});
		}
	}
	int sum = 0;
	rep(i,h) rep(j,w) sum += u[i][j];
	return sum;
}

void cal(int d, int t) {
	if (t==4) chmax(res,p(d));
	else repst(i,1,6) cal(d*10+i, t+1);
}

signed main() {
	while (1) {
		cin >> h >> w >> c;
		if (h==0) break;
		rep(i,h) rep(j,w) cin >> s[i][j];
		res = 0;
		cal(0,0);
		cout << res << ln;
	}
}