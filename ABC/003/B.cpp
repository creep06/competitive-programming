#include <bits/stdc++.h>
using namespace std;

#define inf 1e9
#define linf 1e18
#define mod (1e9+7)
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
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

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

//--------------------------------------------------

int main() {
 
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	string s, t;
	cin >> s >> t;
	int n = s.length();
	unordered_set<char> ok = {'a', 't', 'c', 'o', 'd', 'e', 'r', '@'};
	
	rep(i, n) {
		if (s[i]!=t[i]) {
			if ((s[i]=='@' && !ok.count(t[i])) || (t[i]=='@' && !ok.count(s[i]))
				|| (s[i]!='@' && t[i]!='@')) {
				cout << "You will lose" ln;
				return 0;
			}
		}
	}
	cout << "You can win" ln;
	
}