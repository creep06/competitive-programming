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

int n, a, b, m, d[100], dp[100];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> a >> b >> m;
	a--, b--;
	vector<vector<int>> e(n);
	rep(i,m) {
		int f, t;
		cin >> f >> t;
		f--, t--;
		e[f].pb(t);
		e[t].pb(f);
	}
	
	fill(d, d+n, inf);
	d[a] = 0;
	dp[a] = 1;
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int p = q.front(); q.pop();
		each(i,e[p]) {
			if (d[i]==inf) {
				d[i] = d[p] + 1;
				q.push(i);
			}
			if (d[i] == d[p]+1) dp[i] = (dp[i] + dp[p])%mod;
		}
	}
	cout << dp[b] ln;
}