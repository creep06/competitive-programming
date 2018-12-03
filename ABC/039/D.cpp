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

int h, w;
string s[100];

int main() {
	cin >> h >> w;
	rep(i,h) cin >> s[i];
	
	// まず.を頼りに復元してみる s[i][j]が.ならそのマスと周囲8マスも確実に.
	string mp[h] = {};
	rep(i,h) rep(j,w) mp[i] += '#';
	rep(i,h) {
		rep(j,w) {
			if (s[i][j]=='.') {
				mp[i][j] = '.';
				rep(d,8) {
					int ii = i + ddy[d], jj = j + ddx[d];
					if (0<=ii && ii<h && 0<=jj && jj<w) {
						mp[ii][jj] = '.';
					}
				}
			}
		}
	}
	
	// 復元したデータを実際に収縮してみて元に戻ったらpossible 戻らないならむり
	rep(i,h) {
		rep(j,w) {
			// mp[i][j]自身かその周囲8マスが#ならそのマスは#になる
			char t = '.';
			if (mp[i][j]=='#') t = '#';
			else {
				rep(d,8) {
					int ii = i + ddy[d], jj = j + ddx[d];
					if (0<=ii && ii<h && 0<=jj && jj<w && mp[ii][jj]=='#') {
						t = '#';
						break;
					}
				}
			}
			if (t!=s[i][j]) {
				cout << "impossible" << ln;
				return 0;
			}
		}
	}
	cout << "possible" << ln;
	rep(i,h) {
		rep(j,w) cout << mp[i][j];
		cout << ln;
	}
}