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

ll h, w, ans = linf;

void calch(ll hs) {
	ll sa, sb, sc;
	sa = hs * w;
	// タテ3分割
	sb = (h-hs)/2 * w;
	sc = ((h-hs)-(h-hs)/2) * w;
	if (sb>0 && sc>0) {
		chmin(ans, max(sa, max(sb, sc)) - min(sa, min(sb, sc)));
	}
	// ヨコ2分割
	sb = (h-hs) * (w/2);
	sc = (h-hs) * (w - (w/2));
	if (sb>0 && sc>0) {
		chmin(ans, max(sa, max(sb, sc)) - min(sa, min(sb, sc)));
	}
}

void calcw(ll ws) {
	ll sa, sb, sc;
	sa = h * ws;
	// ヨコ3分割
	sb = (w-ws)/2 * h;
	sc = ((w-ws)-(w-ws)/2) * h;
	if (sb>0 && sc>0) {
		chmin(ans, max(sa, max(sb, sc)) - min(sa, min(sb, sc)));
	}
	// タテ2分割
	sb = (w-ws) * (h/2);
	sc = (w-ws) * (h-(h/2));
	if (sb>0 && sc>0) {
		chmin(ans, max(sa, max(sb, sc)) - min(sa, min(sb, sc)));
	}
}

int main() {
	cin >> h >> w;
	repst(i,1,h-1) calch(i);
	repst(i,1,w-1) calcw(i);
	cout << ans << ln;
}