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



// 3つとも数字のやつは全部繋げるべき
// それ以外はtに突っ込んでおき、そこから2個選んで両端に繋げるのを全部試せばok
// tのサイズが1の場合もケアしたい 適当に番兵入れれば大丈夫そう
// 単体で最大になってるパターンもケアしたい

class DengklekMakingChains {
public:
	int maxBeauty(vector<string> s) {
		vector<string> t;
		int res = 0, cen = 0;
		each(i,s) {
			if (isdigit(i[0]) && isdigit(i[1]) && isdigit(i[2])) cen += i[0]-'0' + i[1]-'0' + i[2]-'0';
			else {
				t.push_back(i);
				if (isdigit(i[1])) {
					if (isdigit(i[0])) chmax(res, i[1]-'0' + i[0]-'0');
					else if (isdigit(i[2])) chmax(res, i[1]-'0' + i[2]-'0');
					else chmax(res, i[1]-'0');
				} else {
					if (isdigit(i[0])) chmax(res, i[0]-'0');
					else if (isdigit(i[2])) chmax(res, i[2]-'0');
				}
			}
		}
		chmax(res, cen);
		t.push_back("...");
		int m = t.size();
		rep(l,m) rep(r,m) if (l!=r) {
			int sum = cen;
			if (isdigit(t[l][2])) {
				sum += t[l][2]-'0';
				if (isdigit(t[l][1])) sum += t[l][1]-'0';
			}
			if (isdigit(t[r][0])) {
				sum += t[r][0]-'0';
				if (isdigit(t[r][1])) sum += t[r][1]-'0';
			}
			chmax(res, sum);
		}
		return res;
	}
};
