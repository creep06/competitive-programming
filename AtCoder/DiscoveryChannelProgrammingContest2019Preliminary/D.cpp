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



// 10^12以下ってことはa[2]は40未満、a[10]は100未満
// これらの条件を全て満たしたとして解は一個に定まるか？
// 1桁ずつ見ていく感じ？
// 30進法ならたかだか8桁
// 2進法で半分全列挙とかできない？
// 前半20桁を全部決めて28要素のvectorで二分探索
// 2^20 * 30 * 20 = 6*10^8 ギリ通らなくもなさそう？
// 桁数がめんどいから10^12だけ別にチェック
// 後は12桁以下で決め打ちして考える

const int M = 1000000;
vector<int> a(31);
vector<pair<vector<int>,int> > p;

// nのk進法での各桁の総和
int sum(int n, int k) {
	int res = 0;
	while (n) res += n%k, n /= k;
	return res;
}

signed main() {
	reps(i,2,31) cin >> a[i];

	// TODO 10^12をチェック

	// 上6桁 下に0を6つ付けないといけない
	rep(k,M) {
		vector<int> t = a;
		bool ng = 0;
		reps(i,2,31) {
			t[i] -= sum(k*M,i);
			if (t[i]<0) ng = 1;
		}
		if (ng) continue;
		p.push_back({t,k*M});
	}
	sort(all(p));

	// 下6桁
	rep(k,M) {
		vector<int> t(31,0ll);
		reps(i,2,31) t[i] = sum(k,i);
		pair<vector<int>,int> x = *lower_bound(all(p), mp(t,0ll));
		if (x.first==t) return cout << x.second + k << endl, 0;
	}
	cout << "invalid" << endl;
}
