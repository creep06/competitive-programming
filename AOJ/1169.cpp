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

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m;for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
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

// 文字数が決まれば最適解も決まる ∴ 頂点と文字数って状態を持ってdpできる
// 負の閉路が存在しなければ文字列長はたかだか240 逆にそれを超えたら存在する
// でも閉路があったとしてもそこを通らずにgまで行ったほうがいい場合は答えは存在する
// 探索時は300文字までで切り上げてmin(d[g][[0,300]])のサイズが240を超えてたらNO

struct S {
	int v, l; // 頂点 文字列長
	string s; // 文字列
	S(int vv, int ll, string ss) {v = vv, l = ll, s = ss;}
	bool operator > (const S &e) const {return s.compare(e.s)>=0;}
};

int n, a, s, g, x, y;
string lab, d[40][555];
vector<S> e[40][555];

void dijkstra() {
	priority_queue<S, vector<S>, greater<S> > que;
	que.push(S(s,0,""));
	while(!que.empty()) {
		S p = que.top(); que.pop();
		int v = p.v, len = p.l;
		string st = p.s;
		if (d[v][len] < st) continue;
		for (int i = 0; i < e[v][len].size(); ++i) {
			S q = e[v][len][i];
			int u = q.v, nlen = q.l;
			string nst = q.s;
			if ((d[u][nlen].empty() || d[u][nlen] > d[v][len] + nst) && nlen<=500) {
				d[u][nlen] = d[v][len] + nst;
				que.push(S(u, nlen, d[u][nlen]));
			}
		}
	}
}

signed main() {
	while (1) {
		cin >> n >> a >> s >> g;
		if (n==0) break;
		rep(i,n) rept(j,500) d[i][j].clear(), e[i][j].clear();
		rep(i,a) {
			cin >> x >> y >> lab;
			rept(j,500) e[x][j].pb(S(y,j+lab.size(),lab));
		}
		dijkstra();
		string res;
		rept(i,500) if (!d[g][i].empty() && (res.empty() || res>d[g][i])) res = d[g][i];
		if (res.size()>300 || res.empty()) cout << "NO" << ln;
		else cout << res << ln;
	}
}