#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(ll (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,n+1)
#define repst(i,s,n) reps(i,s,n+1)
#define reprt(i,n,t) for(ll (i)=(n);(i)>=t;--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto (itr):(v))
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
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<n;++i){cout<<x[i]<<(i==n-1?'\n':' ');}}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
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

int h, w, d, k, m[200][200], y[16000], x[16000];
int mitudo[205][205];

int mxx, mxy;

pii nearmaxemp() {
	int x = mxx, y = mxy;
	if (m[x][y]==0) return {x,y};
	// 隣接4マスをとりあえず確認
	rep(i,4) {
		int xx = x+dx[i], yy = y+dy[i];
		if (0<=xx && xx<w && 0<=yy && yy<h && m[xx][yy]==0) return {xx,yy};
	}
	reps(s,1,200) {
		// 上下
		repst(xx,x-s,x+s) {
			if (xx<0 || w<=xx) continue;
			if (y+s<h && m[xx][y+s]==0) return {xx,y+s};
			if (y-s>=0 && m[xx][y-s]==0) return {xx,y-s};
		}
		// 左右
		repst(yy,y-s,y+s) {
			if (yy<0 || w<=yy) continue;
			if (x+s<w && m[x+s][yy]==0) return {x+s,yy};
			if (x-s>=0 && m[x-s][yy]==0) return {x-s,yy};
		}
	}
	return {inf,inf};
}

pii nearemp(int x, int y) {
	if (m[x][y]==0) return {x,y};
	reps(s,1,200) {
		// 上下
		repst(xx,x-s,x+s) {
			if (xx<0 || w<=xx) continue;
			if (y+s<h && m[xx][y+s]==0) return {xx,y+s};
			if (y-s>=0 && m[xx][y-s]==0) return {xx,y-s};
		}
		// 左右
		repst(yy,y-s,y+s) {
			if (yy<0 || w<=yy) continue;
			if (x+s<w && m[x+s][yy]==0) return {x+s,yy};
			if (x-s>=0 && m[x-s][yy]==0) return {x-s,yy};
		}
	}
	return {inf,inf};
}

// i番目をi-1番目のマスに一番近い空マスに移動させていく貪欲
// 点が偏って密集してたらそっちに寄せたほうがいいから改良の余地がある
// かなり雑な密度は累積和で求められる？

signed main() {
	cin >> h >> w >> d >> k;
	rep(i,d) {
		cin >> x[i] >> y[i];
		m[x[i]][y[i]] = i+1;
		mitudo[x[i]][y[i]]++;
	}
	
	// 雑な密度計算 密集してるとこに寄せるようにしてみる
	rep(i,200) rep(j,200) mitudo[j+1][i] += mitudo[j][i];
	rep(i,200) rep(j,200) mitudo[i][j+1] += mitudo[i][j];
	int tate = h/3+1, yoko = w/3+1, mxwa = 0;
	// 左上(j,i)から右上(j+yoko-1, i+tate-1)まで
	rept(i,h-tate) rept(j,w-yoko) {
			int tmp = mitudo[j+yoko-1][i+tate-1];
			if (j>0) tmp -= mitudo[j-1][i+tate-1];
			if (i>0) tmp -= mitudo[j+yoko-1][i-1];
			if (i>0 && j>0) tmp += mitudo[j-1][i-1];
			if (tmp>mxwa) mxwa = tmp, mxx = j, mxy = i;
		}
	// この範囲に含まれてないdを優先的にこの周辺に移動させたほうが良い
	
	// 初期型 手前に寄せる貪欲
	reps(i,1,min(k+1,d)) {
		pii tmp = nearemp(x[i-1],y[i-1]);
		if (tmp.fi==inf) break;
		cout << x[i] << ' ' << y[i] << ' ';
		cout << tmp.fi << ' ' << tmp.se << ln;
		m[x[i]][y[i]] = 0;
		x[i] = tmp.fi, y[i] = tmp.se;
		m[x[i]][y[i]] = i;
	}
	
	/*
	// 密度が高そうなところに寄せる貪欲
	rep(i,min(k,d)) {
		pii tmp = nearmaxemp();
		if (tmp.fi==inf) break;
		cout << x[i] << ' ' << y[i] << ' ' << tmp.fi << ' ' << tmp.se << ln;
		m[x[i]][y[i]] = 0, m[tmp.fi][tmp.se] = i+1;
	}
	*/
}