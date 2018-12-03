#include <bits/stdc++.h>
using namespace std;

const int mod = 1000003;
long long n[26];
string s;

// 0 0 0 1 1 0 0 1 0 0 0 3 0 0 2 0 0 1 0 0 0 0 1 0 0 0 <- helloworld
// 0 0 0 1 1 0 0 1 0 0 0 2 0 0 1 0 0 1 0 0 0 0 1 0 0 0 <- helworld 4
// 0 0 0 0 1 0 0 1 0 0 0 2 0 0 1 0 0 0 0 0 0 0 0 0 0 0 <- he"ll"o 6

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	for (int i = 0; i < 26; ++i) cin >> n[i];
	cin >> s;
}