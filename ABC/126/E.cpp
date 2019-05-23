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
#define each(i,v) for(auto &(i):(v))
#define all(c) (c).begin(),(c).end()
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define bln(i,n) (((i)==(n)-1)?'\n':' ')
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())

//typedef complex<double> P;
typedef long long ll;

const ll inf = (ll)1e9+10;
const ll linf = (ll)1e18+10;
const ll mod = (ll)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
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



int n, m, x, y, z, res;
vector<int> e[100100];
bool ok[100100];

void rec(int v, int p) {
    ok[v] = 1;
    each(i,e[v]) if (i!=p && !ok[i]) rec(i,v);
}

signed main() {
    cin >> n >> m;
    rep(i,m) {
        cin >> x >> y >> z;
        x--, y--;
        e[x].push_back(y), e[y].push_back(x);
    }
    rep(i,n) if (!ok[i]) res++, rec(i,-1);
    cout << res << endl;
}
