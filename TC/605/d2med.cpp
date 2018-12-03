#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(ll (i)=(n);(i)>=(t);--(i))
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

/*
 * (問題)
 * 各マスが白か黒で塗られたグリッドに対し、任意の行の白黒を反転させて作れる白マスの正方形の面積の最大値を求めよ
 *
 * (解法)
 * ある領域を白のみにできる <=> その領域の各行がBかWの片方のみ
 * 各マスの左にそのマスと同じ色のマスが(自分を含めて)何個続いているか を調べておけば、
 * 領域のタテの長さlを決め打ちするとO(n^3)で全探索できる
 * 下準備なしで正方形の領域自体を決め打ち->その領域を白のみにできるか調べるって方針だとO(n^5)弱だけど軽いからTLEしないと思う
 */

class AlienAndGame {
	public:
	int getNumber(vector<string> b) {
		int h = b.size(), w = b[0].size(), s[55][55] = {};
		rep(i,h) rep(j,w) s[i][j] = (j>0 && b[i][j]==b[i][j-1] ? s[i][j-1] : 0) + 1;
		int res = 1;
		rep(i,h) rep(j,w) {
			int mnw = s[i][j];
			reps(l,1,h-i) chmin(mnw,s[i+l][j]), chmax(res,min(mnw,l+1)*min(mnw,l+1));
		}
		return res;
	}
};