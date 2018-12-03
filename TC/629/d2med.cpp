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
 * アリスちゃんは同級生N人のためにアメを作ろうとしている
 * 各同級生はそれぞれv[i]リットル入る入れ物を持っており、合計w[i]グラムのアメを欲しがっている
 * しかしアリスちゃんは時間がなくて1種類の重さのアメしか作れない
 * 全員の入れ物をアメでいっぱいにしたいが同時になるべくみんなの重さについての希望も叶えたいと思っている
 * 作るアメの重さを調整して Σabs((iさんに渡すアメの重さ)-w[i]) を最小化せよ
 *
 * (解法)
 * Σabs((iさんに渡すアメの重さ)-w[i]) の値は作るアメの重さについて下に凸なグラフになっている
 * 三分探索で極値を求めて、そのときの実際の⇡の式の値が答え
 *
 * (反省)
 * 最初三分探索の回数をwhile (r-l>1e-12)とかにしたらシステムテストで落ちた
 * 整数型ならr-l>1って書き方で問題ないけど小数は精度の問題があるから特に今回みたいに誤差1e-9以下とか
 * 制約が厳しいときはこういう書き方はするべきじゃないかもしれない 無限ループになるリスクもある
 * 個人的にdouble型の精度を信用しすぎてる節があるから気をつけたい
 */

class CandyMaking {
	public:
	double findSuitableDensity(vi v, vi d) {
		int n = v.size();
		double l = 0, r = 1e9;
		rep(i,100) {
			double m1 = l + (r-l)/3, m2 = r - (r-l)/3, s1 = 0, s2 = 0;
			rep(i,n) s1 += abs(m1*v[i]-d[i]), s2 += abs(m2*v[i]-d[i]);
			if (s1<s2) r = m2;
			else l = m1;
		}
		double res = 0;
		rep(i,n) res += abs(l*v[i]-d[i]);
		printf("%.14lf\n",res);
		return res;
	}
};