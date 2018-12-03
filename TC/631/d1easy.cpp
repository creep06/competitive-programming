#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
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
#define log2(x) log(x)/log(2)
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

/*
 * (問題)
 * N*Nサイズで白/黒のみで塗られたグリッドに対し「i行目を白か黒で塗りつぶす」という操作を何度か行い、
 * 各列の同じ色が連続で並んでいるマスの数の最大値をN/2以下にしたい 必要な操作の最小回数を求めよ
 *
 * (解法)
 * どんなグリッドでも真ん中の2行を異なる色で塗りつぶせば必ず題意を満たすことから、答えは最大でも2
 * あとは0回or1回塗りつぶすだけで条件を満たせるかだけ調べればいい
 */

class TaroJiroGrid {
	public:
	bool ok(vst s) {
		int n = s.size(), mx = 1;
		rep(j,n) {
			int cnt = 1;
			reps(i,1,n) {
				if (s[i][j]==s[i-1][j]) chmax(mx, ++cnt);
				else cnt = 1;
			}
		}
		return mx<=n/2;
	}
	
	int getNumber(vst s) {
		int n = s.size();
		if (ok(s)) return 0;
		rep(i,n) {
			string t = s[i];
			rep(j,n) s[i][j] = 'B';
			if (ok(s)) return 1;
			rep(j,n) s[i][j] = 'W';
			if (ok(s)) return 1;
			s[i] = t;
		}
		return 2;
	}
};