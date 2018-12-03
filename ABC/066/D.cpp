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

int n, a[111111], cnt[111111], l = -1, r, m;
ll g[111111], o[111111], ng[30], x, y, ans;

ll comb(ll N, ll R) {
	// ↓今回はN<0とかR<0で呼び出されることはないけど一応
	// "N<Rなら0"って条件がないと組み合わせが0個でも1を返しちゃうので注意
	if (N<0 || R<0 || N<R) return 0;
	// nCr = n!/(r!(n-r)!) 分母のr!と(n-r)!両方の逆元をかける
	return o[N] * g[R] % mod * g[N-R] % mod;
}

int main() {
	cin >> n;
	rep(i,n+1) {
		cin >> a[i];
		cnt[a[i]]++;
		if (cnt[a[i]]==2) m = a[i];
	}
	
	// 重複要素2つのインデックス(l<r)を取得
	rep(i,n+1) {
		if (a[i]==m) {
			if (l==-1) l = i+1;
			else r = i+1;
		}
	}
	
	// 事前に分子の方(n!)を全通り 100001!まで
	o[0] = o[1] = 1;
	repst(i,2,100001) o[i] = o[i-1] * i % mod;
	// フェルマーの小定理でまず(100001!)^-1を求めて、それに100001をかけると(100000!)^-1が求められる
	// これを繰り返すことで高速に逆元テーブルを作れる
	// 1〜n+1の逆元テーブルを全部作っておけば後で全てのnCkがO(1)で計算できる
	// ng[i]: 100001!の2^i乗 繰り返し2乗法
	ng[0] = o[100001];
	reps(i,1,30) ng[i] = ng[i-1] * ng[i-1] % mod;
	// 100001!のmod-2乗 == -1乗(%mod)を求める
	g[100001] = 1;
	rep(i,30) if ((mod-2)>>i & 1) g[100001] = g[100001] * ng[i] % mod;
	// さっき言った方法を使って上から順に逆元テーブルを埋める
	repr(i,100000) g[i] = g[i+1] * (i+1) % mod;
	
	// まず(n+1)Ckが重複を許した場合の部分列の個数 ここから重複した部分列の個数を引きたい
	// 公式解説の通り、重複する部分列ってのはその部分列の数字がそれぞれ元の数列のどこに対応するかわからないもの
	// a[l]とa[r]のうち片方だけと、lとrに挟まれていない部分も使っている部分列は復元できない
	// 例えば23145167って数列から取り出せる21とか167って部分列の"1"はどっちの1を使っているのかわからない ∴ 重複する
	// こういう部分列の数は、a[l]かa[r]を1個 と 範囲[l,r]に含まれないl-1 + n+1-r個の要素からk-1個 選ぶ組み合わせの個数に等しい
	repst(k,1,n+1) {
		//cout << l << "番目の左側" << l-1 << "個と、" << r << "番目の右側" << n+1-r << "個の中から" << k-1 << "個選ぶ" << ln;
		// n+1 C k
		x = comb(n+1, k);
		// (l-1 + n+1-r) C k-1
		y = comb(l+n-r, k-1);
		// 負にならないようにmod足してから引き算
		ans = (x + mod - y) % mod;
		cout << ans << ln;
	}
}