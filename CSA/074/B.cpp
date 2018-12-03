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

// 各正方形領域を塗り潰したときに0が増える数をメモしておけば
// 1つ正方形を決め打ちしたとき他のメモのうちk*k個しか書き換えずに済む トータルでNMK^2
// 何のデータ構造を使えばいいか？セグ木だとTLEしそう
// 二次元sparseで

int h, w, k, a[222][222], b[222][222], c[222][222], z, res;
int table[10][222][10][222];

int mx(int x1, int yb, int x2, int yc) {
	int lenx=x2-x1+1;
	int kx=log2(lenx);
	int leny=yc-yb+1;
	int ky=log2(leny);
	
	//cout << kx <<' ' << ky << ' ' << x2+1-(1<<kx) << ' ' << yc+1-(1<<ky) << ln << flush;
	
	int min_R1 = max ( table[kx ][x1 ][ky ][yb ] , table[kx ][x1 ][ky ][ yc+1-(1<<ky) ] );
	int min_R2 = max ( table[kx ][x2+1-(1<<kx) ][ky ][yb ], table[kx ][x2+1-(1<<kx) ][ky ][yc+1-(1<<ky) ] );
	return max ( min_R1, min_R2 );
}

signed main() {
	cin >> h >> w >> k;
	rep(i,h) rep(j,w) cin >> a[i][j];
	rep(i,h) rep(j,w) if (a[i][j]==0) z++;
	repst(i,1,h) repst(j,1,w) b[i][j] = a[i-1][j-1] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];
	repst(i,k,h) repst(j,k,w) c[i][j] = b[i][j] - b[i-k][j] - b[i][j-k] + b[i-k][j-k];
	
	int ir, ic, jr, jc;
	for(ir=1;ir<=h;ir++)
	{
		for(ic=1;ic<=w;ic++)
		table[ 0 ][ ir ][ 0 ][ ic ] = c[ ir ][ ic ];
		
		for(jc=1;jc<=log2(w);jc++)
		for(ic=0;ic+(1<<(jc-1))<w;ic++)
		table[0 ][ir ][jc ][ic ] = max(table[0 ][ir ][jc-1 ][ic ],table[0 ][ir ][ jc-1 ][ ic+(1<<(jc-1)) ]);
	}
	
	for(jr=1;jr<=log(h);jr++)
	for(ir=0;ir<h;ir++)
	for(jc=0;jc<=log(w);jc++)
	for(ic=0;ic<w;ic++)
	table[jr ][ir ][jc ][ic ] = max(table[jr-1 ][ir ][jc ][ic ],table[jr-1 ][ir+(1<<(jr-1)) ][jc ][ic ]);
	
	repst(i,k,h) repst(j,k,w) {
			int ta = c[i][j];
			int tb = 0;
			// 上
			chmax(tb, mx(0,0, i-k,w));
			// 下
			if (i+k<=h) chmax(tb, mx(i+k,0, h,w));
			// 左
			chmax(tb, mx(0,0, h,j-k));
			// 右
			if (j+k<=w) chmax(tb, mx(0,j+k, h,w));
			cout <<ta << ' '<< tb << ln;
			// かぶってる部分
			cout << i << ' ' << j << "が右下のとき" << ln;
			repst(ii,i-k+1,i+k-1) repst(jj,j-k+1,j+k-1) {
					if (ii-k<0 || jj-k<0) continue;
					int ri = min(ii,i), rj = min(jj,j);
					int li = max(ii-k,i-k), lj = max(jj-k,j-k);
					int gen = b[ri][rj] - b[li][rj] - b[ri][lj] + b[li][lj];
					cout << ii << ' ' << jj << "で" << gen << "個かぶるから" << c[ii][jj]-gen << ln;
					chmax(tb, c[ii][jj] - gen);
				}
			chmax(res, ta+tb);
		}
	cout << res << ln;
	
	cout << res+z << ln;
}