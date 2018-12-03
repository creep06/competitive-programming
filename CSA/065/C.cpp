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

int n, a, b, st;
vi e[100000];
vi r, re;
bool us[100000];
int d[100000];

int rec(int v, int d) {
	if (e[v].size()>=2) return d;
	else return rec(e[v][0], d+1);
}

void bb(int v, int d) {
	r.pb(v);
	if (e[v].size()==1) bb(e[v][0], d+1);
}

vi bfs(int s) {
	queue<pii> q;
	int md = 0, mi = 0;
	q.push({s,0});
	us[s] = true;
	while (!q.empty()) {
		int v = q.front().fi, dis = q.front().se;
		q.pop();
		each(i,e[v]) {
			if (!us[i]) {
				q.push({i,dis+1});
				us[i] = true;
				d[i] = dis+1;
				if (d[i]>md) {
					md = d[i];
					mi = i;
				}
			}
		}
	}
	// miがsから一番遠い点
	fill(us, us+n, false);
	us[mi] = true;
	vi ev;
	int v = mi;
	ev.pb(v);
	while (e[e[v][0]].size()==1) {
		v = e[v][0];
		us[v] = true;
		ev.pb(v);
	}
	reverse(all(ev));
	return ev;
}

signed main() {
	cin >> n;
	rep(i,n-1) {
		cin >> a >> b;
		a--, b--;
		e[a].pb(b), e[b].pb(a);
	}
	// 一番入次数の多い点から最も遠い点からスタートすればいい？
	// とりあえずスタート地点は入次数が1の点が最善なのは明らか
	// 往復する辺を最小化したい
	// 始点を選べるってことは複数ある枝のうち最も長いものを1個往復しなくてよくできるってこと
	// つまり一番長い枝の端点からスタートすればいい
	int l = 0;
	rep(i,n) if (e[i].size()==1) {
		int tmp = rec(i,0);
		if (tmp>l) l = tmp, st = i;
	}
	// でBFS？終点も選べるから終点もなるべく長い枝の端点にした方がいい
	// 分岐がk個あったらk-1個往復して、残り1個一番長いやつを後回しにする必要がある
	// とりえあえず終点
	re = bfs(st);
	r.pb(st);
	
}