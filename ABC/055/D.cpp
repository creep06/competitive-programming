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

int n;
string t;
bool a[100010], b[100010];

void g() {
	int i;
	for (i = 0; i < n; i++) printf("%c", b[i] ? 'W' : 'S');
	printf("\n");
	exit(0);
}

void f() {
	int i;
	for (i = 2; i <= n + 1; i++) b[i] = b[i - 2] ^ b[i - 1] ^ a[i - 1];
	if (b[0] == b[n] && b[1] == b[n + 1]) g();
}

int main() {
	cin >> n >> t;
	rep(i,n) a[i] = (t[i]=='x');
	a[n] = a[0];
	
	// 連続する2匹の動物がそれぞれ何なのかさえわかればあとは連鎖して他の動物も全部わかる
	// 具体的にはi番目が羊でi+1番目が狼ってわかってたとすると、i+1が○ならそれは嘘なのでi+2は狼、とか
	// だから1番目と2番目の動物を仮に決めちゃってsに矛盾するかどうかを調べればいい
	b[0] = 0, b[1] = 0; f();
	b[0] = 0, b[1] = 1; f();
	b[0] = 1, b[1] = 0; f();
	b[0] = 1, b[1] = 1; f();
	cout << -1 << ln;
}