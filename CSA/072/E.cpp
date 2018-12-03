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

int q, t, l, r, a, b, num;
map<pii,int> id;
priority_queue<pii> le, ri;
pii v[100100];
bool out[100100];

signed main() {
	cin >> q;
	while (q--) {
		cin >> t;
		if (t==1) {
			cin >> l >> r;
			num++;
			id[{l,r}] = num;
			v[num] = {l,r};
			le.push({l,num});
			ri.push({-r,num});
		} else if (t==2) {
			cin >> l >> r;
			out[id[{l,r}]] = true;
		} else {
			cin >> l >> r >> a >> b;
			if (r>b) swap(l,a), swap(r,b);
			if (l==a && r==b) {
				cout << 0 << ln;
				continue;
			}
			if (r<a) {
				cout << 1 << ln;
				continue;
			}
			while (out[le.top().se]) le.pop();
			pii p = v[le.top().se];
			while (out[ri.top().se]) ri.pop();
			pii q = v[ri.top().se];
			if (r<p.fi && b<p.fi) cout << 2 << ln;
			else if (q.se<l && q.se<a) cout << 2 << ln;
			else if (r<p.fi && q.se<p.fi && q.se<a) cout << 3 << ln;
			else if (q.se<l && q.se<p.fi && b<p.fi) cout << 3 << ln;
			else cout << -1 << ln;
		}
	}
}