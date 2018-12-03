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



// 0は2個以上合っても1個にまとめられる 消そうと思えば全部消せる
// 0がある場合はそれを消す場合と消さない場合のデカイ方
// いや↓と同様の場合分けが必要
// ない場合は負の数の偶奇で場合分け
// 負が奇数個なら一番大きい負を消せばいい
// 偶数個なら何もしない
int n, a[200200], z, zs[200200], m;
pair<int,int> p[200200];
vector<int> zi, ki;

signed main() {
	cin >> n;
	rep(i,n) {
		cin >> a[i];
		p[i] = {a[i], i};
		if (a[i]==0) z++, zs[i] = 1, zi.push_back(i);
		if (a[i]<0) m++;
	}
	rep(i,n) if (!zs[i]) ki.push_back(i);
	sort(p,p+n);
	if (m%2==0) {
		if (z==0) {
			rep(i,n-1) cout << "1 " << i+1 << ' ' << i+2 << endl;
			return 0;
		} else {
			rep(i,(int)zi.size()-1) cout << "1 " << zi[i]+1 << ' ' << zi[i+1]+1 << endl;
			if (zi.size()==n) return 0;
			cout << "2 " << zi[zi.size()-1]+1 << endl;
			rep(i,(int)ki.size()-1) cout << "1 " << ki[i]+1 << ' ' << ki[i+1]+1 << endl;
		}
	} else {
		int mx = -inf, mxi = -1;
		rep(i,n) if (a[i]<0 && mx<a[i]) mx = a[i], mxi = i;
		if (mxi!=-1) zi.push_back(mxi), sort(all(zi));
		rep(i,(int)zi.size()-1) cout << "1 " << zi[i]+1 << ' ' << zi[i+1]+1 << endl;
		if (zi.size()==n) return 0;
		cout << "2 " << zi[zi.size()-1]+1 << endl;
		vector<int> kii;
		rep(i,n) if (i!=mxi && zs[i]==0) kii.push_back(i);
		rep(i,(int)kii.size()-1) cout << "1 " << kii[i]+1 << ' ' << kii[i+1]+1 << endl;
	}
}
