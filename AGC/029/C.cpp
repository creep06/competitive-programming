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



// 今ある文字列より大きい文字列のうち辞書順最小のものを求める というのをn回繰り返せたらok
// a[i-1]<a[i]なら末尾に0を詰める
// そうでないなら末尾a[i-1]-a[i]文字を消し、最後の文字を1だけ増やす(最後の文字が最大の場合は繰り上がり)
// 繰り上がりが出来なくなったらfalse

int n, a[200200], l, r = 200200;

// 数字[0,x)を使えるときに数列pを1だけ増やせるか判定、増やせるなら増やす
bool inc(vector<pair<int,int> > &p, int x) {
	int z = 0;
	while (1) {
		if (p.empty()) return 0;
		auto t = p.back();
		p.pop_back();
		if (t.first==x-1) {
			z += t.second;
			continue;
		}
		if (t.second>1) p.push_back({t.first, t.second-1});
		if (!p.empty() && p.back().first==t.first+1) p.back().second++;
		else p.push_back({t.first+1, 1});
		if (z) {
			if (!p.empty() && p.back().first==0) p.back().second += z;
			else p.push_back({0, z});
		}
		return 1;
	}
}

bool ok(int x) {
	int m = 0;
	vector<pair<int,int> > p;
	rep(i,n) {
		if (m<a[i]) {
			if (m && p.back().first==0) p.back().second += a[i]-m;
			else p.push_back({0, a[i]-m});
			m = a[i];
			continue;
		}
		while (1) {
			if (m==a[i]) break;
			auto t = p.back();
			p.pop_back(), m -= t.second;
			if (m<a[i]) {
				if (m && p.back().first==t.first) p.back().second += a[i]-m;
				else p.push_back({t.first, a[i]-m});
				m = a[i];
			}
		}
		if (!inc(p,x)) return 0;
	}
	return 1;
}

signed main() {
	cin >> n;
	rep(i,n) cin >> a[i];
	while (r-l>1) {
		int m = (l+r)/2;
		(ok(m) ? r : l) = m;
	}
	cout << r << endl;
}
