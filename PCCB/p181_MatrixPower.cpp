#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

// A*B
vector<vector<int> > mul(vector<vector<int> > &A, vector<vector<int> > &B) {
	vector<vector<int> > C(A.size(), vector<int>(B[0].size()));
	for (int i=0; i<A.size(); ++i
		for (int j=0; j<B.size(); ++j)
			for (int k=0; k<B[0].size(); ++k)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) %mod;
	return C;
}

// A^n
vector<vector<int> > pow(vector<vector<int> > A, long long n) {
	vector<vector<int> > B(A.size(), vector<int>(A.size()));
	for (int i=0; i<A.size(); ++i) B[i][i] = 1;
	while (n>0) {
		if (n&1) B = mul(B,A);
		A = mul(A,A);
		n >>= 1;
	}
	return B;
}

int main() {
	long long n;
	cin >> n;
	vector<vector<int> > A(2, vector<int>(2));
	A[0][0] = 1; A[0][1] = 1;
	A[1][0] = 1; A[1][1] = 0;
	A = pow(A,n);
	printf("%d\n", A[1][0]);
}