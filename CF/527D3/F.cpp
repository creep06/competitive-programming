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



// 1頂点で普通に求めて、その結果と累積和で全部試せば解ける
// けど実装がめんどい
// 1) root(v=0)からdfsしてO(N)で計算
// 2) 各頂点を根とする部分木のp[i]の和を全部dfs2で計算しておく
// 3) 距離が増える頂点のsumと減る頂点のsumを使っていい感じに・・

int n, p[200200], a, b, d[200200], s[200200], as, res;
vector<int> e[200200];

void rec(int v, int p, int dis) {
	d[v] = dis;
	each(i,e[v]) if (i!=p) rec(i, v, dis+1);
}

// s[v]はp[v]を含まない
int rec2(int v, int pa) {
	int sum = 0;
	each(i,e[v]) if (i!=pa) sum += rec2(i,v);
	s[v] = sum;
	return sum + p[v];
}

void rec3(int v, int pa, int sum, int inc, int dec) {
	cout << v << ' ' << sum << endl;
	chmax(res, sum);
	// 距離が増える頂点たちのpのsum
	int tinc = p[v];
	each(i,e[v]) if (i!=pa) tinc += s[i] + p[i];
	each(i,e[v]) if (i!=pa) {
		int INC = inc, DEC = dec;
		INC += tinc - (s[i] + p[i]);
		DEC = s[i] + p[i];
		rec3(i, v, sum + INC - DEC, INC, DEC);
	}
}

signed main() {
	cin >> n;
	rep(i,n) cin >> p[i];
	as = accumulate(p, p+n, 0ll);
	rep(i,n-1) {
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b), e[b].push_back(a);
	}
	rec(0, -1, 0), rec2(0, -1);
	rep(i,n) res += d[i] * p[i];
	rec3(0, -1, res, 0, 0);
	cout << res << endl;
}
