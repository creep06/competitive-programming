#include <bits/stdc++.h>
using namespace std;

#define int long long
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
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln

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

int q, a, b, c, d, k, s, x, y, z;

void getCenter() {
	int l = 0, r = a + 1;
	while (r-l>1) {
		// 境目まででAをm個使うと仮定
		int m = (r+l)/2;
		// その時残るAとBの個数 m%k==0の場合はBはm/k-1個しか使わないことに注意
		int na = a - m;
		int nb = b - max(0ll, (m-1)/k);
		// 残ってるA,BでまだAAAAB...の続きを作れる場合
		if (nb <= (na+1)*k) l = m;
		else r = m;
	}
	// で求まったlが境目までのAの個数
	// つまりs = (l-1)/kとすると
	s = (l-1)/k;
	// 境目の左側は
	// [0, x = s*(k+1)) の範囲ではAAAABをs回繰り返す
	x = s*(k+1);
	// [x, y = l+s) の範囲では余ったAのみを繰り返す
	y = l+s;
	// でBはl = b-s個残るので、ABBBBはs = (l-1)/k個作れる それらが末尾に続く
	l = b-s;
	s = (l-1)/k;
	// [y, z) の範囲は余ったBのみを繰り返す
	z = a+b - s*(k+1);
}

signed main() {
	cin >> q;
	while (q--) {
		cin >> a >> b >> c >> d;
		c--, d--;
		// ABAB..とかBABA..って交互に置くだけの場合
		if (a==b || a==b+1) {
			repst(i,c,d) cout << (i%2==0 ? 'A' : 'B');
			cout << ln;
		}
		else if (b==a+1) {
			repst(i,c,d) cout << (i%2==0 ? 'B' : 'A');
			cout << ln;
		}
		else {
			// 同じ文字のみからなる部分文字列の最長の長さ
			k = (max(a,b) + min(a,b)) / (min(a,b) + 1);
			// f(A,B)は「'A'*k + 'B'」がいくつか繋がった前半と「'A' + 'B'*k」がいくつか繋がった後半に分けられる
			// 前半と後半の境目は二分探索で求める
			getCenter();
			repst(i,c,d) {
				if (i<x) cout << (i%(k+1)==k ? 'B' : 'A');
				else if (i<y) cout << 'A';
				else if (i<z) cout << 'B';
				else cout << ((i-z)%(k+1)==0 ? 'A' : 'B');
			}
			cout << ln;
		}
	}
}