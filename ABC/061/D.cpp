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
struct edge {ll from, to, cost;};

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

ll n, m, a, b, c, d[1000];
edge es[2000];
bool nega = false;	// 負の閉路がある場合true

void BellmanFord(int s) {
	fill(d, d+n, linf);
	d[s] = 0;
	
	for (int j = 0; j < n*2; ++j) {
		bool updatebf = false;
		for (int i = 0; i < m; ++i) {
			edge e = es[i];
			if (d[e.from] != linf && d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				updatebf = true;
				// n-1までの道のりに負の閉路がなければたかだかn-1周でd[n-1]は確定する
				// n周目以降でもまだd[n-1]を更新しようとしてるってことはn-1までの道のりに負の閉路があるってこと
				if (j>=n-1 && e.to==n-1) nega = true;
			}
		}
		if (!updatebf) break;
	}
}

int main() {
	cin >> n >> m;
	rep(i,m) {
		cin >> a >> b >> c;
		a--, b--, c=-c;
		es[i] = edge{a, b, c};
	}
	BellmanFord(0);
	if (nega) cout << "inf" << ln;
	else cout << -d[n-1] << ln;
}