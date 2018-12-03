#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int n, m, k, a[200];

void rif() {
	int b[2*n];
	rep(i,n) b[i*2] = a[i];
	rep(i,n) b[i*2+1] = a[n+i];
	rep(i,2*n) a[i] = b[i];
}

void cut(int k) {
	int b[2*n];
	int z = 2*n - k;
	rep(i,z) b[i] = a[k+i];
	for (int i = z; i < 2*n; ++i) b[i] = a[i-z];
	rep(i,2*n) a[i] = b[i];
}

int main() {
	scanf("%d %d",&n,&m);
	rep(i,2*n) a[i] = i+1;
	rep(i,m) {
		scanf("%d",&k);
		if (k) cut(k);
		else rif();
	}
	rep(i,2*n) printf("%d\n",a[i]);
}