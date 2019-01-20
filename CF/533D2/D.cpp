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
#define endl "\n"

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



// 45度回転累積和でいける？1ターン目は余裕だけどその後がきつそう
// 同じマップでプレイヤーごとにBFSすればいけんじゃね？
// 距離はa[i]で切り捨て除算した値が本物 除算前も保持しないといけない
// dとかcを更新するタイミングだけ除算した値を使ってqueには除算前を入れとく？
// 除算後距離、プレイヤー名、座標

int h, w, p, a[10], d[1010][1010], c[1010][1010], res[10];
string s[1010];
typedef pair<pair<int,int>,pair<int,int> > iiii;
priority_queue<iiii, vector<iiii>, greater<iiii>> q;
vector<pair<int,int> > st[10];

signed main() {
	cin >> h >> w >> p;
	rep(i,p) cin >> a[i];
	rep(i,h) {
		cin >> s[i];
		rep(j,w) if (isdigit(s[i][j])) st[s[i][j]-'1'].push_back({i,j});
	}
	rep(i,h) rep(j,w) d[i][j] = 1<<30, c[i][j] = -1;
	rep(i,p) each(j,st[i]) c[j.first][j.second] = i, d[j.first][j.second] = 0, q.push({{0,i},j});
	while (!q.empty()) {
		int x = q.top().second.first, y = q.top().second.second, col = q.top().first.second, fix = q.top().first.first; q.pop();
		if (c[x][y]!=col || d[x][y]/a[col]<fix) continue;
		rep(j,4) {
			int xx = x + dx[j], yy = y + dy[j], cost = d[x][y]+1;
			//if (ool(xx,yy,h,w) || s[xx][yy]!='.' || (c[xx][yy]!=-1 && ((c[xx][yy]==col && d[xx][yy]<=cost) || (c[xx][yy]!=col && d[xx][yy]/a[c[xx][yy]]<=cost/a[col])))) continue;
			if (ool(xx,yy,h,w) || s[xx][yy]!='.' || (c[xx][yy]==col && c[xx][yy]<=cost) || (c[xx][yy]!=-1 && c[xx][yy]!=col)) continue;
			//cout << xx << ' ' << yy << ' ' << col << ' ' << cost << endl;
			d[xx][yy] = cost, c[xx][yy] = col;
			q.push({{cost/a[col], col}, {xx, yy}});
		}
	}
	rep(i,h) rep(j,w) if (c[i][j]!=-1) res[c[i][j]]++;
	rep(i,p) cout << res[i] << bln(i,p);
}
