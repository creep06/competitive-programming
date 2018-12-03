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

string s;
int x, y;
bool dp[4000][16001], dp2[4000][16001];	// i番目まででj-8000を作れるか

int main() {
	cin >> s >> x >> y;
	
	int cnt = 0;
	vi xf, yf;
	int tur = 0;
	rep(i,s.length()) {
		if (s[i]=='F') {
			cnt++;
		}
		else {
			if (!tur) xf.pb(cnt);
			else yf.pb(cnt);
			cnt = 0;
			tur = 1 - tur;
		}
	}
	if (!tur) xf.pb(cnt);
	else yf.pb(cnt);
	// iが偶数なら左右、奇数なら上下 一度も動かない場合は考慮しなくていい
	// 偶数の一番最初の1要素だけは右向き指定だった
	
	// evの要素を足し引きしてxに、odを足し引きしてyにできればいい
	// 最高で2000通りずつある どうする？ dp 間に合うか怪しい
	int N = xf.size(), M = yf.size();
	dp[1][8000+xf[0]] = true;
	for (int i = 1; i < N; ++i) {
		rep(j,16001) {
			if (dp[i][j]) {
				//cout << j-8000 << "がOKなので" << j-8000+xf[i] << "もいける" << ln;
				dp[i+1][j+xf[i]] = true;
				dp[i+1][j-xf[i]] = true;
			}
		}
	}
	
	dp2[0][8000] = true;
	for (int i = 0; i < M; ++i) {
		rep(j,16001) {
			if (dp2[i][j]) {
				//cout << j-8000 << "がOKなので" << j-8000+yf[i] << "もいける" << ln;
				dp2[i+1][j+yf[i]] = true;
				dp2[i+1][j-yf[i]] = true;
			}
		}
	}
	if (dp[N][x+8000] && dp2[M][y+8000]) cout << "Yes" << ln;
	else cout << "No" << ln;
	
	/*
	rep(i,N) cout << xf[i] << " ";
	cout << ln;
	rep(i,M) cout << yf[i] << " ";
	cout << ln;
	 */
}