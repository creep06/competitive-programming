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
 * 各マスにはリンゴが置いてあるかナシが置いてあるか何も置いていない
 * あるマスに置いてある果物を何も置いていないマスに移動する という操作をk回まで行えるとき、
 * リンゴが置いてあるマスのみからなる長方形の面積の最大値を最大化せよ
 *
 * (解法)
 * あるマスを "リンゴが置いてあるマス" に変えるには、そのマスにもともと
 * ナシが置いてある場合) ナシをどこかの空白マスにどけてからリンゴを持ってくる -> コスト2
 * 何も置いていない場合) リンゴを置くだけ -> コスト1
 * リンゴが置いてある場合) 何もしなくていい -> コスト0
 * こう考えるとある長方形領域をリンゴマスで満たすために何回操作を行う必要があるかわかる
 * 全ての長方形領域についてコストを求めて、コストk以下のときのみその長方形の面積で答えを更新 O(N^6)
 * ただし空白マスが1個もないときは一切操作できない、つまりkの値に関係なく総コスト0のときしか答えを更新できないことに注意
 */

class UniformBoard {
	public:
	int getBoard(vst s, int k) {
		int n = s.size(), ap = 0, bl = 0, res = 0;
		rep(i,n) rep(j,n) ap += s[i][j]=='A', bl += s[i][j]=='.';
		rep(i,n) rep(j,n) { // 長方形の左上の点
			repst(a,1,n-i) repst(b,1,n-j) { // 長方形のタテサイズ、ヨコサイズ
				if (a*b>ap) continue;
				int cost = 0;
				reps(x,i,i+a) reps(y,j,j+b) {
					if (s[x][y]=='.') cost += 1;
					else if (s[x][y]=='P') cost += 2;
				}
				if ((bl==0 && cost==0) || (bl!=0 && cost<=k)) chmax(res,a*b);
			}
		}
		return res;
	}
};