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

// ex4みたいにどこにもつながってないスイッチがあるケースもあるらしい

int n, m, q;
string s, b;
vector<pair<string,string> > p;

signed main() {
	while (1) {
		cin >> n >> m >> q;
		if (n==0) break;
		p.clear();
		p.pb({string(n,'0'), string(m,'0')});
		p.pb({string(n,'1'), string(m,'1')});
		string ss = string(n,'0');
		rep(i,q) {
			cin >> s >> b;
			rep(j,n) ss[j] = (ss[j]==s[j] ? '0' : '1');
			p.pb({ss,b});
		}
		q += 2;
		
		map<string,string> ma;
		rep(i,q) ma[p[i].fi] = p[i].se;
		rep(i,q) reps(j,i+1,q) {
			string x;
			rep(k,n) x.pb(p[i].fi[k]==p[j].fi[k] ? '0' : '1');
			string t;
			rep(k,m) t.pb(p[i].se[k]==p[j].se[k] ? '0' : '1');
			ma[x] = t;
		}
		
		int res[1000];
		bool f[44] = {};
		memset(res,-1,sizeof(res));
		rep(i,n) each(j,ma) if (j.fi[i]=='1' && !j.se.empty()) {
			string x = j.fi;
			x[i] = '0';
			string y = ma[x];
			if (y.size()!=m) continue;
			rep(k,m) if (j.se[k]!=y[k]) res[k] = i;
			f[i] = 1;
			break;
		}
		
		// わからないのが1個だけなら確定できる ex5
		if (accumulate(f,f+44,0)==n-1) {
			int id;
			rep(i,n) if (!f[i]) id = i;
			rep(i,m) if (res[i]==-1) res[i] = id;
		}
		
		rep(i,m) {
			if (res[i]==-1) cout << '?';
			else if (res[i]<=9) cout << res[i];
			else cout << (char)('A' + (res[i]-10));
			if (i==m-1) cout << ln;
		}
	}
}