#include <bits/stdc++.h>
int n;
double v, y;

int main() {
	while (scanf("%lf",&v) != EOF) {
		y = v * v / 19.6;
		n = ceil((y+5)/5);
		printf("%d\n",n);
	}
}