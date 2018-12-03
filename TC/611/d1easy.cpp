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
 * 数列Aの数字の組み合わせで作れるLCMの集合と数列Bの〜集合が全く同じになるかどうか判定
 *
 * (解法)
 * Aには入っててBには入ってない数字をBの数字の組み合わせで作れなかったら無理 逆に作れればその後⇡の操作で同じ集合ができる
 * Bには入ってて〜も同じ
 * 例えばex2は、14,105はAのみに含まれていてBにはないけど、Bの{2,7}のLCMが14で、{3,5,7}のLCMが105だからOK
 * 逆に6,30,35はBのみに含まれているけど、Aの{2,3}のLCMが6、{2,3,5}のLCMが30、{5,7}のLCMが35だからOK
 * みたいな感じで判定する
 *
 * (反省)
 * 実装がクソ a[i]/b[i]をb/aの寄せ集めで作れるか判定するメソッド作ってまとめるべき
 */

class LCMSet {
	public:
	
	// 素因数分解 O(√N)
	map<ll, int> pf(ll n) {
		map<ll, int> res;
		for (ll i = 2; i*i <= n; i++) {
			while (n%i==0) {
				++res[i];
				n /= i;
			}
		}
		if (n!=1) res[n]++;
		return res;
	}
	
	string equal(vi a, vi b) {
		int n = a.size(), m = b.size();
		map<ll,int> x[50], y[50];
		rep(i,n) x[i] = pf(a[i]);
		rep(i,m) y[i] = pf(b[i]);
		// b->a
		rep(i,n) {
			bool ex = false;
			each(j,b) if (a[i]==j) ex = true;
			if (ex) continue;
			map<ll,int> need;
			each(j,x[i]) need[j.fi] = j.se;
			rep(j,m) {
				bool us = true;
				each(k,y[j]) if (x[i][k.fi]<k.se) us = false;
				if (us) each(k,y[j]) if (need[k.fi]==k.se) need[k.fi] = 0;
			}
			each(j,need) if (j.se>0) return "Not equal";
		}
		// a->b
		rep(i,m) {
			bool ex = false;
			each(j,a) if (b[i]==j) ex = true;
			if (ex) continue;
			map<ll,int> need;
			each(j,y[i]) need[j.fi] = j.se;
			rep(j,n) {
				bool us = true;
				each(k,x[j]) if (y[i][k.fi]<k.se) us = false;
				if (us) each(k,x[j]) if (need[k.fi]==k.se) need[k.fi] = 0;
			}
			each(j,need) if (j.se>0) return "Not equal";
		}
		return "Equal";
	}
};