#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rept(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
#define repst(i,s,n) for(int (i)=(s);(i)<=(int)(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln "\n"
#define dbg(x) cout<<#x" = "<<x ln

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > mat;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

int n, a[345678];
ll suml, sumr, b[123456], ans = -linf;
priority_queue<int, vi, greater<>> ql;
priority_queue<int> qr;

int main() {
	cin >> n;
	rep(i,n*3) cin >> a[i];
	
	// n <= k < 2nの範囲でkを動かし、qlに常に[0,k]の範囲で大きい方からn個の要素が入ってる状態を保つ
	// kを1ずつ右にずらし、その度にqlの最小値を取り出してa[k]を入れ直して差分をsumlに足し、sumをbにしまっておく しゃくとり的な
	// qrには[k,3n)の範囲で小さい方からn個の要素を入れて同様にsumrを求めていき、bから引く
	// これで(kより左n個の総和)-(kより右n個の総和)が全通り求められるので最大値を出力すればいい
	
	// 前半分
	rep(i,n) {
		suml += a[i];
		ql.push(a[i]);
	}
	b[0] = suml;
	reps(k,n,n*2) {
		// 今厳選してあるn個の中の最小値よりa[k]の方が更に小さいなら何もしなくていい
		if (ql.top()<a[k]) {
			suml -= ql.top(); ql.pop();
			suml += a[k];
			ql.push(a[k]);
		}
		b[k-n+1] = suml;
	}
	// 後ろ半分
	reps(i,n*2,n*3) {
		sumr += a[i];
		qr.push(a[i]);
	}
	b[n] -= sumr;
	for (int k = n*2-1; k >= n; --k) {
		if (qr.top()>a[k]) {
			sumr -= qr.top(); qr.pop();
			sumr += a[k];
			qr.push(a[k]);
		}
		b[k-n] -= sumr;
	}
	// 最大値探し
	rept(i,n) chmax(ans, b[i]);
	cout << ans << ln;
}