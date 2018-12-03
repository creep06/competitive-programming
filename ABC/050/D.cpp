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

/*
 * X = a+b, Y = a^b, a⊇bとして0 <= X, Y <= Nを満たすX, Yの組の数を求める
 * (a+b<=N, a^b<=Nを満たすa,bの組を求めるのとは違う)
 * a⊇bってのはaのiビットをa[i]と表すとするとa[i]>=b[i]が全てのiについて成り立つって意味
 * つまり(aのiビット、bのiビット)の組は(0,0), (1,0), (1,1)の3通りしかない (0,1)はだめ
 * この条件をつけるとX,Yの値からa,bの組を復元できる
 * Yが奇数なら(1,0)のパターンで、Yが偶数ならXも見ればわかる
 * 逆にこの条件がなかったら(0,1)と(1,0)の区別がつかなくなるから重複カウントしてしまう
 * この条件を思いつけばあとは桁dp
 */

ll n;
map<pll, ll> m;

ll f(ll s, ll x) {
	if (m[pll(s, x)]) return m[pll(s, x)];
	// a:even b:even 0-0
	ll res = f(s/2, x/2);
	// a:odd b:even 1-0
	if (s>=1 && x>=1) res += f((s-1)/2, (x-1)/2);
	// a:odd b:odd 1-1
	if (s>=2) res += f((s-2)/2, x/2);
	return m[pll(s, x)] = res % mod;
}

int main() {
	cin >> n;
	m[pll(0, 0)] = 1;
	cout << f(n, n) << ln;
}