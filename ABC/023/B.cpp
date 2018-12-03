#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rept(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
#define repst(i,s,n) for(int (i)=(s);(i)<=(int)(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define each(itr,v) for(auto (itr):(v))
#define all(c) c.begin(),c.end()
#define pb push_back
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln << "\n"
#define show(x) cout << #x << " = " << x ln
#define dbg(x) cout<<#x"="<<x ln

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> PP;
struct edge {
	int to,cost;
	edge(int t, int c):to(t),cost(c) {}
};

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

//--------------------------------------------------

int n, cnt = 0;
string s;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> s;
	int c = n/2;
	if (n%2==0 || s[c]!='b') goto end;
	repst(i, 1, n/2) {
		cnt++;
		if (i%3==1) {
			if (s[c - i] != 'a' || s[c + i] != 'c') goto end;
		} else if (i%3==2) {
			if (s[c - i] != 'c' || s[c + i] != 'a') goto end;
		} else if (s[c-i]!='b' || s[c+i]!='b') goto end;
	}
	
	cout << cnt ln;
	return 0;
	
	end: cout << -1 ln;
}