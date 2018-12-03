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

#define int long long
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



int n, a[100100], b[100100], res, lst = -1;
deque<int> q;

signed main() {
	cin >> n;
	rep(i,n) cin >> a[i];
	sort(a,a+n);
	if (n%2==0) {
		lst = a[n/2];
		a[n/2] = linf;
		sort(a,a+n);
		n--;
	}
	reverse(a,a+n);
	q.push_back(a[0]);
	int l = 1, r = n-1;
	rep(i,n/2) {
		if (i%2==0) {
			q.push_front(a[r--]);
			q.push_back(a[r--]);
		} else {
			q.push_front(a[l++]);
			q.push_back(a[l++]);
		}
	}
	if (lst!=-1) {
		int x = abs(q.front()-lst), y = abs(q.back()-lst);
		if (x<y) q.push_back(lst);
		else q.push_front(lst);
		n++;
	}
	int sum = 0;
	while (q.size()>=2) {
		int t = q.back(); q.pop_back();
		sum += abs(q.back()-t);
	}
	res = sum;
	while (!q.empty()) q.pop_back();


	sum = 0;
	sort(a,a+n);
	if (n%2==0) {
		n--;
	}
	q.push_back(a[0]);
	l = 1, r = n-1;
	rep(i,n/2) {
		if (i%2==0) {
			q.push_front(a[r--]);
			q.push_back(a[r--]);
		} else {
			q.push_front(a[l++]);
			q.push_back(a[l++]);
		}
	}
	if (lst!=-1) {
		int x = abs(q.front()-lst), y = abs(q.back()-lst);
		if (x<y) q.push_back(lst);
		else q.push_front(lst);
		n++;
	}
	while (q.size()>=2) {
		int t = q.back(); q.pop_back();
		sum += abs(q.back()-t);
	}
	res = max(res, sum);

	cout << res << endl;
}
