#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rept(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
#define repst(i,s,n) for(int (i)=(s);(i)<=(int)(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln "\n"
#define show(x) cout << #x << " = " << x ln
#define dbg(x) cout<<#x"="<<x ln

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > mat;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

int n, k, l, p, q, r, s;
pii pr[200000];

// ゴミみたいな実装
//----------------↓UnionFind↓----------------

int para[200000], ranka[200000];
int parb[200000], rankb[200000];

void init(int n) {
	for (int i=0; i<n; i++) {
		para[i] = parb[i] = i;
		ranka[i] = rankb[i] = 0;
	}
}

int finda(int x) {
	if (para[x]==x) return x;
	else return para[x] = finda(para[x]);
}

int findb(int x) {
	if (parb[x]==x) return x;
	else return parb[x] = findb(parb[x]);
}

void unitea(int x, int y) {
	x = finda(x);
	y = finda(y);
	if (x==y) return;
	
	if (ranka[x]<ranka[y]) para[x] = y;
	else {
		para[y] = x;
		if (ranka[x]==ranka[y]) ranka[x]++;
	}
}

void uniteb(int x, int y) {
	x = findb(x);
	y = findb(y);
	if (x==y) return;
	
	if (rankb[x]<rankb[y]) parb[x] = y;
	else {
		parb[y] = x;
		if (rankb[x]==rankb[y]) rankb[x]++;
	}
}

bool samea(int x, int y) {
	return finda(x) == finda(y);
}

bool sameb(int x, int y) {
	return findb(x) == findb(y);
}

//----------------↑UnionFind↑----------------

int main() {
	cin >> n >> k >> l;
	init(n);
	// 道路で繋ぐ
	rep(i,k) {
		cin >> p >> q;
		unitea(p-1, q-1);
	}
	// 鉄道で繋ぐ
	rep(i,l) {
		cin >> r >> s;
		uniteb(r-1, s-1);
	}
	
	// i番目の町の、"道路で繋がった根" と "鉄道で繋がった根" のペアを列挙しておく
	// i番目の町とj番目の町が道路でも鉄道でも繋がっている場合このペアは完全に一致するので、
	// "pr[i]と一致するpr[j]の個数" が "iと道路鉄道で繋がっている町の数" に等しい
	rep(i,n) pr[i] = mp(finda(i), findb(i));
	sort(pr, pr+n);
	rep(i,n) {
		// 二分探索で一致するペアの数を求める
		pii sa = mp(finda(i), findb(i));
		cout << upper_bound(pr, pr+n, sa) - lower_bound(pr, pr+n, sa) << (i==n-1 ? '\n' : ' ');
	}
}