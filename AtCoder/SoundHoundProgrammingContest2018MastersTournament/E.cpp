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

// ある点に書く数字を1増やすとその点からの距離が奇数の点に書く数字は1減り、偶数の点は1増える
// 適当な点に1を書き込んでみると他の点で足りない数・余る数がわかる？
// これで下限と上限がわかる 範囲の幅が答え
// ↑これは全頂点への原点からの距離の偶奇が1通りの場合 2通りの点があるなら条件が複雑化する ex1とかがそう
// その場合だけ答えは1か0になるからうまく場合分けしたい
// 距離の偶奇とnumが同じならbfs続行、違うならbfsをやめて両方満たすように調整して矛盾が生まれないかチェックし直し、生まれないなら1、生まれたら0

int n, m, a, b, c, d[114514], num[114514];
vi od, ev;
vpii e[114514];

signed main() {
	cin >> n >> m;
	rep(i,m) {
		cin >> a >> b >> c;
		a--, b--;
		e[a].pb({b,c}), e[b].pb({a,c});
	}
	queue<pii> q;
	q.push({0,0});
	bool us[114514] = {};
	us[0] = 1;
	while (!q.empty()) {
		int v = q.front().fi, dis = q.front().se; q.pop();
		each(i,e[v]) {
			int u = i.fi, c = i.se;
			// 探索済みで矛盾してる場合
			if (us[u] && num[v]+num[u]!=c) {
				// 一致してるなら両方増やすか両方減らす
				if (d[v]%2==d[u]%2) {
					int dif = c - (num[u]+num[v]);
					if (dif%2) return cout << 0 << ln, 0;
					dif /= 2;
					int s = (d[v]%2 ? -dif : dif);
					if (s<=0) return cout << 0 << ln, 0;
					queue<pii> qq;
					qq.push({0,0});
					zero(us), zero(num), zero(d);
					num[0] = s;
					us[0] = 1;
					//cout << "ここまで" << ln << flush;
					while (!qq.empty()) {
						v = qq.front().fi, dis = qq.front().se; qq.pop();
						each(j,e[v]) {
							u = j.fi, c = j.se;
							// 探索済みで矛盾してる場合
							if (us[u] && num[v]+num[u]!=c) return cout << 0 << ln, 0;
							else if (!us[u]) us[u] = 1, qq.push({u,dis+1}), d[u] = dis+1, num[u] = c - num[v];
						}
					}
					//cout << "ここまで" << ln << flush;
					rep(i,n) if (num[i]<=0) return cout << 0 << ln, 0;
					return cout << 1 << ln, 0;
				}
				// してないならもうむり
				else return cout << 0 << ln, 0;
			}
			else if (!us[u]) us[u] = 1, q.push({u,dis+1}), d[u] = dis+1, num[u] = i.se - num[v];
		}
	}
	rep(i,n) {
		if (d[i]%2==0) ev.pb(num[i]);
		else od.pb(num[i]);
	}
	sort(all(od)), sort(all(ev));
	int l = 1-ev[0]; // l以上が必要
	int r = od[0]-1;
	int res = max(r-l+1,0ll);
	cout << res << ln;
}