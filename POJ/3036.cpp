#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

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

const int hdx[] = {-1, 0, -1, 1, 0, 1};
const int hdy[] = {-1, -1, 0, 0, 1, 1};
int dp[15][15][15];

int rec(int n, int x, int y) {
	if (n==0) {
		if (x==0 && y==0) return 1;
		else return 0;
	}
	if (max(abs(x), abs(y)) > n) return 0;
	if (dp[n][7+x][7+y]>=0) return dp[n][7+x][7+y];
	
	int cnt = 0;
	rep(i,6) cnt += rec(n-1, x+hdx[i], y+hdy[i]);
	return dp[n][7+x][7+y] = cnt;
}

int tes, n;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> tes;
	memset(dp, -1, sizeof(dp));
	rep(z, tes) {
		cin >> n;
		cout << rec(n, 0, 0) ln;
	}
}