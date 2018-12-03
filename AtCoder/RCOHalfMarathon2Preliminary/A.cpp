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

int n, k, h, w, t;
string s[100][50], com = "UDLR";
int sx[100], sy[100];

std::random_device rnd;
std::mt19937 mt(rnd());

// 乱数でコマンドを生成するだけのメソッド
string make_commands(int num) {
	std::uniform_int_distribution<> rands(0,3);
	string res, com = "UDLR";
	rep(i,num) {
		int tmp = rands(mt);
		res.pb(com[tmp]);
	}
	return res;
}

// num番目のマップで一番点数を稼げるコマンドを作る
// (そのマスに到達するまでに回収したoの数, その最短距離)で更新していくと6*10^5？
string makecom(int num) {
	string res;
	queue<pair<int,pii>> q;
	// とりあえず⇡を求める
	int d[h][w][h*w+1];
	rep(i,h) rep(j,w) rept(k,h*w) d[i][j][k] = inf;
	d[sy[num]][sx[num]][0] = 0;
	q.push({0,{sx[num],sy[num]}});
}

map<char,int> hen;
bool used[50][50];

// num番目のマップでコマンドcomを入力したときの点数
int point(int num, const string &com) {
	memset(used,0, sizeof(used));
	used[sy[num]][sx[num]] = true;
	int x = sx[num], y = sy[num];
	int res = 0;
	rep(i,t) {
		int xx = x + dx[hen[com[i]]], yy = y + dy[hen[com[i]]];
		if (s[num][yy][xx]=='#') continue;
		if (s[num][yy][xx]=='x') break;
		if (s[num][yy][xx]=='o' && !used[yy][xx]) res++, used[yy][xx] = true;
		x = xx, y = yy;
	}
	return res;
}

signed main() {
	cin >> n >> k >> h >> w >> t;
	rep(i,n) rep(j,h) {
			cin >> s[i][j];
			rep(k,w) if (s[i][j][k]=='@') sx[i] = k, sy[i] = j;
		}
	hen['U'] = 0, hen['R'] = 1, hen['D'] = 2, hen['L'] = 3;
	// 乱数で生成したコマンドで全マップ試し、点数を降順にk個足したとき一番高くなるコマンドを探す
	string coms[114514];
	int maxsum = 0, maxi = 0;
	int anss[k] = {};
	rep(j,10000) {
		coms[j] = make_commands(t);
		vpii pnts(n);
		rep(i,n) pnts[i] = {point(i,coms[j]), i};
		sort(pnts.rbegin(), pnts.rend());
		int tmpsum = 0;
		rep(i,k) tmpsum += pnts[i].fi;
		if (maxsum<tmpsum) {
			maxsum = tmpsum, maxi = j;
			rep(i,k) anss[i] = pnts[i].se;
			
			//rep(i,k) cout << anss[i] << ' ';
			//cout << ln;
			//cout << coms[j] << ln;
			//cout << tmpsum << ln;
		}
	}
	sort(anss, anss+k);
	rep(i,k) cout << anss[i] << (i==k-1 ? '\n' : ' ');
	cout << coms[maxi] << ln;
	// 各マップで最善のコマンドを作って各コマンドを全マップで試してそれぞれで点数の降順でk個の和が一番高いコマンドを採用？
	// 最善のコマンドってどうやって作るの？
	// とりあえず0番目のマップで最善のコマンドを作って、
	// 1〜n番目のマップ全てでそのコマンドを入力したときの点数を列挙して降順にk個選んでみる方針で
	//string command = makecom(0);
	
}