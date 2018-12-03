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

int n, W, w0, w, v;
vi vs[4];

int main() {
	cin >> n >> W;
	cin >> w0 >> v;
	vs[0].pb(v);
	// w0と比較した相対的な重さで分ける 0,1,2,3の4通りしかない
	reps(i,1,n) {
		cin >> w >> v;
		vs[w-w0].pb(v);
	}
	// 降順ソートして価値が高い順に取り出せるようにしとく
	rep(i,4) sort(vs[i].rbegin(), vs[i].rend());
	// ↓で毎回手前からi個、j個…って取ってると時間かかるから累積和をとっておく
	// 毎回合計求めてもたかだか100回だから本番だったら実装の手間かかるだけかも
	int vsum[4][101] = {{}};
	ll wsum[4][101] = {{}};
	rep(i,4) {
		repst(j,1,vs[i].size()) {
			vsum[i][j] = vsum[i][j-1] + vs[i][j-1];
			wsum[i][j] = wsum[i][j-1] + w0 + i;
		}
	}
	// それぞれの重さから何個取るか決めて全列挙し、重さの合計がW以下なら価値の合計でansを更新
	int ans = 0;
	rept(i,vs[0].size()) {
		rept(j,vs[1].size()) {
			rept(k,vs[2].size()) {
				rept(l,vs[3].size()) {
					int Vs = vsum[0][i] + vsum[1][j] + vsum[2][k] + vsum[3][l];
					ll Ws = wsum[0][i] + wsum[1][j] + wsum[2][k] + wsum[3][l];
					if (Ws<=W) chmax(ans, Vs);
					else break;
				}
			}
		}
	}
	cout << ans << ln;
}