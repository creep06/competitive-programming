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

// aに+2 bに+1
// aに2足す権利、bに1足す権利
int n, a[10000], b[10000], ap, bp;

signed main() {
	cin >> n;
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];
	rep(i,n) {
		if (a[i]==b[i]) continue;
		if (a[i]>b[i]) {
			// 権利を使うだけ使う　それでも差が埋まらないならaに2足す権利を獲得
			int dif = a[i]-b[i];
			int ken = min(dif,bp);
			dif -= ken, bp -= ken;
			ap += dif;
			//cout << "apに" << dif << ln;
		}
		else if (a[i]<b[i]) {
			// 同様
			int dif = b[i]-a[i];
			// 両方に2,1ずつ足せば差は1埋まる
			if (dif%2==1) dif--;
			int ken = min(dif/2, ap);
			dif -= ken*2, ap -= ken;
			bp += dif/2;
			//cout << "bpに" << dif/2 << ln;
		}
	}
	//cout << ap << ' ' << bp << ln;
	if (ap<=bp) cout << "Yes" << ln;
	else cout << "No" << ln;
}