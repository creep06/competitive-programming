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



// 明らかにいらない区間が存在し得るからそれは消してok
// → lは狭義単調増加、rは広義単調増加になる
// 区間[l,x+k]と[x,r]が並んでるとき、[l,x)は1個目の時点で確定し、[x,r]は[l,x+k]から自由に持ってこれる
// 左→右の移動はできても右→左の移動はできない
// ってことは区間[l,r]を見てる時点で[0,l)は確定してるはず
// dp[i][j]: [0,i)まで決めて[0,r[i]]に1がj個あるような文字列の決め方

int n, m, a, b, r[3030], c[3030], dp[3030][3030];
string s;

signed main() {
	cin >> n >> m >> s;
	rep(i,n) c[i+1] = s[i]-'0' + (i ? c[i] : 0);
	rep(i,3030) r[i] = i;
	rep(i,m) {
		cin >> a >> b;
		reps(j,a,b+1) chmax(r[j],b);
	}
	dp[0][0] = 1;
	reps(i,1,n+1) rep(j,min(c[r[i]],i)+1) {
		// [0,r[i]] 0-count
		if (r[i]-c[r[i]]<i-j) continue;
		// i文字目を0に
		dp[i][j] = dp[i-1][j];
		// i文字目を1に
		if (j) (dp[i][j] += dp[i-1][j-1]) %= mod;
	}
	cout << dp[n][c[n]] << endl;
}
