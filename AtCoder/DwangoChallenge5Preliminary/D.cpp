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



// 第一象限で完結するとは限らない ex3みたいなケースがある
// 二分探索でいけそう？
// (x±nd, y±md)の任意の点に行けそう 点を右にずらしまくったりして整理しながらやればいつかは可能そう
// 両方の非負の最小値のペアで点をグループ分けしていい感じにやれそう？
// グループ数はたかだか1000個
//
// d<=30で嬉しいこととして思いつくのは左下の点を全部試せること
// (0,0)から(29,29)まで全部試すことはできる
// そうすると二分探索までは無理 逆に最大値が一意に求められればいける

int n, d, x[100100], y[100100], cnt[2020][2020], res, hei[100100];
const int M = 1010;

bool ok(int m) {
	rep(i,2020) rep(j,2020) if (cnt[i][j]) {
		int h = (m-i)/d, w = (m-j)/d;
		if (h<0 || w<0) return 0;
		h++, w++;
		if (h*w<cnt[i][j]) return 0;
	}
	return 1;
}

signed main() {
	cin >> n >> d;
	rep(i,33333) hei[i] = i*i;
	int mnx = 1010, mny = 1010;
	rep(i,n) {
		cin >> x[i] >> y[i];
		x[i] -= x[i]/d*d, y[i] -= y[i]/d*d;
		if (abs(x[i]-d)<x[i]) x[i] -= d;
		if (abs(y[i]-d)<y[i]) y[i] -= d;
		chmin(mnx,x[i]), chmin(mny,y[i]);
	}
	rep(i,n) x[i] += -mnx, y[i] += -mny;
	while (1) {
		bool fin = 1;
		mnx = 1010, mny = 1010;
		rep(i,n) {
			if (abs(x[i]-d)<abs(x[i])) x[i] -= d, fin = 0;
			if (abs(y[i]-d)<abs(y[i])) y[i] -= d, fin = 0;
			chmin(mnx,x[i]), chmin(mny,y[i]);
		}
		rep(i,n) x[i] += -mnx, y[i] += -mny;
		if (fin) break;
	}
	rep(i,n) cnt[x[i]][y[i]]++;
	int l = 0, r = 1<<30;
	while (r-l>1) {
		int m = (l+r)/2;
		(ok(m) ? r : l) = m;
	}
	cout << r << endl;
}
