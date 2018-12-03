#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
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

int n, k;
bool isp[1121];			// 素数ならtrue
int dp[1121][15][188];	// dp[i][j]: iをj個の互いに異なる素数の和で表すパターン数
vector<int> p;			// 1120以下の素数(187個) 昇順

void calcprime() {
	fill(isp, isp+1121, true);
	isp[0] = isp[1] = false;
	repst(i,2,sqrt(1120)) {
		if (isp[i])
			for (int j = i*2; j < 1121; j+=i) isp[j] = false;
	}
	repst(i,2,1120) if (isp[i]) p.pb(i);
}

int rec(int n, int k, int idx) {
	if (n==0 && k==0) return 1;
	if (n==0 || k==0) return 0;
	if (dp[n][k][idx]>=0) return dp[n][k][idx];
	
	int cnt = 0;
	reps(i,idx,187) {
		if (p[i]>n) break;
		else cnt += rec(n-p[i], k-1, i+1);
	}
	return dp[n][k][idx] = cnt;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	calcprime();
	memset(dp, -1, sizeof(dp));
	while (cin >> n >> k && n|k) {
		cout << rec(n, k, 0) ln;
	}
}