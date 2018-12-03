#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int n;

// 素数判定
bool isprime(int n) {
	if (n==1) return false;
	for (int i = 2; i*i <= n; ++i) {
		if (n%i==0) return false;
	}
	return true;
}

// 約数列挙
vector<int> divisor(int n) {
	vector<int> res;
	for (int i = 1; i <= n; ++i) {
		if (n%i==0) {
			res.push_back(i);
			if (i!=n/i) res.push_back(n/i);
		}
	}
	return res;
}

// 素因数分解
map<int, int> primefactor(int n) {
	map<int, int> res;
	for (int i = 2; i*i <= n; i++) {
		while (n%i==0) {
			++res[i];
			n /= i;
		}
	}
	if (n!=1) res[n] = 1;
	return res;
}

// エラトステネスの篩
vector<int> ps;
bool p[101010];
void sieve(int n) {
	fill(p, p+n, true);
	p[0] = p[1] = false;
	for (int i = 2; i*i <= n; ++i) {
		if (p[i]) {
			ps.push_back(i);
			for (int j = 2*i; j <= n; j += i) p[j] = false;
		}
	}
}

int main() {
	cin >> n;
	if (isprime(n)) cout << "Yes" << endl;
	else cout << "No" << endl;
}