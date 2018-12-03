#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <string.h>
#include <numeric>
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

//typedef complex<double> P;
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



int n, m, a, b, c, t;
vector<tuple<int,int,int> > et[114514];
vector<int> d[114514];
map<int,map<int,int> > tr, rv;

void dijkstra() {
	priority_queue<tuple<int,int,int>, vector<tuple<int,int,int> >, greater<tuple<int,int,int> > > que;
	que.push(make_tuple(0,0,0));
	while(!que.empty()) {
		int dis, v, col;
		tie(dis,v,col) = que.top(); que.pop();
		int dv = d[v][tr[v][col]];
		if (dv<dis) continue;
		if (v==n-1) return;
		for (int i = 0; i < et[v].size(); ++i) {
			int to, ch, cost;
			tie(to,ch,cost) = et[v][i];
			cost += abs(col-ch);
			if (d[to][tr[to][ch]] > dv + cost) {
				d[to][tr[to][ch]] = dv + cost;
				que.push(make_tuple(d[to][tr[to][ch]], to, ch));
			}
		}
	}
}

signed main() {
	cin >> n >> m;
	rep(i,m) {
		cin >> a >> b >> c >> t;
		a--, b--, c--;
		et[a].push_back(make_tuple(b,c,t)), et[b].push_back(make_tuple(a,c,t));
	}
	rep(v,n) {
		set<int> col;
		each(i,et[v]) {
			tie(b,c,t) = i;
			col.insert(c);
		}
		int cnt = 0;
		if (v==0 && !col.count(0)) tr[0][0] = 0, rv[0][0] = 0, d[v].push_back(0), cnt++;
		each(i,col) {
			tr[v][i] = cnt, rv[v][cnt++] = i;
			d[v].push_back(linf);
		}
	}
	d[0][0] = 0;
	dijkstra();
	int res = linf;
	each(i,d[n-1]) chmin(res,i);
	cout << res << endl;
}
