#include <bits/stdc++.h>
using namespace std;

#define inf 1e9
#define linf 1e18
#define mod (1e9+7)
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
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
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

//--------------------------------------------------

int main() {
 
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n,m;
	cin >> n >> m;
	bool fs[n][n] = {};
	rep(i,m) {
		int a,b;
		cin >> a >> b;
		fs[a-1][b-1] = fs[b-1][a-1] = true;
	}
	
	int ans = 0;
	rep(i,1<<n) {
		int tmp = 0;
		rep(j,n) {
			// j人目を入れるか考える
			if (i>>j&1){
				repr(k,j-1) {
					// j人目とk[0,j)人目が友達じゃない場合終了
					if (i>>k&1 && !fs[j][k]) goto SKIP;
				}
				tmp++;
			}
		}
		chmax(ans, tmp);
		SKIP:;
	}
	cout << ans ln;
	
}