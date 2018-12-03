#include <utility>
#include <iostream>
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
 
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	// 100万以下の素数
	bool p[1000000] = {};
	fill(p, p+1000000, true);
	p[0] = p[1] = false;
	reps(i,2,1000) {
		if (p[i])
			for (int j = 2*i; j <= 1000000; j+=i) p[j] = false;
	}
	
	int a, d, n;
	while (cin >> a >> d >> n && (a|d|n)) {
		int cnt = 0;
		while (true) {
			if (p[a]) cnt++;
			if (cnt==n) {
				cout << a ln;
				break;
			}
			a += d;
		}
	}
	
}