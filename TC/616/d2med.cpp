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
 * 通貨valがn種類ある val[i]はval[0]〜val[i-1]で割り切れる
 * 通貨の色と価値の対応がわからない
 * 無限に金を引き出せるATMがあり、金額を指定するとその金額をちょうど払える払い方のうち通貨の枚数が最小になる払い方で金が出てくる
 * うまく金額を指定することで通貨の色と価値の対応を全て知ることができるか判定
 *
 * (解法)
 * 要は各通貨を異なる枚数ずつ引き出せればいい
 * ex1で書いてある通り、1を2枚と3を1枚引き出せればそれぞれの価値と色の対応がわかる
 * ダメなパターンはval = {1,2,4}みたいなやつ 各通貨を1枚、2枚、3枚とか異なる枚数ずつ引き出せればokだけどそういう割当が存在しない
 * (例えば1*1+2*2+3*4==17を引き出そうとすると4が4枚と1が1枚出てくる)
 * num[i] = val[i+1]/val[i]とする
 * val[i]の通貨をnum[i]枚引き出そうとするとval[i+1]の通貨1枚にまとめて支払われてしまうから判別できない
 * 引き出し枚数の割当はnumの昇順が最善だからそれでダメならimpossible
 */

class ColorfulCoinsEasy {
	public:
	string isPossible(vi val) {
		int n = val.size();
		vi num;
		rep(i,n-1) num.pb(val[i+1]/val[i]);
		sort(all(num));
		rep(i,n-1) if (num[i]<=i+1) return "Impossible";
		return "Possible";
	}
};