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
 * N個のビルがあり、あるビルの高さを1増やすにはコストが1かかる
 * 1<=M<=Nを満たす全てのMについて「同じ高さのビルがM個以上ある状態にするのに必要なコストの最小値」を求め、それらのxor和を求めよ
 *
 * (解法)
 * ビルの高さhを昇順ソートする
 * (r-M,r]の範囲のM個のビルを同じ高さにするためにかかる最小コストは、これら全てのビルをh[r]に揃えればいいから
 * h[r]-h[r-M+1] + h[r]-h[r-M+2] + ... + h[r]-h[r-1] + h[r]-h[r]
 * == h[r]*M - (h[r-M+1]+h[r-M+2]+...+h[r-1]+h[r])
 * かっこ内を毎回求めてるとO(N^3) 累積和を求めておけばO(N^2)
 */

class BuildingHeights {
	public:
	int minimum(vi h) {
		int n = h.size(), imo[4040] = {};
		h.pb(-1);
		sort(all(h));
		repst(i,1,n) imo[i] = imo[i-1] + h[i];
		int res = 0;
		repst(k,1,n) {
			int mn = inf;
			repst(i,k,n) chmin(mn, h[i]*k - (imo[i] - imo[i-k]));
			res ^= mn;
		}
		return res;
	}
};