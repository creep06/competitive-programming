#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
typedef long long ll;

ll n, n1, n2, k, l, r, a[40], res;
vector<ll> p[44];

int main() {
	scanf("%lld %lld %lld %lld",&n,&k,&l,&r);
	rep(i,n) scanf("%lld",&a[i]);
	n1 = n/2, n2 = n-n1;
	rep(i,1<<n1) {
		ll c = 0, s = 0;
		rep(j,n1) if (i>>j&1) c++, s += a[j];
		p[c].pb(s);
	}
	rep(i,k+1) sort(all(p[i]));
	rep(i,1<<n2) {
		ll c = 0, s = 0;
		rep(j,n2) if (i>>j&1) c++, s += a[n1+j];
		if (c<=k) res += upper_bound(all(p[k-c]), r-s) - lower_bound(all(p[k-c]), l-s);
	}
	printf("%lld\n",res);
}