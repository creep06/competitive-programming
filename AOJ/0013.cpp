#include <bits/stdc++.h>
using namespace std;

int a;
stack<int> s;

int main() {
	while (scanf("%d",&a) != EOF) {
		if (a==0) {
			printf("%d\n",s.top());
			s.pop();
		}
		else s.push(a);
	}
}