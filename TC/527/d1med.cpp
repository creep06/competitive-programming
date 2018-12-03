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

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(i,v) for(auto &(i):(v))
#define eachr(i,v) for(auto &(i)=(v).rbegin();(i)!=(v).rend();(i)++)
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
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
bool ool(int x,int y,int h,int w) {return((x<0)||(h<=x)||(y<0)||(w<=y));}
bool deq(double a,double b) {return abs(a-b)<eps;}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;



// 辞書順最小の条件より1行目から順に決めたい
// 手前のはてながなるべく0になるようにしたい
// 手前のはてなから順に見ていき、0にしてもマッチングが可能なら0に、無理なら1にする
// これを繰り返せば答えが定まる
// すると二部グラフが完全マッチングが可能かどうか判定をする問題になる

const int MAXV = 123;
class Dinic {
private:
struct edge {int to, cap, rev;};
	vector<edge> g[MAXV];
	int level[MAXV], iter[MAXV];
public:
	// fromからtoへ向かう要領capの辺をグラフに追加する
	void add_edge(int from, int to, int cap) {
		g[from].push_back((edge){to, cap, (int)g[to].size()});
		g[to].push_back((edge){from, 0, (int)g[from].size()-1});
	}
	// sからの最短距離をBFSで計算
	void bfs(int s) {
		memset(level, -1, sizeof(level));
		queue<int> que;
		level[s] = 0;
		que.push(s);
		while (!que.empty()) {
			int v = que.front(); que.pop();
			for (int i = 0; i < g[v].size(); i++) {
				edge &e = g[v][i];
				if (e.cap>0 && level[e.to]<0) {
					level[e.to] = level[v] + 1;
					que.push(e.to);
				}
			}
		}
	}
	// 増加パスをdfsで探す
	int dfs(int v, int t, int f) {
		if (v==t) return f;
	for (int &i = iter[v]; i < g[v].size(); ++i) {
			edge &e = g[v][i];
			if (e.cap>0 && level[v]<level[e.to]) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d>0) {
					e.cap -= d;
					g[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	// sからtへの最大流を求める
	int getflow(int s, int t) {
		int flow = 0;
		while (1) {
			bfs(s);
			if (level[t]<0) return flow;
			memset(iter, 0, sizeof(iter));
			int f;
			while ((f=dfs(s, t, inf))>0) flow += f;
		}
	}
};

class P8XMatrixRecovery {
public:
	int h, w;
	vector<string> rs, cs;

	bool ok() {
		Dinic din;
		rep(i,w) rep(j,w) {
			bool ng = 0;
			rep(k,h) if (rs[k][i]!='?' && cs[j][k]!='?' && rs[k][i]!=cs[j][k]) {
				ng = 1;
				break;
			}
			if (!ng) din.add_edge(i+1,w+j+1,1);
		}
		rep(i,w) din.add_edge(0,i+1,1), din.add_edge(w+i+1,100,1);
		return din.getflow(0,100)==w;
	}

	vector<string> solve(vector<string> R, vector<string> C) {
		rs = R, cs = C, h = rs.size(), w = cs.size();
		rep(i,h) rep(j,w) if (rs[i][j]=='?') {
			rs[i][j] = '0';
			if (!ok()) rs[i][j] = '1';
		}
		return rs;
	}
};
