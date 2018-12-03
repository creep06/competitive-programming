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



// 最初に通るk個までのa以外の文字は全部同じ
// 最初はなるべくaを拾うように動くべき
// a以外のマスに進むにはコスト1、aのマスにはコスト0かかる
// コストの初期値は左上のマスがaなら0でそうじゃなければ1
// コストkで進める最もゴールに近いマスたちがスタート地点の候補
// これらのスタート地点から始めてゴールまでで出来る文字列のうち最小のものを求めたい
// kが0で文字が全部'b'みたいなケースを考えるとO(n^3)になるから全部保持しながら進んでいくのは無理

int h, w, k, a[2020][2020], d[2020][2020], mx;
string s[2020], res;
vector<pair<int,int> > ss;
char cc[4040];

signed main() {
	cin >> h >> k;
	w = h;
	rep(i,h) {
		cin >> s[i];
		rep(j,w) if (s[i][j]=='a') a[i][j] = 1;
	}
	rep(i,2020) rep(j,2020) d[i][j] = 1<<30;
	d[0][0] = (s[0][0]!='a');
	queue<pair<int,int> > q;
	q.push({0,0});
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		rep(i,2) {
			int xx = x + dx[i], yy = y + dy[i];
			if (ool(xx,yy,h,w)) continue;
			int cost = d[x][y] + (s[xx][yy]!='a');
			if (d[xx][yy]>cost) d[xx][yy] = cost, q.push({xx,yy});
		}
	}
	if (d[h-1][w-1]<=k) {
		rep(i,h*2-1) cout << 'a';
		cout << endl;
		return 0;
	}
	rep(i,h) rep(j,w) if (d[i][j]==k) {
		int l = i+j+1;
		if (mx<l) {
			mx = l;
			ss.clear();
		}
		if (mx==l) {
			ss.push_back({i,j});
		}
	}
	if (mx==0) {
		ss.push_back({0,0});
		res.push_back(s[0][0]);
	}
	int no = h*2 - max(mx,1) - 1;
	rep(i,mx) res.push_back('a');
	rep(i,4040) cc[i] = 'z'+1;
	rep(i,2020) rep(j,2020) d[i][j] = 1<<30;
	each(i,ss) q.push({i.first, i.second}), d[i.first][i.second] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		if (cc[d[x][y]]<s[x][y]) continue;
		rep(i,2) {
			int xx = x + dx[i], yy = y + dy[i];
			if (ool(xx,yy,h,w)) continue;
			int dis = d[x][y]+1;
			char c = s[xx][yy];
			if (cc[dis]>c || (cc[dis]==c && d[xx][yy]>dis)) cc[dis] = c, d[xx][yy] = dis, q.push({xx,yy});
		}
	}
	reps(i,1,no+1) res.push_back(cc[i]);
	cout << res << endl;
}
