#include <bits/stdc++.h>
using namespace std;

//#define int long long
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
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln

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

ll k, n, a[100000], d[100000], l, r = 1e12, m, t, x, s;

bool ok() {
	t = 0;
	rep(i,n) {
		if (a[i]>m) continue;
		// x回増築すると次の増築費用がmを超える
		x = (m-a[i])/d[i] + 1;
		t += x;
	}
	return t>=k;
}

ll calc() {
	t = 0;
	rep(i,n) {
		if (a[i]>r) continue;
		// a[i] + a[i]+d[i] + a[i]+2d[i] + ... + a[i]+xd[i]の等差数列
		x = (r-a[i])/d[i] + 1;
		t += a[i]*x + x*(x-1)/2*d[i];
		s += x;
		//cout << i << "番目を" << x << "回増築する" << ln;
	}
	// 足しすぎた分引く
	t -= r * (s-k);
	//cout << "最後に" << k << "回" << r << "円で増築する" << ln;
	return t;
}

signed main() {
	cin >> k >> n;
	rep(i,n) cin >> a[i] >> d[i];
	// k回目の増築の費用の最小値を二分探索で求める
	// 最後の増築にmかかるとすると価格がm未満の建物は次の増築費用がm以上になるまで必ず増築することになる
	// m未満の価格でできる増築をt回やって、それからちょうどm円でできる増築をk-m回できればOK
	while (r-l>1) {
		m = (r+l)/2;
		if (ok()) r = m;
		else l = m;
	}
	// で最後答えをシミュレートする
	cout << calc() << ln;
}