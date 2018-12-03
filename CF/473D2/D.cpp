#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto &(itr):(v))
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) if(x>y)x=y
#define chmax(x,y) if(x<y)x=y
#define log2(x) (log(x)/log(2))
#define ln '\n'
#define bln(i,n) ((i==n-1)?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
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

ll mop(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

int n, a[114514];
bool pc[3003003];
bool used[3003003];
priority_queue<int,vi,greater<int>> p;

// エラトステネスの篩 O(NloglogN)
void sieve() {
	fill(pc, pc+3003003, true);
	pc[0] = pc[1] = false;
	for (int i = 2; i*i <= 3000000; ++i)
		if (pc[i]) for (int j = 2*i; j <= 3000000; j += i) pc[j] = false;
	for (int i = 2; i <= 3000000; ++i) if (pc[i]) p.push(i);
}

// 素因数分解 O(√N)
vi pf(ll n) {
	vi res;
	for (ll i = 2; i*i <= n; i++) {
		if (n%i==0) res.pb(i), n /= i;
		while (n%i==0) n /= i;
	}
	if (n!=1) res.pb(n);
	return res;
}


signed main() {
	sieve();
	// 素数が216816個用意できる
	// 手前から順に決めていく
	// 今まで使った数の中にa[i]と素でないものがあれば使えないからa[i]より大きい素数の中で最小のものを採用
	// それ以降はまだ大丈夫なものを小さい順に並べればいい
	// 境目は1回だけだから重い処理しても大丈夫なはず
	cin >> n;
	rep(i,n) cin >> a[i];
	// 辞書順でaよりでかいって制約を満たしたらtrue
	bool bg = false;
	rep(i,n) {
		// あとは小さい方から詰めるだけ
		if (bg) {
			while (used[p.top()]) p.pop();
			cout << p.top();
			p.pop();
		}
		// なるべくa[i]に近づける
		else {
			vi d = pf(a[i]);
			bool ok = true;
			each(j,d) if (used[j]) ok = false;
			// a[i]をそのまま使える場合
			if (ok) {
				each(j,d) used[j] = true;
				cout << a[i];
			}
			// そのままじゃダメな場合 a[i]より大きい最小のokなやつ
			else {
				repst(j,a[i]+1,3000000) {
					d = pf(j);
					ok = true;
					each(k,d) if (used[k]) {
						ok = false;
						break;
					}
					if (ok) {
						cout << j;
						each(k,d) used[k] = true;
						break;
					}
				}
				bg = true;
			}
		}
		cout << bln(i,n);
	}
}