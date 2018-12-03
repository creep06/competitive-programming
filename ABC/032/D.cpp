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
#define show(x) cout << #x << " = " << x ln
#define dbg(x) cout<<#x"="<<x ln

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

ll n, W, dp[210][210000], v[210], w[210], mxv, mxw, ans;

// w<=1000 一番普通なやつ
// dp[i][j]: i番目までで重さの総和がj以下になるような選び方の価値の最大値
ll nsw() {
	rep(i,n) {
		rept(j,W) {
			if (j<w[i]) dp[i+1][j] = dp[i][j];
			else dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
		}
	}
	return dp[n][W];
}

// v<=1000
// dp[i][v]: i番目までで価値の総和がjになるような選び方の重さの最小値
ll nsv() {
	// あり得る最大の価値
	ll pV = mxv * n;
	repst(i,1,pV) dp[0][i] = linf;
	rep(i,n) {
		rept(j,pV) {
			if (j<v[i]) dp[i+1][j] = dp[i][j];
			else dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i]);
		}
	}
	ll res = 0;
	rept(i,pV) {
		if (dp[n][i]<=W) res = i;
	}
	return res;
}

// n<=30
// 半分全列挙を2回やって二分探索
ll nsn() {
	ll n1 = n/2;
	ll n2 = n - n1;
	
	// 前半を全列挙してw-vのペアを作る
	pll ps[1<<n1];
	rep(i,1<<n1) {
		ll sv = 0, sw = 0;
		rep(j,n1) {
			if (i>>j & 1) {
				sv += v[j];
				sw += w[j];
			}
		}
		ps[i] = mp(sw, sv);
	}
	
	// 重さで昇順ソートして、重さは同じか増えるのに価値が減るような要素を除外する
	sort(ps, ps+(1<<n1));
	int m = 1;
	reps(i,1,1<<n1) {
		if (ps[m-1].se < ps[i].se) ps[m++] = ps[i];
	}
	
	// 後半を全列挙して↑で厳選したm個の要素からWを超えない範囲で最も価値の高いものを二分探索で探す
	ll res = 0;
	rep(i,1<<n2) {
		ll sv = 0, sw = 0;
		rep(j,n2) {
			if (i>>j & 1) {
				sv += v[n1+j];
				sw += w[n1+j];
			}
		}
		if (sw<=W) {
			ll tv = (lower_bound(ps, ps+m, mp(W-sw, linf))-1)->se;
			chmax(res, sv+tv);
		}
	}
	return res;
}

int main() {
	cin >> n >> W;
	rep(i,n) {
		cin >> v[i] >> w[i];
		chmax(mxv, v[i]), chmax(mxw, w[i]);
	}
	
	if (mxw<=1000) ans = nsw();
	else if (mxv<=1000) ans = nsv();
	else ans = nsn();
	cout << ans << ln;
}