#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

// xのn乗のmod mを二分累乗でO(logn)で求める
ll mpow(ll x, ll n, ll m) {
	ll res = 1;
	while (n>0) {
		if (n&1) res = res * x %m;
		x = x * x %m;
		n >>= 1;
	}
	return res;
}

ll n;

int main() {
	cin >> n;
	cout << mpow(3, n, 1145141919) << endl;
}