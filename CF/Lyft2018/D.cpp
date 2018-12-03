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



// 木は自分の木の適当な1頂点を根とした根付き木として問題ない
// 相手の木の点vを1個適当に聞く
// vの親を辿り続けて最初に到着した自分の木の頂点をuとすると、u以外の部分木は今後どうでもよくなる
// uについて調べれば終わり？
// vから自分の木との距離をdとする
// dがk2より大きかったら答えが-1なのが確定
//

int Q, n, a, b, k1, x1[1010], k2, x2[1010], d[1010], v, u, z;
vector<int> e[1010];
set<int> my, his;

void rec(int x, int p) {
	if (u!=-1) return;
	if (my.count(x)) {
		u = x;
		return;
	}
	each(i,e[x]) if (i!=p) {
		d[i] = d[x]+1;
		rec(i,x);
	}
}

signed main() {
	cin >> Q;
	while (Q--) {
		cin >> n;
		rep(i,n) e[i].clear();
		rep(i,n-1) {
			cin >> a >> b;
			a--, b--;
			e[a].push_back(b), e[b].push_back(a);
		}
		cin >> k1;
		my.clear();
		rep(i,k1) {
			cin >> x1[i];
			x1[i]--;
			my.insert(x1[i]);
		}
		cin >> k2;
		his.clear();
		rep(i,k2) {
			cin >> x2[i];
			x2[i]--;
			his.insert(x2[i]);
		}
		cout << "B " << x2[0]+1 << endl << flush;
		cin >> v;
		v--;
		rep(i,n) d[i] = 1<<30;
		d[v] = 0;
		u = -1;
		rec(v,-1);
		cout << "A " << u+1 << endl << flush;
		cin >> z;
		z--;
		if (his.count(z)) cout << "C " << u+1 << endl << flush;
		else cout << "C " << -1 << endl << flush;
	}
}
