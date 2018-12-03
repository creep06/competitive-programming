#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(ll (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,n+1)
#define repst(i,s,n) reps(i,s,n+1)
#define reprt(i,n,t) for(ll (i)=(n);(i)>=t;--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb emplace_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) for(int (i)=0;i<n;++i){cout<<x[i]<<(i==n-1?'\n':' ');}

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

const int inf = (ll)1e9+10;
const ll linf = (ll)1e18+10;
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

/*
 * ABCAC AとCの長さを決めればABCそれぞれに対応する文字列が決まる
 * ABC-ACの切れ目を全探索し、ABCが[0,i-1]、ACが[i,|s|-1]に対応するとして、前者の文字列をx、後者をyとする
 * xとyのprefixがa文字、suffixがc文字だけかぶっているとき、a>0 && c>0 && a+c>=|y|が成り立っていれば、
 * a+c-|y|+1通りの分け方があることになる
 * 例えば|y|=5, a=4, c=3のとき aaccc, aaacc, aaaacみたいに分けられる
 * aaaacccからa,c両方とも最低1文字は含むように連続する|y|文字を切り取る感じ？
 */

string s;
int n;
ll r;
vi z, zr;

// 文字列SとS[i,|S|-1]の最長共通接頭辞の長さの配列をO(|S|)で構築
vi zaru(const string &s) {
	int n = s.size();
	vi a(n);
	a[0] = n;
	int i = 1, j = 0;
	while (i<n) {
		while (i+j<n && s[j]==s[i+j]) ++j;
		a[i] = j;
		if (j==0) {++i; continue;}
		int k = 1;
		while (i+k<n && k+a[k]<j) a[i+k] =a[k], ++k;
		i += k, j -= k;
	}
	return a;
}

signed main() {
	cin >> s;
	z = zaru(s);
	reverse(all(s));
	zr = zaru(s);
	reverse(all(zr));
	n = s.length();
	
	reps(i,n/2+1,n-1) {
		int a = min(n-i-1,z[i]), c = min(n-i-1,zr[i-1]);
		if (a>=1 && c>=1 && a+c>=n-i) r += a+c-(n-i)+1;
	}
	cout << r << ln;
}