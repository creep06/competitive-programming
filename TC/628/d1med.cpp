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
 * いくつかの抵抗をつなぎ合わせて1つの抵抗を作る 繋ぎ方には2種類あり、
 * タイプAの繋ぎ方で出来る抵抗の値は2つの抵抗の値の和になり、タイプBでは2つの抵抗の最大値になる
 * 繋ぎ方の種類が決まっているとき繋ぐ抵抗の順番を入れ替えて最終的な抵抗の値を最大化せよ
 *
 * (解法)
 * タイプBの繋ぎ方をするってのは1つの抵抗の値を捨てることと同じ
 * 捨てるとすれば最も小さい抵抗を捨てるのが最善 つまり最終的に残る抵抗の値は最初にある抵抗のうち降順に何個か取ったものの和になる
 * この個数を再帰で求めればいい
 */

class CircuitsConstruction {
	public:
	int id = 0;
	string s;
	
	int rec() {
		if (s[id]=='X') return 1;
		if (s[id]=='A') {
			id++;
			int a = rec();
			id++;
			int b = rec();
			return a+b;
		}
		id++;
		int a = rec();
		id++;
		int b = rec();
		return max(a,b);
	}
	
	int maximizeResistance(string st, vi a) {
		s = st;
		sort(a.rbegin(), a.rend());
		return accumulate(a.begin(), a.begin()+rec(), 0);
	}
};