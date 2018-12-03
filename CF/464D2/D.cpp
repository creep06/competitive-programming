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

int n;
string s, t;

// ex1みたいに2つのスペルで3つのペアを解消できる 例えばa-b,b-cならa-cもいける ただの貪欲ではない
// n個の辺があるグラフの最小全域木でいけそう？
// 最小全域木ではなかった ただのunionfind?

//----------------↓UnionFind↓----------------

int par[26], rnk[26];

void init(int n) {
	for (int i=0; i<n; i++) {
		par[i] = i;
		rnk[i] = 0;
	}
}

int find(int x) {
	if (par[x]==x) return x;
	else return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x==y) return;
	
	if (rnk[x]<rnk[y]) par[x] = y;
	else {
		par[y] = x;
		if (rnk[x]==rnk[y]) rnk[x]++;
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

//----------------↑UnionFind↑----------------

vector<pair<char,char>> r;

signed main() {
	cin >> n >> s >> t;
	init(26);
	rep(i,n) {
		if (s[i]==t[i] || same(s[i]-'a',t[i]-'a')) continue;
		unite(s[i]-'a',t[i]-'a');
		r.pb({s[i],t[i]});
	}
	cout << r.size() << ln;
	each(i,r) cout << i.fi << ' ' << i.se << ln;
}