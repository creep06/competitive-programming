#include <bits/stdc++.h>
int n, r;
double xa, ya, ra, xb, yb, rb, d;

int main() {
	scanf("%d",&n);
	while (n--) {
		scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
		d = sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
		if (d+ra<rb) r = -2;
		else if (d+rb<ra) r = 2;
		else if (d>ra+rb) r = 0;
		else r = 1;
		printf("%d\n",r);
	}
}