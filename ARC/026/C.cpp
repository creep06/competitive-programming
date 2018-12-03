#include <bits/stdc++.h>
using namespace std;

#define int long long
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
typedef tuple<int,int,int> tp;

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

int n, N, m, l, r, c, tmp, dp[100100];

const int MAX_N = 100100;
int dat[2*MAX_N - 1];
tp p[100100];

void init(int n_) {
	n = 1;
	while (n<n_) n *= 2;
	for (int i = 0; i < 2*n-1; ++i) dat[i] = INT_MAX;
}

void update(int k, int a) {
	k += n-1;
	dat[k] = a;
	while (k>0) {
		k = (k-1)/2;
		dat[k] = min(dat[k*2+1], dat[k*2+2]);
	}
}

int querys(int a, int b, int k, int l, int r) {
	if (r<=a || b<=l) return INT_MAX;
	if (a<=l && r<=b) return dat[k];
	else {
		int vl = querys(a, b, k*2+1, l, (l+r)/2);
		int vr = querys(a, b, k*2+2, (l+r)/2, r);
		return min(vl, vr);
	}
}

int query(int a, int b, int n) {
	return querys(a, b, 0, 0, n);
}

signed main() {
	cin >> m >> N;
	init(N+10);
	rep(i,m) {
		cin >> l >> r >> c;
		p[i] = make_tuple(l,r,c);
	}
	sort(p, p+m);
	fill(dp, dp+N+10,linf);
	dp[0] = 0;
	update(0,0);
	rep(i,m) {
		tie(l,r,c) = p[i];
		tmp = query(l,r,n);
		chmin(dp[r], tmp+c);
		update(r, tmp+c);
	}
	cout << dp[N] << ln;
}