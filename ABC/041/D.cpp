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

const int inf = 100100100;
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

int n, m, x[120], y[120];
vector<vi> m(16);
ll dp[1<<16];

int main() {
	cin >> n >> m;
	rep(i,m) {
		cin >> x[i] >> y[i];
		x[i]--, y[i]--;
	}
	
	// 順序の制約を満たすトポロジカルソートの方法の数を求める問題と言い換えられる
	// dp[S]: 頂点集合Sをソートする方法の数 とすると、dp[S]からはSに含まれない点vを
	// Sをソートした末尾に並べた集合(S+v)全てに遷移する
	// まず全ての集合を、順序の制約を満たすか満たさないかで分ける
	bool no[1<<n] = {};
	rep(s,1<<n) {
		if (no[s]) continue;
		rep(j,m) {
			if (!((s>>x[j])&1) & ((s>>y[j])&1)) no[s] = true;
		}
	}
	
	dp[0] = 1;
	rep(s,1<<n) {
		rep(v,n) {
			// 集合Sにvを追加しても制約を破らない場合のみdp[S+v]にdp[S]を足す
			if (!(s>>v & 1) && !no[s|(1<<v)]) {
				dp[s|(1<<v)] += dp[s];
			}
		}
	}
	cout << dp[(1<<n)-1] << ln;
}