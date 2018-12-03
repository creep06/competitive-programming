#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define rept(i,n) for(ll (i)=0;(i)<=(ll)(n);(i)++)
#define reps(i,s,n) for(ll (i)=(s);(i)<(ll)(n);(i)++)
#define repst(i,s,n) for(ll (i)=(s);(i)<=(ll)(n);(i)++)
#define repr(i,n) for(ll (i)=(n);(i)>=0;(i)--)
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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

int n, r[100000], h[100000], wi[100000], lo[100000], dr[100000];
vi g, c, p;

int main() {
	cin >> n;
	rep(i,n) {
		cin >> r[i] >> h[i];
		if (h[i]==1) g.pb(r[i]);
		else if (h[i]==2) c.pb(r[i]);
		else p.pb(r[i]);
	}
	sort(all(g)), sort(all(c)), sort(all(p));
	// 実装がまずかったかもしれない
	rep(i,n) {
		// レートが上回ってれば手は関係なく勝てる
		wi[i] = (lower_bound(all(g), r[i]) - g.begin())
				+ (lower_bound(all(c), r[i]) - c.begin())
				+ (lower_bound(all(p), r[i]) - p.begin());
		if (h[i]==1) {
			// レートが一緒なら通常のじゃんけん
			wi[i] += upper_bound(all(c), r[i]) - lower_bound(all(c), r[i]);
			dr[i] += upper_bound(all(g), r[i]) - lower_bound(all(g), r[i]) - 1;	// 自分自身をカウントしないように
		} else if (h[i]==2) {
			wi[i] += upper_bound(all(p), r[i]) - lower_bound(all(p), r[i]);
			dr[i] += upper_bound(all(c), r[i]) - lower_bound(all(c), r[i]) - 1;
		} else {
			wi[i] += upper_bound(all(g), r[i]) - lower_bound(all(g), r[i]);
			dr[i] += upper_bound(all(p), r[i]) - lower_bound(all(p), r[i]) - 1;
		}
		lo[i] = n-1 - (wi[i]+dr[i]);
		cout << wi[i] << ' ' << lo[i] << ' ' << dr[i] << ln;
	}
}