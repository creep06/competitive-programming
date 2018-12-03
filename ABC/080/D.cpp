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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

// ⊂ニニニニニニニニニニニニニ( ^ω^)ニニニニニニニニニニニニニ⊃

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n, c;
	cin >> n >> c;
	int imo[c][200010]={{}};
	rep(i,n) {
		int s, t, ch;
		cin >> s >> t >> ch;
		imo[ch-1][s*2-1]++, imo[ch-1][t*2]--;
	}
	
	int ans = 0;
	rep(i,200005) {
		int cnt = 0;
		rep(j,c) {
			imo[j][i+1] += imo[j][i];
			if (imo[j][i]>0) cnt++;
		}
		chmax(ans, cnt);
	}
	cout << ans ln;
}