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

// メモ化再帰バージョン 再帰で"4も9も使わない"数字を数える
string s;
int lim;
ll a, b, A, B, dp[20][2], ok, ans;


ll dfs(int n, int def) {
	if (n==s.length()) return 1;
	ll &res = dp[n][def];
	if (res!=-1) return res;
	
	res = 0;
	lim = def ? 9 : s[n]-'0';
	rep(d,lim+1) {
		if (d!=4 && d!=9) res += dfs(n+1, def || (d<lim));
	}
	return res;
}

/*
ll dfs(int n, int f){
	if(n==s.size())return 1;
	ll &ret=dp[n][f];
	if(ret!=-1)return ret;
	ret=0;
	rep(i,10){
		if(!f&&i>s[n]-'0')continue;
		if(i==4||i==9)continue;
		ret+=dfs(n+1,f||(i<s[n]-'0'));
	}
	return ret;
}
*/
int main() {
	cin >> a >> b;
	a--;
	
	s = to_string(a);
	memset(dp, -1, sizeof(dp));
	A = dfs(0, 0);
	
	s = to_string(b);
	memset(dp, -1, sizeof(dp));
	B = dfs(0, 0);
	
	ans = b - a - (B - A);
	cout << A << ln << B << ln;
	cout << ans << ln;
}