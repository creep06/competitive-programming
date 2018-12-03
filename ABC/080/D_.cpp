#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef long long int lli;

template<class T>bool chmax(T &a, const T &b) { if( a < b ) { a = b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if( b < a ) { a = b; return 1; } return 0;}

#ifdef LOCAL
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...) 1
#endif

#define ROUNDUP(a, b) 		( ((a) + ((b) - 1) ) / b)
#define SET_ZERO(a)	 		( memset((a), 0, sizeof(a)))
#define SET_NUM_ARRAY(a,b)	( memset((a), b, sizeof(a)))

const int N_MAX = 1010*101;

int count32bit(unsigned int v) {
	unsigned int count = (v & 0x55555555) + ((v >> 1) & 0x55555555);
	count = (count & 0x33333333) + ((count >> 2) & 0x33333333);
	count = (count & 0x0f0f0f0f) + ((count >> 4) & 0x0f0f0f0f);
	count = (count & 0x00ff00ff) + ((count >> 8) & 0x00ff00ff);
	return (count & 0x0000ffff) + ((count >> 16) & 0x0000ffff);
}

int main() {
	int N, C;
	scanf("%d %d", &N, &C);
	unsigned int time[(N_MAX+1)*2];
	SET_ZERO(time);
	for (int i = 0; i < N; i++) {
		int s, t, c;
		scanf("%d %d %d", &s, &t, &c);
		time[s*2-1] |= 1 << (c-1);
		time[t*2] |= 1 << (c-1);
	}
	
	int max = 0;
	unsigned int state = 0;
	for (int i = 0; i < (N_MAX+1)*2; i++) {
		state = state ^ time[i];
		chmax(max, count32bit(state));
	}
	printf("%d\n", max);
	return 0;
}