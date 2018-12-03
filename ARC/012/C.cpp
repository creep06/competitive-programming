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

int b, w, bm, wm, l;
char t;
string s[19];

bool fin() {
	rep(i,19) {
		rep(j,19) {
			if (s[i][j]!='.') {
				bm = wm = 0;
				rep(k,8) {
					l = 1;
					while (true) {
						int ii = i + l*ddx[k], jj = j + l*ddy[k];
						if (ii<0 || 19<=ii || jj<0 || 19<=jj || s[ii][jj]!=s[i][j]) break;
						l++;
					}
					if (s[i][j]=='o') chmax(bm, l);
					else chmax(wm, l);
				}
				if (bm>=5 || wm>=5) return true;
			}
		}
	}
	return false;
}

signed main() {
	rep(i,19) {
		cin >> s[i];
		rep(j,19) {
			b += s[i][j]=='o';
			w += s[i][j]=='x';
		}
	}
	// 石の数がおかしいケース
	if (b-w!=0 && b-w!=1) {
		cout << "NO" << ln;
		return 0;
	}
	// 何も置いてないケース
	if (b==0 && w==0) {
		cout << "YES" << ln;
		return 0;
	}
	// 最後に置かれたはずの石の色
	if (b==w) t = 'x';
	else t = 'o';
	// 全てのtの石を1個だけ取り除いてみて、試合終了してないパターンがあったらOK
	rep(i,19) {
		rep(j,19) {
			if (s[i][j]==t) {
				s[i][j] = '.';
				if (!fin()) {
					cout << "YES" << ln;
					return 0;
				}
				s[i][j] = t;
			}
		}
	}
	cout << "NO" << ln;
}