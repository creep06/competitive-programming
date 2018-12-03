// dp[2][W]
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

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n, W;
	cin >> n >> W;
	int v[n], w[n];
	int dp[2][W+1];
	fill(dp[0], dp[0]+W+1, 0);
	repst(i,1,n) cin >> v[i] >> w[i];
	
	repst(i,1,n) {
		fill(dp[i&1], dp[i&1]+W+1, 0);
		rept(j,W) {
			if (j<w[i]) dp[i&1][j] = dp[~i&1][j];
			else dp[i&1][j] = max(dp[~i&1][j], dp[~i&1][j-w[i]]+v[i]);
		}
	}
	cout << dp[n&1][W] ln;
}