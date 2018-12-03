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



// 各列のアヒルをi行目に全て集める
// → それらを連結する(中央値に集めるのが最善)
// このコストで答え更新 それぞれの列と行についてやる

class DucksAlignment {
public:
	int minimumTime(vector<string> s) {
		int h = s.size(), w = s[0].size(), res = inf;
		int ph[50], pw[50];
		memset(ph,-1,sizeof(ph)), memset(pw,-1,sizeof(pw));
		rep(i,h) rep(j,w) if (s[i][j]=='o') ph[i] = j, pw[j] = i;
		rep(i,h) {
			vector<int> p;
			int t = 0;
			rep(j,w) if (pw[j]!=-1) t += abs(pw[j]-i), p.push_back(j);
			sort(all(p));
			int k = p.size();
			reps(j,k/2+1,k) t += p[j]-p[j-1]-1, p[j] = p[j-1]+1;
			for(int j=k/2-1; j>=0; j--) t += p[j+1]-p[j]-1, p[j] = p[j+1]-1;
			chmin(res, t);
		}
		rep(i,w) {
			vector<int> p;
			int t = 0;
			rep(j,h) if (ph[j]!=-1) t += abs(ph[j]-i), p.push_back(j);
			sort(all(p));
			int k = p.size();
			reps(j,k/2+1,k) t += p[j]-p[j-1]-1, p[j] = p[j-1]+1;
			for(int j=k/2-1; j>=0; j--) t += p[j+1]-p[j]-1, p[j] = p[j+1]-1;
			chmin(res, t);
		}
		return res;
	}
};
