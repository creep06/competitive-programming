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
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
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
 * グリッドの中の縞模様になっている長方形部分の面積の最大値を求めよ
 *
 * (解法)
 * 愚直に全ての長方形部分を調べようとするとO(H^2 W^2) (もしかしたらこれで普通に間に合う？)
 * dpl[i][j]: マス(i,j)から左に伸びる縞模様の長さ(自分も含める)
 * dpu[i][j]: マス(i,j)から上に 〃
 * これを求めておくとO(HW(H+W))になる
 */

class TheMatrix {
	public:
	int MaxArea(vst s) {
		int h = s.size(), w = s[0].size(), dpu[100][100] = {}, dpl[100][100] = {}, res = 0;
		rep(i,h) rep(j,w) {
			dpu[i][j] = (i==0 || s[i][j]==s[i-1][j] ? 0 : dpu[i-1][j]) + 1;
			dpl[i][j] = (j==0 || s[i][j]==s[i][j-1] ? 0 : dpl[i][j-1]) + 1;
			int mw = dpl[i][j];
			rep(k,dpu[i][j]) chmin(mw, dpl[i-k][j]), chmax(res, (k+1)*mw);
			int mh = dpu[i][j];
			rep(k,dpl[i][j]) chmin(mh, dpu[i][j-k]), chmax(res, (k+1)*mh);
		}
		return res;
	}
};