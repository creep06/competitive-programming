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

// BIT<型,k> bt; [1,2^k)
template<class T, int ME> class BIT {
	public:
	T bit[1<<ME],val[1<<ME];
	T total(int e) {T s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	T add(int e,T v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	T set(int e,T v) { add(e,v-val[e]);}
	int lb(T v) {
		T tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<v) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};

// 0, 010, 01010, 0101010, ...
// 0単体はいくらでも消して調整できる 1を優先して消して0が残ればそれでいい
// なるべく大きい区間を取ったほうが得 010より01010
// 貪欲にデカイやつを作っていくには？

int n;
string s;
BIT<ll,22> a, b;
vi ans[200200];
int cnt;
bool used[200200];

signed main() {
	cin >> s;
	n = s.size();
	rep(i,n) {
		if (s[i]=='0') a.add(i+1,1);
		else b.add(i+1,1);
	}
	repr(i,n-1) {
		if (s[i]=='0' && !used[i]) {
			ans[cnt].pb(i+1);
			used[i] = true;
			int ls = i;
			while (1) {
				// 一番近い1を探す
				int cn = b.total(ls+1);
				if (cn==0) break;
				int t1 = b.lb(cn);
				// その1から一番近い0を探す
				int cn2 = a.total(t1);
				if (cn2==0) break;
				int t2 = a.lb(cn2);
				// 0,1を使用済みにする
				used[t1-1] = used[t2-1] = true;
				ans[cnt].pb(t1), ans[cnt].pb(t2);
				ls = t2-1;
				a.add(t2,-1), b.add(t1,-1);
			}
			cnt++;
		}
	}
	
	if (b.total(n)) return cout << -1 << ln, 0;
	
	cout << cnt << ln;
	rep(i,cnt) {
		cout << ans[i].size() << ' ';
		repr(j,ans[i].size()-1) cout << ans[i][j] << bln(j,1);
	}
}