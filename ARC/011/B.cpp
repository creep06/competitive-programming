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

int n;
string w;
map<char,int> m;
vector<string> r;

int main() {
	m['a'] = m['i'] = m['u'] = m['e'] = m['o'] = m['y'] = m['.'] = m[','] = -1;
	m['z'] = m['r'] = 0;
	m['b'] = m['c'] = 1;
	m['d'] = m['w'] = 2;
	m['t'] = m['j'] = 3;
	m['f'] = m['q'] = 4;
	m['l'] = m['v'] = 5;
	m['s'] = m['x'] = 6;
	m['p'] = m['m'] = 7;
	m['h'] = m['k'] = 8;
	m['n'] = m['g'] = 9;
	cin >> n;
	rep(i,n) {
		cin >> w;
		string t;
		rep(j,w.length()) {
			if ('A'<=w[j] && w[j]<='Z') w[j] = w[j] - 'A' + 'a';
			if (m[w[j]]==-1) continue;
			t += to_string(m[w[j]]);
		}
		if (!t.empty()) r.pb(t);
	}
	if (r.empty()) cout << ln;
	else rep(i,r.size()) cout << r[i] << (i==r.size()-1 ? '\n' : ' ');
}