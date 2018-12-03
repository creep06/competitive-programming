#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto &(itr):(v))
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
#define bln(i,n) (i==n-1?'\n':' ')
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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// 現れる数字が全て偶数回のもののうちs未満の最大値を求める
// 後ろから1つずつ見ていき、その文字を一旦消してみる
// で残った文字のうち奇数回のものの個数 <= 消した文字数
// になるたび、奇数回の文字たちを消した部分にあてはめても元の数字を超えないか確認
// 超えないような最大の並びが存在するならそこで終了、しないなら続行
// これで先頭まで来ちゃった場合は9をn-2回出力して終了すればいい
// 毎回確認してるとTLEしそう
// 使わないといけない文字を昇順に並べたものの先頭に長さの差分だけ0をつけたしたもの
// これが元の数字より小さければ少なくともそれ以上遡る必要はなくあとは並べ方を考えてなるべく元の数字に近づけるだけでよくなる

int t;
string s;

int bit[1<<10], n;

signed main() {
	reps(i,1,1<<10) bit[i] = 1 + bit[i-(i&-i)];
	cin >> t;
	while (t--) {
		cin >> s;
		n = s.size();
		
		// 奇数文字は弾ける
		if (n%2) {
			rep(i, n - 1) cout << 9;
			cout << ln;
			continue;
		}
		
		int cur = 0;
		each(i,s) cur ^= 1<<(i-'0');
		bool fin = false;
		repr(i,n-1) {
			int c = s[i]-'0';
			cur ^= 1<<c;
			repr(j,c-1) {
				cur ^= 1<<j;
				if (i+1+bit[cur]<=n) {
					fin = true;
					s[i] = j+'0';
					int pnt = i+1, lft = n - (i+1+bit[cur]);
					while (lft--) s[pnt++] = '9';
					repr(k,9) if (cur & (1<<k)) s[pnt++] = '0'+k;
				}
				cur ^= 1<<j;
				if (fin) break;
			}
			if (fin) break;
		}
		int pnt = 0;
		while (s[pnt]=='0') pnt++;
		cout << s.substr(pnt,n-2*pnt) << ln;
	}
}