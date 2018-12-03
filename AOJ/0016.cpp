#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

double d, a, x, y, p;

int main() {
	while (scanf("%lf,%lf",&d,&a) && (d || a)) {
		y += d * cos(p / 180.0 * M_PI);
		x += d * sin(p / 180.0 * M_PI);
		p += a;
	}
	printf("%d\n%d\n", (int)x, (int)y);
}