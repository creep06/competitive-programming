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

// odd-odd / odd-even / even-odd / even-even
int n, x, y, pr=0, cnt[4];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		if (x%2==0) {
			if (y%2==0) cnt[3]++;
			else cnt[2]++;
		}
		else {
			if (y%2==0) cnt[1]++;
			else cnt[0]++;
		}
	}
	
	for (int i : cnt) pr += i /2;
	if (pr%2==0) cout << "Bob" ln;
	else cout << "Alice" ln;
}