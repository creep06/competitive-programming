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

int n, a[114514], b[114514], c[114514], inv[114514], r, t;
int bit[1919810];
vi v;

// データは[1,n]だからiの値に注意
int sum (int i) {
	i++;
	int s = 0;
	while (i>0) {
		s += bit[i-1];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x) {
	i++;
	while (i<=n) {
		bit[i-1] += x;
		i += i & -i;
	}
}

signed main() {
	cin >> n;
	// a[i]のi番目の数字をiに対応させ、bをその対応で書き換える
	// するとaは1,2,3,...と昇順になり、bの転倒数がそのまま元のaとb間の転倒距離になる
	rep(i,n) {
		cin >> a[i];
		c[a[i]] = i;
	}
	rep(i,n) {
		cin >> b[i];
		b[i] = c[b[i]];
	}
	// bの転倒数をrとおくと、まずrが奇数なら明らかに解なし
	// 偶数のとき、bの一部をバブルソートして転倒数をちょうどr/2に減らしたものが求めたい数列の一つになる
	repr(i,n-1) {
		inv[b[i]] = sum(b[i]);
		r += inv[b[i]];
		add(b[i],1);
	}
	
	if (r&1) {
		cout << -1 << ln;
		return 0;
	}
	
	r /= 2;
	// やりすぎないように転倒数を減らしていく
	repr(i,n-1) {
		t = min(r, inv[i]);
		inv[i] -= t;
		r -= t;
	}
	rep(i,n) {
		v.insert(v.end()-inv[i], a[i]);
	}
	rep(i,n) cout << v[i] << (i==n-1 ? '\n' : ' ');
}