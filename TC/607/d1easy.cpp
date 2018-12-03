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
 * s1とs2を全て繋げて出来る文字列sのうち、文字'?'は等確率で26種のアルファベットどれかに変わる
 * sの全てのsubstringのうち回分になっているものの個数の期待値を求めよ
 *
 * (解法)
 * 自力で解けなかった ↓参考
 * http://ekaing.hatenablog.com/entry/2014/02/25/012055
 * dp[l][r]: sの[l,r]の範囲が回分になる確率 とすると
 * dp[l][r] = dp[l+1][r-1] * (s[l]==s[r]になる確率)
 * これを用いるとO(n^2)
 */

class PalindromicSubstringsDiv1 {
	public:
	double expectedPalindromes(vector<string> s1, vector<string> s2) {
		string s;
		each(i,s1) s += i;
		each(i,s2) s += i;
		int n = s.size();
		double res = 0;
		rep(i,n) {
			// i文字目単体のsubstringは必ず回分
			res += 1;
			// i文字目を中心とした奇数文字のsubstring
			double p = 1;
			for (int l=i-1, r=i+1; 0<=l && r<n; --l, ++r) {
				if (s[l]=='?' || s[r]=='?') p /= 26.0, res += p;
				else if (s[l]==s[r]) res += p;
				else break;
			}
			// 偶数文字
			p = 1;
			for (int l=i, r=i+1; 0<=l && r<n; --l, ++r) {
				if (s[l]=='?' || s[r]=='?') p /= 26.0, res += p;
				else if (s[l]==s[r]) res += p;
				else break;
			}
		}
		return res;
	}
};