#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define ln '\n'
typedef long long ll;

ll n, v, a[1000], b[1000], c[1000], d[1000], ps[1000000], r;

int main() {
	cin >> n >> v;
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&b[i]);
	rep(i,n) scanf("%lld",&c[i]);
	rep(i,n) scanf("%lld",&d[i]);
	rep(i,n) rep(j,n) ps[i*n+j] = a[i] + b[j];
	sort(ps, ps+n*n);
	rep(i,n) rep(j,n) {
		ll t = c[i] + d[j];
		if (t<v) r += upper_bound(ps, ps+n*n, v-t) - lower_bound(ps, ps+n*n, v-t);
	}
	printf("%lld\n",r);
}