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



// 最短周期が|s|であるような文字列s -> "良い文字列"
// 文字列sをいくつかに区切り、全ての小文字列が良い文字列なら、その区切り方は "良い表現"
// 区切りの個数の最小値mnと区切りの個数がmnであるような区切り方の個数を求めたい
//
// 長さが素数であるような文字列は全部良い文字列になる (これは使えない気がする)
// dp[i]: i文字目までを矛盾なく区切り終わったときの最小項数
// dp[i] = min(dp[j]+1 | j<i, s(j,i]が良い文字列)
// 部分点だけならこのまんま
// 項数が求められたら
// dp[i][j]: i文字目まででj回区切るような遷移の数
// で累積和でO(n^2) (たぶん)
// やっぱ準備計算にO(n^3)かかって無理？
// z-algorithmでうまくやればO(n^2)にはなりそう
//
// そもそもsが良い文字列なら答えは 1 1
// sの最小周期が1なら答えは n 1
// それ以外の場合は答えは2になりそう
// 少なくとも先頭1文字と残りに区切れば絶対良い表現になりそう
// 先頭1文字は絶対良い文字列で、残りは元々周期が2だとするとa-bababみたいになる

string s;
int n, res;
vector<int> x, y;

vector<int> zal(const string &s) {
	int n = s.size();
	vector<int> a(n);
	a[0] = n;
	int i = 1, j = 0;
	while (i<n) {
		while (i+j<n && s[j]==s[i+j]) ++j;
		a[i] = j;
		if (j==0) {++i; continue;}
		int k = 1;
		while (i+k<n && k+a[k]<j) a[i+k] =a[k], ++k;
		i += k, j -= k;
	}
	return a;
}

vector<int> pre() {
	vector<int> res(n+1,1), z = zal(s);
	reps(i,1,n) for (int j=2; (j-1)*i<=z[i]; j++) res[i*j] = 0;
	return res;
}

signed main() {
	cin >> s;
	n = s.size();
	if (count(all(s), s[0])==n) return cout << n << endl << 1 << endl, 0;
	x = pre();
	if (x[n]) return cout << 1 << endl << 1 << endl, 0;
	reverse(all(s));
	y = pre();
	reverse(all(y));
	reps(i,1,n) if (x[i] && y[i]) res++;
	cout << 2 << endl << res << endl;
}
