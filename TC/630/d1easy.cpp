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
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define log2(x) log(x)/log(2)
#define ln '\n'
#define bln(i,n) (i==n-1?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

/*
 * (問題)
 * 重み付き木が与えられる
 * どの2頂点間の距離も同じ値dであるような頂点の集合のサイズの最大値を求めよ
 *
 * (解法)
 * とりあえずワーシャルフロイドして出来る配列に出てくる値を全てdの候補としてsetに入れる
 * で全頂点から再帰で距離dの点の個数を数え上げて最大値をとればいい
 * でもただ数えるだけじゃダメで、
 * 再帰の始点をp、その直接の子をv0,v1,...,vkとし、dist(vi,vj) = Dとする
 * ここでviを親とする部分木の中にpとの距離がdである点が2個以上あっても1個しか集合に採用できない
 * 仮に2点あったとしてa,bとすると、(dist(a,p) = dist(b,p) = d)
 * dist(a,b) ≠ Dが証明できるため (∵ dist(a,b) = Dが成り立つと仮定するとdist(p,vi) = 0になって矛盾する)
 * あとn==1ならres=1はいいとしてn>=2なら最低でもres=2になることに注意
 *
 * 隣接リストと隣接行列の併用があんまり美しくない
 */

class Egalitarianism3 {
	public:
	vpii e[50];
	
	int rec(int v, int dis, int p) {
		if (dis==0) return 1;
		int cnt = 0;
		if (p==-1) each(i,e[v]) if (i.se<=dis) cnt += rec(i.fi,dis-i.se,v);
		if (p!=-1) each(i,e[v]) if (i.fi!=p && i.se<=dis) chmax(cnt, rec(i.fi,dis-i.se,v));
		return cnt;
	}
	
	int maxCities(int n, vi a, vi b, vi c) {
		int d[50][50] = {};
		rep(i,n) rep(j,n) if (i!=j) d[i][j] = inf;
		rep(i,n-1) {
			a[i]--, b[i]--;
			e[a[i]].pb({b[i],c[i]}), e[b[i]].pb({a[i],c[i]});
			d[a[i]][b[i]] = d[b[i]][a[i]] = c[i];
		}
		rep(k,n) rep(i,n) rep(j,n)
		    chmin(d[i][j], d[i][k]+d[k][j]);
		set<int> pd;
		rep(i,n) reps(j,i+1,n) pd.insert(d[i][j]);
		int res = 1 + (n>=2);
		rep(i,n) each(j,pd) chmax(res, rec(i,j,-1));
		return res;
	}
};