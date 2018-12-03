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

ll n, t[111111], a[111111], p[111111], h[111111], r = 1;

int main() {
	cin >> n;
	rep(i,n) cin >> t[i];
	rep(i,n) cin >> a[i];
	if (t[n-1]!=a[0]) r = 0;
	else {
		// まず高橋くんの記録だけ見たときのi番目の山の高さとしてあり得る種類を求める
		p[0] = 1;
		reps(i,1,n) {
			if (t[i]==t[i-1]) p[i] = t[i];
			else p[i] = 1, h[i] = t[i];
		}
		// 青木くんの記録で⇡を狭める
		p[n-1] = 1;
		repr(i,n-2) {
			if (a[i]==a[i+1]) {
				if (h[i]) p[i] = (h[i]<=a[i]);
				else chmin(p[i], a[i]);
			}
			else {
				if (h[i]) p[i] = (h[i]==a[i]);
				else p[i] = 1;
			}
		}
		rep(i,n) r = (r*p[i])%mod;
	}
	cout << r << ln;
}