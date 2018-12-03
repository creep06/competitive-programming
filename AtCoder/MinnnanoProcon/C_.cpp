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

int n, j, t, m, M, c;
bool a[114514];
string s[114514];

int main() {
	cin >> n >> j;
	rep(i,j) {
		cin >> t;
		t--;
		a[t] = true;
	}
	rep(i,n) cin >> s[i];
	if (n==j) {
		cout << ln;
		return 0;
	}
	// m: 検索したい文字列の共通接頭辞の長さの最小値
	// M: 検索したくない文字列の共通接頭辞の長さの最大値
	m = s[t].length();
	rep(i,n) {
		if (a[i]) {
			chmin(m, (int) s[i].length());
			rep(j, m) {
				if (s[t][j] != s[i][j]) {
					m = j;
					break;
				}
			}
		} else {
			int tm = min((int)s[t].length(), (int)s[i].length());
			rep(j,tm) {
				if (s[t][j] != s[i][j]) {
					tm = j;
					break;
				}
			}
			chmax(M, tm);
		}
	}
	if (M<m) cout << s[t].substr(0,M+1) << ln;
	else cout << -1 << ln;
}