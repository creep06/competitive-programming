#include <bits/stdc++.h>
using namespace std;

int n, k, r, PAS[777][777];

int comb(int n, int r) {
	if (r<0 || r>n) return 0;
	else if (r==0) return 1;
	else if (PAS[n][r]) return PAS[n][r];
	else return PAS[n][r] = (comb(n-1, r-1) + comb(n-1, r))%((int)1e9+7);
}

int main() {
	cin >> n >> k;
	if (n<=k) r = comb(n, k%n);
	else r = comb(n+k-1, k);
	cout << r << '\n';
}