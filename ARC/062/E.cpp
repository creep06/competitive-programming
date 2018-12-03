#include <bits/stdc++.h>
using namespace std;

#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(ll (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int> > mat;

const ll inf = (ll)1e9+10;
const ll linf = (ll)1e18+10;
const ll mod = (ll)(1e9+7);
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

// 立方体の上面と底面のパネルと前者の向きを全探索
// この2つが決まれば8頂点全ての色が確定するから残りは数え上げればいい
// c[i]の順列のうち辞書順最小のものをハッシュ値として保存しておけば側面のパネルとして採用できる枚数がわかる

int n, c[400][4], t[4], ans;
map<int,int> m;

int id(int a, int b, int c, int d) {return (a<<30)+(b<<20)+(c<<10)+d;}

void pl(int i, int x) {
	int a = i>>30, b = (i>>20)&1023, c = (i>>10)&1023, d = i&1023;
	m[id(a,b,c,d)] += x;
	m[id(d,a,b,c)] += x;
	m[id(c,d,a,b)] += x;
	m[id(b,c,d,a)] += x;
}

signed main() {
	cin >> n;
	rep(i,n) {
		rep(j,4) cin >> c[i][j];
		pl(id(c[i][0],c[i][1],c[i][2],c[i][3]), 1);
	}
	rep(i,n-5) {
		pl(id(c[i][0],c[i][1],c[i][2],c[i][3]), -1);
		reps(j,i+1,n) rep(d,4) {
			// 一つの立方体を作るときに同じパネルを採用しないように一旦使用済みにしてから元に戻す
			pl(id(c[j][0],c[j][1],c[j][2],c[j][3]), -1);
			t[0] = id(c[i][0],c[j][(0+d)%4],c[j][(3+d)%4],c[i][1]);
			t[1] = id(c[i][1],c[j][(3+d)%4],c[j][(2+d)%4],c[i][2]);
			t[2] = id(c[i][2],c[j][(2+d)%4],c[j][(1+d)%4],c[i][3]);
			t[3] = id(c[i][3],c[j][(1+d)%4],c[j][(0+d)%4],c[i][0]);
			if (m[t[0]]&&m[t[1]]&&m[t[2]]&&m[t[3]]) {
				int tmp = 1;
				// ここも同様
				rep(l,4) tmp *= m[t[l]], pl(t[l],-1);
				ans += tmp;
				rep(l,4) pl(t[l],1);
			}
			pl(id(c[j][0],c[j][1],c[j][2],c[j][3]), 1);
		}
	}
	cout << ans << ln;
}