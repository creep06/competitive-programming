#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rept(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
#define repst(i,s,n) for(int (i)=(s);(i)<=(int)(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define each(itr,v) for(auto (itr):(v))
#define all(c) c.begin(),c.end()
#define pb push_back
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln << "\n"
#define show(x) cout << #x << " = " << x ln
#define dbg(x) cout<<#x"="<<x ln

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> PP;
struct edge {
	int to,cost;
	edge(int t, int c):to(t),cost(c) {}
};

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

//--------------------------------------------------

int n, j, dp[2][200010];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> j;
	int a[n];
	rep(i,n) cin >> a[i];
	sort(a, a+n);
	
	// dp[i][j]: aのi番目まででxorがjになる組み合わせの個数
	dp[0][0] = 1;
	// i-1までのxorの組み合わせで取りうる最大の値
	int lim = 0;
	
	rep(i,n) {
		rept(j,lim) {
			dp[1][j] = (dp[1][j] + dp[0][j]) % mod;
			dp[1][j^a[i]] = (dp[1][j^a[i]] + dp[0][j]) % mod;
		}
		lim |= a[i];
		rept(j,lim) swap(dp[0][j], dp[1][j]);
		fill(dp[1], dp[1]+lim+1, 0);
	}
	
	cout << dp[0][j] ln;
}