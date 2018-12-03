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

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// 行の入れ替えが決まっていれば、あとは上下反転して等しくなる列をペアにしていくことで条件を満たすか判定できる
// 行の入れ替え方は12!だけど例えば{AB}って並びで条件が成り立つかどうかは{BA}って並びでのそれと同じ
// つまりi行目とj行目の前後関係はどっちか1通りだけ考えればいいから入れ替え方は 11*9*7*5*3 = 10395 まで減る

int h, w;
string s[12];

void judge(vector<int> x, vector<int> y) {
	string t[12] = {};
	rep(i,x.size()) rep(j,w) t[j].push_back(s[x[i]][j]);
	rep(i,y.size()) rep(j,w) t[j].push_back(s[y[i]][j]);
	bool ok[12] = {};
	rep(i,w) if (!ok[i]) {
		string r = t[i];
		reverse(all(r));
		reps(j,i+1,w) if (!ok[j] && r==t[j]) {
			ok[i] = ok[j] = 1;
			break;
		}
	}
	int p = accumulate(ok,ok+w,0), fin = 0;
	if (p==w) fin = 1;
	if (p+1==w) rep(i,w) if (!ok[i]) {
		string r = t[i];
		reverse(all(r));
		if (r==t[i]) fin = 1;
	}
	if (fin) {
		cout << "YES";
		exit(0);
	}
}

void enu(int b, vi x, vi y) {
	int p = __builtin_popcount(b);
	if (p==h) {
		reverse(all(x));
		judge(x,y);
		return;
	}
	if (h%2 && p==0) {
		rep(i,h) {
			x.push_back(i);
			enu(b|(1<<i), x, y);
			x.pop_back();
		}
		return;
	}
	vector<int> t;
	rep(i,h) if (~b>>i&1) t.push_back(i);
	reps(i,1,h-p) {
		x.push_back(t[0]), y.push_back(t[i]);
		enu(b|(1<<t[0])|(1<<t[i]), x, y);
		x.pop_back(), y.pop_back();
	}
}

int main() {
	cin >> h >> w;
	rep(i,h) cin >> s[i];
	vector<int> X, Y;
	enu(0,X,Y);
	cout << "NO";
}