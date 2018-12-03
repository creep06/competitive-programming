#include <bits/stdc++.h>
using namespace std;

//#define int long long
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
#define ln '\n'
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

int n, k, a[26];
string s;
pair<string, int> p[100000];

signed main() {
	cin >> n >> k >> s;
	// しゃくとりで1周すれば長さkの全ての部分文字列をチェックできる
	// 全ての部分文字列でのアルファベットの出現頻度を保持して、同じ状態が2個以上あればOK
	// stringとかでn-k+1個保存してソートしてもう一周見ていく？
	// 共通部分があったらだめだから2つの状態同士のlの差がk以上あればいい
	rep(i,k) t[s[i]-'a']++;
	string t;
	rep(i,26) t += to_string(t[i]);
	p[0] = {t,0};
	reps(r,k,n) {
		int l = r - k + 1;
		t[s[r]-'a']++, t[s[l-1]-'a']--;
		string te;
		rep(i,26) te += to_string(t[i]);
		p[l] = {te,l};
	}
	sort(p, p+n-k+1);
	rep(i,n-k+1) {
		//cout << p[i].se << " " << p[i].fi << ln;
		int mn = p[i].se, mx = p[i].se;
		while (i<n-k && p[i].fi == p[i+1].fi) i++, chmin(mn, p[i].se), chmax(mx, p[i].se);
		if (mx-mn>=k) {
			cout << "YES" << ln;
			return 0;
		}
	}
	cout << "NO" << ln;
}