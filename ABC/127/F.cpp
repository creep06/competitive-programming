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



template<class T, int ME> class BIT {
    public:
    T bit[1<<ME],val[1<<ME];
    T sum(int e) {T s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
    T add(int e,T v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
    T set(int e,T v) { add(e,v-val[e]);}
    int lb(T v) {
        T tv=0; int i,ent=0;
        for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<v) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
        return ent;
    }
};

int Q, t[200200], a[200200], b[200200], id = 1;
set<int> s;
map<int,int> con, rev;
BIT<int,20> bt, sm;

signed main() {
    cin >> Q;
    rep(i,Q) {
        cin >> t[i];
        if (t[i]==1) {
            cin >> a[i] >> b[i];
            s.insert(a[i]);
        }
    }
    each(i,s) con[i] = id, rev[id++] = i;
    int bs = 0, num = 0;
    rep(i,Q) {
        if (t[i]==1) {
            bt.add(con[a[i]], 1);
            sm.add(con[a[i]], a[i]);
            num++, bs += b[i];
        } else {
            int l = 0, r = 200200;
            int p = (num+1)/2;
            while (r-l>1) {
                int m = (l+r)/2;
                if (bt.sum(m)>=p) r = m;
                else l = m;
            }
            int sml = bt.sum(r)*rev[r] - sm.sum(r);
            int smr = sm.sum(200200)-sm.sum(r) - (num-bt.sum(r))*rev[r];
            cout << rev[r] << ' ' << sml+smr + bs << endl;
        }
    }
}
