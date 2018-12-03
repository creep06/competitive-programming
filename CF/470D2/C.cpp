#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto &(itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define bln(i,n) (i==n-1?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
typedef vector<bool> vb;
typedef vector<ld> vld;
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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

struct LazySegmentTree {
	private:
	int n;
	vector<ll> node, lazy;
	
	public:
	LazySegmentTree(vector<ll> v) {
		int sz = (int)v.size();
		n = 1; while(n < sz) n *= 2;
		node.resize(2*n-1);
		lazy.resize(2*n-1, 0);
		
		for(int i=0; i<sz; i++) node[i+n-1] = v[i];
		for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
	}
	
	void eval(int k, int l, int r) {
		if(lazy[k] != 0) {
			node[k] += lazy[k];
			if(r - l > 1) {
				lazy[2*k+1] += lazy[k] / 2;
				lazy[2*k+2] += lazy[k] / 2;
			}
			lazy[k] = 0;
		}
	}
	
	void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
		if(r < 0) r = n;
		eval(k, l, r);
		if(b <= l || r <= a) return;
		if(a <= l && r <= b) {
			lazy[k] += (r - l) * x;
			eval(k, l, r);
		}
		else {
			add(a, b, x, 2*k+1, l, (l+r)/2);
			add(a, b, x, 2*k+2, (l+r)/2, r);
			node[k] = node[2*k+1] + node[2*k+2];
		}
	}
	
	ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
		if(r < 0) r = n;
		eval(k, l, r);
		if(b <= l || r <= a) return 0;
		if(a <= l && r <= b) return node[k];
		ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
		ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
		return vl + vr;
	}
};

ll n, v[100100], t[100100], ts[100100];
ll imo[100100], sp[100100];

signed main() {
	cin >> n;
	rep(i,n) cin >> v[i];
	rep(i,n) cin >> t[i];
	ts[0] = t[0];
	reps(i,1,n) ts[i] = ts[i-1] + t[i];
	ts[n] = linf;
	rep(i,n) {
		int dis = lower_bound(ts,ts+n,v[i] + (i==0 ? 0 : ts[i-1])) - ts;
		// i日目から始まってdis日目に雪が完全に消える
		// [i,dis)は毎日規定量削れてdis日目だけケアしないといけない
		imo[i]++;
		// dis日目に綺麗に消せる場合
		if (ts[dis]==v[i] + (i==0 ? 0 : ts[i-1])) imo[dis+1]--;
		// dis日目に少しだけ消せる場合
		else {
			imo[dis]--;
			sp[dis] += v[i] + (i==0 ? 0 : ts[i-1]) - (dis==0 ? 0 : ts[dis-1]);
		}
	}
	reps(i,1,n) imo[i] += imo[i-1];
	//rep(i,n) cout << imo[i] << bln(i,n);
	//rep(i,n) cout << sp[i] << bln(i,n);
	rep(i,n) cout << imo[i]*t[i] + sp[i] << bln(i,n);
}