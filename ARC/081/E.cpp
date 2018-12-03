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

// sの後ろから見ていき、"アルファベット26種全てを含む最短のsuffix"を見つける度に切り取っていく(vi segに追加していく)
// segのサイズがkになったとすると、k文字以下の文字列は明らかに全てsの部分列
// k+1文字だと例えば最後に残った文字列s'に含まれていない文字を先頭に、各segの先頭1文字ずつ採用していって出来る文字列は部分列じゃない
// つまり求める文字列の長さはk+1なのは確定
// まず先頭の1文字はs'に含まれていない文字のうち辞書順最小のアルファベットが最善 その文字をlsとする
// seg1の範囲が[l,r)だとして、その中で初めてlsが現れる位置をi(l<i<r)とすると、
// (i,r)に含まれない文字のうち辞書順最小のアルファベットを採用してそれをlsにする これを繰り返せばいい
// a/cbadefghijklmnopqrstuvwxyz

string s, t;
int a[26], c;
vi seg;
char ls;

void wr() {
	rep(i,26) {
		if (a[i]==0) {
			ls = 'a'+i;
			cout << ls;
			break;
		}
	}
}

signed main() {
	scanf("%s",s);
	cin >> s;
	seg.pb(s.length());
	repr(i,s.length()-1) {
		a[s[i]-'a']++;
		if (a[s[i]-'a']==1) c++;
		if (c==26) {
			seg.pb(i);
			memset(a,0,sizeof(a));
			c = 0;
		}
	}
	wr();
	reprt(i,seg.size()-1,1) {
		int l = seg[i], r = seg[i-1];
		reps(j,l,r) {
			if (s[j]==ls) {
				l = j;
				break;
			}
		}
		memset(a,0,sizeof(a));
		reps(j,l+1,r) a[s[j]-'a']++;
		wr();
	}
	cout << ln;
}