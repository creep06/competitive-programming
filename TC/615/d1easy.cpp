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
 * アメーバは自分と全く同じサイズのジェルに出会うとそれを食べ、アメーバのサイズが倍になる
 * アメーバが出会ったジェルのサイズxが出会った順に与えられる 最終的なアメーバのサイズとしてあり得ないものの個数を求めよ
 *
 * (解法)
 * アメーバの初期サイズがxに含まれない数字だった場合、最後まで1個もジェルを食べられずサイズは変わらないので、
 * とりあえずxに含まれる数字全てが答えの候補になる
 * あとは実際にそれらを初期サイズとしてシミュレートしてみて、実はあり得るサイズがあればメモしておき、
 * 候補の個数からあり得るサイズの個数を引いたものが答え
 * 例えばex1は最初は1,2,3が候補だけど、初期サイズ1のとき最終的に2になるから、答えはsize({1,2,3}) - size({2}) == 2
 */

class AmebaDiv1 {
	public:
	int count(vi x) {
		set<int> s, t;
		each(i,x) s.insert(i);
		each(i,s) {
			int k = i;
			each(j,x) if (k==j) k *= 2;
			if (s.count(k)) t.insert(k);
		}
		return s.size() - t.size();
	}
};
