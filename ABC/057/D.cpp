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
#define YES(x) if(x)cout<<"YES"<<ln;else cout<<"NO"<<ln
#define Yes(x) if(x)cout<<"Yes"<<ln;else cout<<"No"<<ln

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

int n, a, b;
vl v(55);
ll c[55][55];

// パスカルの三角形を作る
void comb() {
	rept(i,n) {
		rept(j,i) {
			if (j==i || j==0) c[i][j] = 1;
			else c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
	}
}

int main() {
	cin >> n >> a >> b;
	rep(i,n) cin >> v[i];
	nck();
	
	// まず平均はでかい順にa個取るのが明らかに最善
	sort(v.rbegin(), v.rend());
	double ave = 0;
	rep(i,a) ave += v[i];
	ave /= a;
	printf("%.24lf\n", ave);
	
	// この場合は選ぶ品物の数を増やすほど平均値が減っていく
	// 右端(a[i-1]と同じ値)が複数個あればそれの選び方が複数出てくる
	if (v[0]!=v[a-1]) {
		int x = 0, y = 0;
		rep(i,n) if (v[i]==v[a-1]) x++;
		rep(i,a) if (v[i]==v[a-1]) y++;
		printf("%lld\n", c[x][y]);
	}
	// この場合はv[0]と同じ数がX(>=A)個あるとするとΣXCk(k=A..min(B,X))通り
	else {
		int x = 0;
		rep(i,n) if (v[i]==v[0]) x++;
		ll ans = 0;
		repst(i,a,b) ans += c[x][i];
		printf("%lld\n", ans);
	}
}