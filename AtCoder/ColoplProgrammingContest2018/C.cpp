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

// i番目まででj個選ぶ方法
ll a, b;

ll gcd(ll a, ll b)
{
	ll c;
	
	if (a < b) {
		a+=b; b=a-b; a-=b;
	}
	
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	
	return a;
}

int main() {
	cin >> a >> b;
	vl od, ev;
	for (ll i = a; i <= b; ++i) {
		if (i%2==0) ev.pb(i);
		else od.pb(i);
	}
	int odn = (int)od.size(), evn = (int)ev.size();
	ll bc = b-a+1;
	int n = (int)bc;
	bool so[n][n] = {};
	rep(i,n) rep(j,n) if (gcd(a+i, a+j)==1) so[i][j] = true;
	
	// a+iを絶対選ぶとするとその後選べる数字の候補は？
	// 連続する2整数n, n+1は必ず互いに素 ←関係ないかも
	// 偶数は全部互いに素じゃないので同時には選べない
	// となると35個あっても同時に選ぶ候補はたかだか18個 全列挙できる
	// 奇数だけ組み合わせ全列挙して、全部互いに素かテーブルで確認して、okならans++
	// あとは偶数を1個ずつ見ていってそれも全部と互いに素だったらansをもう一回++
	ll ans = 0;
	rep(i,1<<odn) {
		vl us;
		rep(j,odn) {
			if (i>>j & 1) {
				each(itr,us) {
					if (!so[od[itr]-a][od[j]-a]) goto skp;
				}
				us.pb(j);
			}
		}
		ans++;
		rep(j,evn) {
			each(itr,us) {
				if (!so[od[itr]-a][ev[j]-a]) goto nx;
			}
			ans++;
			nx:;
		}
		skp:;
	}
	cout << ans << ln;
}