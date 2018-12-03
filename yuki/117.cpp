#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;

int t;
char c[100];
ll n, k, f[2002002];

ll mpow(ll x, ll n = mod-2, ll m = mod) {
	ll res = 1;
	while (n>0) {
		if (n&1) res = res * x %m;
		x = x * x %m;
		n >>= 1;
	}
	return res;
}

ll comb(ll n, ll k) {
	if (n==-1 && k==0) return 1;
	if (n<k) return 0;
	return f[n] * mpow(f[k]) %mod * mpow(f[n-k]) %mod;
}

int main() {
	f[0] = 1;
	for (ll i = 1; i <= 2000000; ++i) f[i] = f[i-1]*i %mod;
	scanf("%d", &t);
	while (t--) {
		scanf("%1s(%lld,%lld)", c, &n, &k);
		cout << c << ' ' << n << ' ' << k << endl;
		if (c[0]=='C') cout << comb(n,k) << endl;
		else if (c[0]=='P') cout << comb(n,k) * f[k] %mod << endl;
		else cout << comb(n+k-1,k) << endl;
	}
}