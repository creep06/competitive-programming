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

typedef complex<double> P;
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

// ベクトル演算
// 内積 外積 直交 平行
double dot(P a, P b) {return (a.real()*b.real()+a.imag()*b.imag());}
double cross(P a, P b) {return (a.real()*b.imag()-a.imag()*b.real());}
bool orth(P a1, P a2, P b1, P b2) {return deq(dot(a1-a2,b1-b2),0.0);}
bool para(P a1, P a2, P b1, P b2) {return deq(cross(a1-a2,b1-b2),0.0);}
// 点cが直線[線分]ab上にあるかどうか
bool pol(P a, P b, P c) {return deq(cross(b-a,c-a),0.0);}
bool pols(P a, P b, P c) {return (abs(a-c)+abs(c-b)<abs(a-b)+eps);}
// 線分a1a2と線分b1b2の交差判定
bool intls(P a1, P a2, P b1, P b2) {
	return (cross(a2-a1,b1-a1)*cross(a2-a1,b2-a1)<eps)
		   && (cross(b2-b1,a1-b1)*cross(b2-b1,a2-b1)<eps);
}
// 直線[線分]a1a2と直線[線分]b1b2の交点 (要交差判定)
P pintl(P a1, P a2, P b1, P b2) {
	P a = a2-a1, b = b2-b1;
	return a1+a*cross(b,b1-a1)/cross(b,a);
}
P pintls(P a1, P a2, P b1, P b2) {
	P b = b2-b1;
	double d1 = abs(cross(b,a1-b1)), d2 = abs(cross(b,a2-b1)), t = d1/(d1+d2);
	return a1+(a2-a1)*t;
}
// 点cと直線[線分]abとの距離
double disl(P a, P b, P c) {return abs(cross(b-a,c-a))/abs(b-a);}
double disls(P a, P b, P c) {
	if (dot(b-a,c-a)<eps) return abs(c-a);
	if (dot(a-b,c-b)<eps) return abs(c-b);
	return abs(cross(b-a,c-a))/abs(b-a);
}
// 線分a1a2と線分b1b2の距離
double dislss(P a1, P a2, P b1, P b2) {
	if (!para(a1,a2,b1,b2) && intls(a1,a2,b1,b2)) return 0;
	double a = min(disls(a1,a2,b1),disls(a1,a2,b2)), b = min(disls(b1,b2,a1),disls(b1,b2,a2));
	return min(a,b);
}



int n, res;
P a[1010], b[1010];
set<pair<int,int> > us;

signed main() {
	cin >> n;
	rep(i,n) {
		int ax, ay, bx, by;
		cin >> ax >> ay >> bx >> by;
		res += gcd(abs(ax-bx), abs(ay-by)) + 1;
		a[i] = P(ax,ay), b[i] = P(bx,by);
	}
	rep(i,n) {
		vector<pair<int,int>> lst;
		reps(j,i+1,n) {
			if (!intls(a[i],b[i],a[j],b[j])) continue;
			P p = pintls(a[i],b[i],a[j],b[j]);
			if (deq(p.real(), round(p.real())) && deq(p.imag(), round(p.imag()))) {
				pair<int,int> t = {(int)round(p.real()), (int)round(p.imag())};
				if (us.count(t)) continue;
				res--;
				lst.push_back(t);
			}
		}
		each(i,lst) us.insert(i);
	}
	cout << res << ln;
}
