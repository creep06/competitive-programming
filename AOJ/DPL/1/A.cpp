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

// dp[i][j]: i番目までのコインでj円を作るときのコインの枚数の最小値(組み合わせが存在しなければinf)
int N, m, c[21], dp[21][50001];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin >> N >> m;
	repst(i,1,m) cin >> c[i];
	rept(i,m) fill(dp[i], dp[i]+N+1, inf);
	dp[0][0] = 0;
	
	repst(i,1,m) {
		rept(j,N) {
			if (j<c[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = min(dp[i-1][j], dp[i][j-c[i]]+1);
		}
	}
	
	/*
	rept(i,m) {
		rept(j,N) {
			printf("%4d  ", dp[i][j]);
		}
		printf("\N");
	}
	*/
	
	cout << dp[m][N] ln;
}