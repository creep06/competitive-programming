#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define rept(i,n) for(ll (i)=0;(i)<=(ll)(n);(i)++)
#define reps(i,s,n) for(ll (i)=(s);(i)<(ll)(n);(i)++)
#define repst(i,s,n) for(ll (i)=(s);(i)<=(ll)(n);(i)++)
#define repr(i,n) for(ll (i)=(n);(i)>=0;(i)--)
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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

int tx, ty;
string s[8];
bool fin;

bool chk(int x, int y) {
	rep(i,8) {
		int xx = x + ddx[i], yy = y + ddy[i];
		while (0<=xx && xx<8 && 0<=yy && yy<8) {
			if (s[xx][yy]=='Q') return false;
			xx += ddx[i], yy += ddy[i];
		}
	}
	return true;
}

void dfs(int ex, int ey) {
	if (fin) return;
	// もうコマを置ける行/列がなくなった ∴ クイーンを8個設置し終わったら確認
	if (ex==0) {
		rep(i,8) rep(j,8) if (s[i][j]=='Q' && !chk(i,j)) return;
		rep(i,8) cout << s[i] << ln;
		fin = true;
		return;
	}
	rep(i,8) {
		rep(j,8) {
			if ((ex>>i & 1) && (ey>>j & 1)) {
				s[i][j] = 'Q';
				dfs(ex^(1<<i), ey^(1<<j));
				s[i][j] = '.';
			}
		}
	}
}

int main() {
	rep(i,8) cin >> s[i];
	// まず空いてる行と列を調べる もし最初から条件を満たしてなかったら終わり
	tx = ty = (1<<8) - 1;
	rep(i,8) {
		rep(j,8) {
			if (s[i][j]=='Q') {
				if (chk(i,j)) tx ^= 1<<i, ty ^= 1<<j;
				else {
					cout << "No Answer" << ln;
					return 0;
				}
			}
		}
	}
	dfs(tx, ty);
	if (!fin) cout << "No Answer" << ln;
}