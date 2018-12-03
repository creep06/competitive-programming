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



// 割合の制約よりi番目のジュースを1リットル増やすには[0,i)のジュースも全て1リットルずつ増やす必要がある
// こう考えると1リットルあたりの値段はs[i]/iになるから、まとめ買いするならこれが一番安いiで買いまくるのが得
// 他のiで帳尻合わせをする必要がある 他のiで買う量は最大でどれくらいになるか？
// -> 最大でもn^2程度になる
// ∵ 一番安いiをmとすると、m以外のi(=kとする)をm個買うよりmでk個買ったほうが得だから、m以外は全部でm未満しか買わなくていい
// ほんとはたかだかn個しか買わなくていいらしいけど証明がよくわからなかったからまた今度で・・

int n, v, c[101], s[101], mn, dp[101][10010], res = linf;

signed main() {
	cin >> n >> v;
	rep(i,n) {
		cin >> c[i];
		s[i] = c[i] + (i ? s[i-1] : 0);
	}
	v -= n;
	if (v<=0) return cout << s[n-1] << endl, 0;
	rep(i,n) if (s[i]*(mn+1)<s[mn]*(i+1)) mn = i;

	rep(i,101) rep(j,10010) dp[i][j] = linf;
	dp[0][0] = 0;
	rep(i,n) rep(j,10010) rep(k,101)
		if (j+k*(i+1)<=10000) chmin(dp[i+1][j+k*(i+1)], dp[i][j] + s[i]*k);
	rep(i,min(10001ll,v)) if ((v-i)%(mn+1)==0) chmin(res, (v-i)/(mn+1)*s[mn] + dp[n][i]);
	cout << res + s[n-1] << endl;
}
