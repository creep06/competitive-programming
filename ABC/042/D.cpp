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

ll h, w, a, b, ans, kai[2000010];

ll nCk(ll n, ll k) {
	ll bunsi = kai[n];
	ll bunbo = (kai[k] * kai[n-k])%mod;
	
	ll gyaku[30];	// 元の数字の2^k乗の%mod
	gyaku[0] = bunbo;
	reps(i,1,30) gyaku[i] = (gyaku[i-1]*gyaku[i-1])%mod;
	bunbo = 1;
	rep(i,30) if ((mod-2)>>i & 1) bunbo = (bunbo*gyaku[i])%mod;
	return (bunsi*bunbo)%mod;
}

int main() {
	cin >> h >> w >> a >> b;
	h--, w--, a--, b--;
	// ↓考えた流れ
	// https://drive.google.com/file/d/1CMoW510aobDu8Ab0X_0M-CDtKJVuXr0G/view?usp=sharing
	// 何回も使うことになるから2*10^6までの階乗%modを求めておく
	kai[0] = kai[1] = 1;
	repst(i,2,2000000) kai[i] = (kai[i-1]*i)%mod;
	rep(i,w-b) ans = (ans + nCk(h-a+b+i, b+i+1) * nCk(a+w-b-i-1, w-b-i-1))%mod;
	cout << ans << ln;
}