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
 * (0,0)からスタートし、ステップk(0-based)では上下左右どれかに3^kだけ進む
 * あるkにおいて(x,y)に辿り着けるか判定
 *
 * (解法)
 * 1,3,9,27,...を足したり引いたりしてある数xが作れるとき、正負を逆にすれば-xも作れるので、x,yは絶対値をとっても問題ない
 * まず|x|,|y|それぞれを3進法に直す また、任意の3進数は1と0のみ用いた3進数NとMの差という形に変形できる
 * 例えば12==100-011, 222==1000-0001とか
 * 前者はステップ0,1で右、ステップ3で左に移動してx==12(3進法)に辿り着くという操作に対応している
 * (後者はステップ0で右、ステップ3で左に移動してx==222に辿り着く)
 * こうやって分けて出来た計4つの3進数のxorが1にならない桁があったらImpossible、そうでなければPossibleを出力
 *
 * システスは通ったけどたぶん想定解じゃないと思う
 */

class PowerOfThree {
	public:
	vi conv(int x) {
		vi res;
		while (x>=3) {
			res.pb(x%3);
			x /= 3;
		}
		res.pb(x);
		res.resize(50);
		rep(i,49) {
			if (res[i]==2) res[i] = 1, res[i+1]++;
			else if (res[i]==3) res[i] = 0, res[i+1]++;
		}
		return res;
	}
	string ableToGet(int x, int y) {
		if (x==0 && y==0) return "Possible";
		x = abs(x), y = abs(y);
		vi a = conv(x), b = conv(y);
		bool fin = false;
		rep(i,50) {
			if ((a[i]&b[i]) || (fin && (a[i]|b[i]))) return "Impossible";
			if (!a[i] && !b[i]) fin = true;
		}
		return "Possible";
	}
};