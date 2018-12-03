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
const double eps = 1e-6;

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
 * h(x) = x^d(x), d(x) = (xの約数の個数) と定義する
 * h(x) = nを満たす最小のxを求めよ (存在しない場合-1)
 *
 * (解法)
 * xが素数じゃない場合d(x)>=3が成り立つから10^6まで調べれば10^18までの数字をカバーできる
 * これに引っかからなかったらあとはnが素数の2乗になってる以外あり得ない
 * 誤差を考慮してsqrt(n)の前後をいくつか調べればいい
 * これにも引っかからなかったら-1を返す
 *
 * (反省)
 * ↓参考↓
 * http://kmjp.hatenablog.jp/entry/2014/07/23/0900
 * 方針は全く一緒だったけどオーバーフロー対策だけどうすればいいかわからなかった
 * (ちなみにdouble型でやったらシステムテストで落ちた 誤差の問題？)
 * p*i/iがpにならなかったらオーバーフローしてるって見分け方は勉強になった
 * あとdoubleで試しに計算してみてnを超えそうならやめる、超えないならlong longで実際に計算するってテクもあるらしい
 *
 * あと約数の個数を数え上げるアルゴリズムについて ⇡のありきたりなやり方だとO(N√N) (N==10^6)でTLEする？と思って
 * エラトステネスっぽく工夫したんだけど余計なことをしてたらしい
 * 本番ではなるべくこういう無駄な工夫に時間を割きたくないから計算量の見積もりに気をつけたい
 */

class DivisorsPower {
	public:
	ll findArgument(ll n) {
		int d[1001001] = {};
		repst(i,1,1000000) {
			for (int j = i; j <= 1000000; j += i) d[j]++;
			ll p = 1;
			bool ov = false;
			rep(k,d[i]) {
				if (n<p*i || p*i/i!=p) ov = true; // ( ^ω^) ここがポイント ( ^ω^)
				p *= i;
			}
			if (!ov && p==n) return i;
		}
		
		ll sq = sqrt(n);
		repst(i,max(2ll,sq-5),sq+5) {
			bool pr = true;
			for (int j = 2; j*j <= i; ++j) if (i%j==0) pr = false;
			if (pr && (ll)i*i==n) return i;
		}
		return -1;
	}
};