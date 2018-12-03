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

int n, k, m[100001], mr[100001];

ll modPow(ll x, ll y) {
	if (y==0) return 1;
	else if (y==1) return x;
	else if (y%2==0) {
		ll z = modPow(x, y/2);
		return (z*z)%mod;
	}
	else return (modPow(x, y-1)*x)%mod;
}

ll nCk(int n, int k) {
	ll a = 1, b = 1;
	for (int i = 0; i < k; ++i) a = (a*(n-i))%mod;
	for (int i = k; i >= 2; --i) b = (b*i)%mod;
	return (a*modPow(b, mod-2)%mod)%mod;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> k;
	cout << nCk(n+k-1, k) ln;
}