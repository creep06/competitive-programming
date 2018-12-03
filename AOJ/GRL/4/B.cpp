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

// ⊂ニニニニニニニニニニニニニ( ^ω^)ニニニニニニニニニニニニニ⊃

// 頂点数、辺数、入次数
int v, e, in[100000];
// 入次数0の頂点をここに入れていく
queue<int> S;
// 辺の隣接リスト
mat V(100000);
// 答え
vi ans;

int main() {
	cin >> v >> e;
	rep(i,e) {
		int a, b;
		cin >> a >> b;
		V[a].pb(b);
		in[b]++;
	}
	
	// 入次数0の頂点を列挙
	rep(i,v) if (in[i]==0) S.push(i);
	while (!S.empty()) {
		int u = S.front(); S.pop();
		ans.pb(u);
		// uの順序が確定したのでグラフから消し、隣接する全ての点の入次数を1下げる
		rep(i,V[u].size()) {
			int to = V[u][i];
			in[to]--;
			// この操作によって入次数が0になった点があればSに追加
			if (in[to]==0) S.push(to);
		}
	}
	rep(i,v) cout << ans[i] << ln;
}