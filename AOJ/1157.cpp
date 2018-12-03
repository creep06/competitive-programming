#include <bits/stdc++.h>
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
const double eps = 1e-8;

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

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

int n, xl[50], yl[50], xr[50], yr[50], h[50];
double d[50];
P s, g;

vector<double> res;

bool ok(double r) {
	rep(i,n) {
		if (r<=h[i] && d[i]<r) return false;
		else if (h[i]<r) {
			double t = sqrt(d[i]*d[i] + (r-h[i])*(r-h[i]));
			if (t<r) return false;
		}
	}
	return true;
}

signed main() {
	while (1) {
		cin >> n;
		if (n==0) break;
		double sx, sy, gx, gy;
		cin >> sx >> sy >> gx >> gy;
		s = P(sx,sy), g = P(gx,gy);
		rep(i,n) {
			cin >> xl[i] >> yl[i] >> xr[i] >> yr[i] >> h[i];
			P p1 = P(xl[i],yl[i]), p2 = P(xr[i],yl[i]), p3 = P(xr[i],yr[i]), p4 = P(xl[i],yr[i]);
			double a = min(dislss(p1,p2,s,g), dislss(p2,p3,s,g)), b = min(dislss(p3,p4,s,g), dislss(p4,p1,s,g));
			d[i] = min(a,b);
			// コースを内包するブロックを検出
			if (intls(p1,p3,s,g) || intls(p2,p4,s,g)) d[i] = 0;
		}
		double l = 0, r = 1001;
		rep(i,100) {
			double m = (l+r)/2;
			if (ok(m)) l = m;
			else r = m;
		}
		printf("%.14lf\n",l);
	}
}