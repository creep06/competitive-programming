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



// 貪欲に決めればいい
// 頂点iを採用していいかどうかの判定が問題になる
// 今x個目の頂点をiにしようとしていて、そうすると残りkk回しか操作が出来ないとする
// 残りm-x枚のコインをn-x個の頂点のどれかにkk回の操作でコインを置ければok
// 操作1は必ずやるから残りkk-m+x回
// 既に使った頂点を根とする部分木は根ごと全て消して、その上で残った頂点だけにコインを置ける
// これらの頂点を浅いものを優先して使っていきたい
// 使える頂点の深さを全部vectorにでも入れて昇順に↑個取ればいい
// 一回確定した頂点を更に下げることはないからこれで良い
// 計算量はギリ大丈夫
//
// ちょうどkってのを見落としてた
// k以上にできれば減らすことはいくらでもできる
// と思ったけどk以下もk以上も作れないといけない
// 昇順にm-?個とった値 <= kk <= 降順にm-?個とった値 が成り立てばok
// 間は自由に調整できる

int n, m, k, p[333], r, us[333], d[333], mx, mn;
vector<int> e[333], res, dep;

void rec(int v, int p, int dis) {
	d[v] = dis;
	each(i,e[v]) if (i!=p) rec(i,v,dis+1);
}

void rec2(int v, int p, int dis) {
	if (us[v]) return;
	dep.push_back(dis);
	each(i,e[v]) if (i!=p) rec2(i,v,dis+1);
}

void rec3(int v, int p) {
	us[v] = 1;
	each(i,e[v]) if (i!=p) rec3(i,v);
}

signed main() {
	cin >> n >> m >> k;
	// 操作1のコストを0にする
	k -= m;
	rep(i,n) {
		cin >> p[i];
		p[i]--;
		if (p[i]==-1) r = i;
		else e[i].push_back(p[i]), e[p[i]].push_back(i);
	}
	rec(r,-1,0);
	rep(x,m) rep(i,n) if (!us[i]) {
		int num = m-x-1;
		int kk = k - d[i];
		if (kk<0) goto fin;
		dep.clear();
		us[i] = 1;
		rec2(r,-1,0);
		if (dep.size()<num) goto fin;
		mx = 0, mn = 0;
		sort(dep.rbegin(), dep.rend());
		rep(j,num) mx += dep[j];
		sort(all(dep));
		rep(j,num) mn += dep[j];
		// OK
		if (mn<=kk && kk<=mx) {
			res.push_back(i);
			// i以下の頂点を全て使用済みにする
			rec3(i,p[i]);
			//cout << i << ' ';
			k = kk;
			break;
		}
		// ダメだった場合
		fin:;
		us[i] = 0;
		if (i==n-1) return cout << -1 << endl, 0;
	}
	rep(i,m) cout << res[i]+1 << bln(i,m);
}
