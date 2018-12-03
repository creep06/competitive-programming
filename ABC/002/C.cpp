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
	
	double x,y,a,b,c,d;
	cin >> x >> y >> a >> b >> c >> d;
	a -= x;
	c -= x;
	b -= y;
	d -= y;
	double ans = abs(a*d-b*c)/2.0;
	printf("%f\n", ans);
	
}