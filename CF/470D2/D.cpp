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

// a[i] xor p[i]の順列が辞書順最小になるようにpの要素を入れ替える
// trie木にpを全部格納しておいて、a[i]の上のビットから見ていき、極力同じ数字の枝に進んでいく
// これで通ったパスが明らかにa[i]とのxorを最小にするp これを繰り返せばいい
// aもpも最大2^30だから深さD=30としてO(DN)

template<typename V> struct BTrie {
	private:
	static const int bit = 30, N = 300300, S = bit*N;
	public:
	V go[S][2],cnt[S],m;
	BTrie() {newNode();}
	V newNode() {go[m][0]=go[m][1]=-1; return m++;}
	void add(V x) {
		V v=0; cnt[v]++;
		for (V i = bit - 1; i >= 0; i--) {
			V y = (x>>i)&1;
			if (go[v][y]==-1) go[v][y]=newNode();
			v=go[v][y],cnt[v]++;
		}
	}
	void del(V x) {
		V v=0; cnt[v]--;
		for (V i = bit - 1; i >= 0; i--) {
			V y = (x >> i) & 1;
			if (go[v][y]==-1) go[v][y]=newNode();
			v=go[v][y],cnt[v]--;
		}
	}
};

BTrie<int> bt;
int n, tmp, a[300300];

int getBest(int x) {
	int v = 0;
	int ans = 0;
	for (int i = 29; i >= 0; i--) {
		int y = (x >> i) & 1;
		while(true) {
			int u = bt.go[v][y];
			// i番目のビットが同じものが存在しなければxorをとって仕方なくもう片方に進む
			if (u == -1 || bt.cnt[u] == 0) {
				y ^= 1;
				ans ^= 1 << i;
				continue;
			}
			v = u;
			break;
		}
	}
	return ans;
}

signed main() {
	cin >> n;
	rep(i,n) cin >> a[i];
	rep(i,n) {
		cin >> tmp;
		bt.add(tmp);
	}
	rep(i,n) {
		tmp = getBest(a[i]);
		bt.del(a[i]^tmp);
		cout << tmp << bln(i,n);
	}
}