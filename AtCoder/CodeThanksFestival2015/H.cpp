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



// カロリーがk+xとなる長方形の内部(境界は含まない)にカロリーがxとなる長方形があればいいってこと
// 消す領域は1個のみだから1〜9しかない
// ケーキの外周以外の点を1個ずつ見ていって、
// それぞれの点(値はx)とその周囲8マスは絶対に含むような長方形のうちk+xとなるものを数えていければいい
// 横の広げ方を決めれば上下の広げ方は二分探索でできる？O(HW^2log(H))なら間に合う
// まともにやるとO(HW * W^2 * (H〜))はかかる
// 逆に3*3以上の長方形でカロリーがk+x, 1<=x<=9になるものを全部見ていってその内側に含まれるxのマスの個数を足していく方が良い？
// それならO(H^2Wlog(W))になりそう

int h, w, k, a[444][444], s[444][444], x[444][444][10], res;
string t;

int ar(int xa, int ya, int xb, int yb) {
	return s[xb][yb] - s[xa-1][yb] - s[xb][ya-1] + s[xa-1][ya-1];
}

int cn(int xa, int ya, int xb, int yb, int num) {
	return x[xb][yb][num] - x[xa-1][yb][num] - x[xb][ya-1][num] + x[xa-1][ya-1][num];
}

signed main() {
	cin >> h >> w >> k;
	rep(i,h) {
		cin >> t;
		rep(j,w) s[i+1][j+1] = a[i][j] = t[j]-'0', x[i+1][j+1][t[j]-'0']++;
	}
	reps(i,1,h+1) reps(j,1,w+1) s[i][j] += s[i][j-1];
	reps(i,1,h+1) reps(j,1,w+1) s[i][j] += s[i-1][j];
	reps(i,1,h+1) reps(j,1,w+1) rep(l,10) x[i][j][l] += x[i][j-1][l];
	reps(i,1,h+1) reps(j,1,w+1) rep(l,10) x[i][j][l] += x[i-1][j][l];
	reps(ia,1,h+1) reps(ib,ia+2,h+1) reps(ja,1,w-1) {
		// 和がk+1以上になる左端
		int l = ja+1, r = w;
		while (r-l>1) {
			int m = (l+r)/2;
			if (ar(ia,ja,ib,m)>=k+1) r = m;
			else l = m;
		}
		int jbl = r;
		// 和がk+9以下になる右端
		l = ja+2, r = w+1;
		while (r-l>1) {
			int m = (l+r)/2;
			if (ar(ia,ja,ib,m)<=k+9) l = m;
			else r = m;
		}
		int jbr = l;
		reps(jb,jbl,jbr+1) {
			int sum = ar(ia,ja,ib,jb);
			if (sum<k+1 || k+9<sum) continue;
			res += cn(ia+1,ja+1,ib-1,jb-1,sum-k);
		}
	}
	cout << res << endl;
}
