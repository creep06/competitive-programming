#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
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

/*
int k;
string s, t;

bool all9(const string &s) {
	rep(i,k) if (s[i]!='9') return false;
	return true;
}

string p1(const string &s) {
	string res = s;
	repr(i,k-1) {
		if (t[i]=='9') t[i] = '0';
		else {
			t[i] += 1;
			return t;
		}
	}
}

string square(const string &s) {
	int c[2222] = {};
	reverse(all(s));
	rep(i,s.length()) rep(j,s.length()) c[i+j] += (s[i]-'0')*(s[j]-'0');
	rep(i,2020) {
		c[i+1] += c[i]/10;
		c[i] %= 10;
	}
	string res;
	bool st = false;
	repr(i,2020) {
		if (c[i]) st = true;
		if (st) res += '0'+c[i];
	}
	return res;
}

signed main() {
	cin >> s;
	k = s.length();
	// 全桁9のときだけ特別扱い
	if (all9) {
		if (k&1) {
			rep(i,k-1) cout << 9;
			cout << 81 << ln;
		} else cout << s << ln;
		return 0;
	}
	// t = s+1を作る
	t = p1(s);
	// 2乗する
	s = square(s), t = square(t);
	// s <= √n < t より s^2 <= n < t^2
	//
}
*/

boost::multiprecision::cpp_int a, b;

signed main() {
	cin >> a;
	b = a+1;
	a = a*a, b = b*b - 1;
	while ((a+99)/100 <= b/100) {
		a = (a+99)/100;
		b = b/100;
	}
	cout << a << ln;
}