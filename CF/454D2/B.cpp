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

int x, y;
string s[3][3][3];

int main() {
	// s[i][j][k][l]: i行j列のフィールドのk行l列目
	rep(i,3) rep(k,3) rep(j,3) cin >> s[i][j][k];
	cin >> x >> y;
	x--, y--;
	/*
	// oならどこにでも置けるので塗りつぶすだけ
	if (s[x/3][y/3][x%3][y%3]=='o') {
		rep(i,3) rep(j,3) rep(k,3) rep(l,3) if (s[i][j][k][l]=='.') s[i][j][k][l] = '!';
	}
	// xなら対応するフィールドの空きマス全てを塗る
	else {*/
		bool e = false;
		rep(i,3) rep(j,3) if (s[x%3][y%3][i][j]=='.') {
					s[x%3][y%3][i][j] = '!';
					e = true;
				}
		// 空きますがなければ全てのマスを塗りつぶす
		if (!e) {
			rep(i,3) rep(j,3) rep(k,3) rep(l,3) if (s[i][j][k][l]=='.') s[i][j][k][l] = '!';
		}
	//}
	rep(i,3) {
		rep(k,3) {
			rep(j,3) {
				cout << s[i][j][k] << " ";
			}
			cout << ln;
		}
		cout << ln;
	}
}