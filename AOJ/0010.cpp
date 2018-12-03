#include <bits/stdc++.h>
using namespace std;

int n;
double xa, ya, xb, yb, xc, yc, x, y, r;

signed main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> xa >> ya >> xb >> yb >> xc >> yc;
		x = ((ya-yb)*(xc*xc+yc*yc-xa*xa-ya*ya)-(ya-yc)*(xb*xb+yb*yb-xa*xa-ya*ya))/(2*((ya-yc)*(xa-xb)-(ya-yb)*(xa-xc)));
		y = ((xa-xb)*(xc*xc+yc*yc-xa*xa-ya*ya)-(xa-xc)*(xb*xb+yb*yb-xa*xa-ya*ya))/(2*((ya-yb)*(xa-xc)-(ya-yc)*(xa-xb)));
		r = sqrt((x-xa)*(x-xa)+(y-ya)*(y-ya));
		printf("%.3lf %.3lf %.3lf\n",x,y,r);
	}
}