#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(ll (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto (itr):(v))
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
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
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

// 最終的に作る回分をtとし、s[i]がt[p[i]]になるとする
// 事前に各アルファベットの個数を求めておけばsの各文字がtの①左半分②ちょうど真ん中③右半分のどこに属するかは決められる
// とりあえずこの属する場所に順序関係を保ったまま移動させたものをxとすると、s->tのswap回数はs->xとx->tのswap回数の和になる
// ①内のある要素をswapするのとそれに対応する③内の要素をswapさせるのは同じことだから①内の要素はswapしないことにしても問題ない
// すると③内の要素の順番も定まるからあとはBITでバブルソートするだけ

int n;
ll ans;
vi c[26];
vpii p;
string s;

// [1,n]
int bit[200200];
int sum(int i) {
	i++;
	int s = 0;
	while (i>0) {
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x) {
	i++;
	while (i<=n) {
		bit[i] += x;
		i += i & -i;
	}
}

signed main() {
	cin >> s;
	n = s.length();
	rep(i,n) c[s[i]-'a'].pb(i);
	// 奇数回現れる文字種のカウントと同じ文字種の対応付け
	int odds = 0;
	rep(i,26) {
		int t = c[i].size();
		rep(j,t) {
			if (j*2>=t) break;
			if (j*2+1==t) {
				odds++;
				p.pb({c[i][j],c[i][j]});
			} else p.pb({c[i][t-1-j],c[i][j]});
		}
	}
	if (odds>=2) return cout << -1 << ln, 0;
	sort(all(p));
	each(i,p) {
		ans += sum(i.se-1) / (i.fi==i.se ? 2 : 1);
		add(i.fi,1);
		if (i.fi!=i.se) add(i.se,1);
	}
	cout << ans << ln;
}