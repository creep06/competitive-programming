#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i);(i)<n;(i)++)

int n, m, a[50];

int main() {
	cin >> n >> m;
	rep(i,n) cin >> a[i];
	rep(i,n) rep(j,n) rep(k,n) rep(l,n) {
		if (a[i]+a[j]+a[k]+a[l]==m) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}