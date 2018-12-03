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
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define bln(i,n) (((i)==(n)-1)?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln<<flush
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ')<<flush;}}
#define zero(a) memset(a,0,sizeof(a))
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())

typedef complex<double> P;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
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

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m;for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}
bool ool(int x,int y,int h,int w) {return((x<0)||(h<=x)||(y<0)||(w<=y));}
bool deq(double a,double b) {return abs(a-b)<eps;}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// ex2だとまず先頭1文字だけを見るとb<aが確定
// 上2つはokだけど下2つでprefixの条件を破ってるからダメ
// こんな感じで条件を全部列挙して矛盾があったらno
// ex4の条件は b<c(1個目と2個目より) と c<b(3個目と4個目) で矛盾してるからダメ
// a<bならa->bに辺をつなげるとかして出来たグラフに閉路があれば矛盾してるとわかる

int n;
string s[500];
vi e[26];
bool vis[26], hei;

void rec(int v, int p) {
	vis[v] = 1;
	rep(i,e[v].size()) {
		if (e[v][i]==p) hei = 1;
		else if (!vis[e[v][i]]) rec(e[v][i],p);
	}
}

signed main() {
	while (1) {
		cin >> n;
		if (n==0) break;
		rep(i,26) e[i].clear();
		bool dame = 0;
		rep(i,n) {
			cin >> s[i];
			rep(j,i) if (s[j].size()>s[i].size() && s[j].substr(0,s[i].size())==s[i]) dame = 1; // prefix
		}
		if (dame) {
			cout << "no" << ln;
			continue;
		}
		// 条件追加
		rep(i,n) reps(j,i+1,n) {
			if (s[j].size()>=s[i].size() && s[j].substr(0,s[i].size())==s[i]) continue; // prefix
			rep(k,min(s[i].size(),s[j].size())) if (s[i][k]!=s[j][k]) {
				e[s[i][k]-'a'].pb(s[j][k]-'a');
				break;
			}
		}
		// 閉路検出
		hei = 0;
		rep(i,26) zero(vis), rec(i,i);
		cout << (hei ? "no" : "yes") << ln;
	}
}