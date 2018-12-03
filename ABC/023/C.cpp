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

const int MAXN = 100000;
int r, c, k, n, rmax=0, cmax=0, rs[MAXN], cs[MAXN], y[MAXN], mid[MAXN];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> r >> c >> k >> n;
	rep(i,n) {
		cin >> y[i] >> mid[i];
		y[i]--, mid[i]--;
		// その行/列に存在する飴の個数
		rs[y[i]]++, cs[mid[i]]++;
		// 1つの行/列に存在する飴の個数の最大値
		chmax(rmax, rs[y[i]]);
		chmax(cmax, cs[mid[i]]);
	}
	
	// 飴の個数で行/列を分類
	int rlist[rmax+1] = {}, clist[cmax+1] = {};
	rep(i,r) rlist[rs[i]]++;
	rep(i,c) clist[cs[i]]++;
	
	ll ans = 0;
	rept(i,rmax) {
		if (k-i<0 || cmax<k-i) continue;
		ans += rlist[i] * clist[k-i];
	}
	
	// 重複チェック
	rep(i,n) {
		if (rs[y[i]]+cs[mid[i]]==k) ans--;
		else if (rs[y[i]]+cs[mid[i]]==k+1) ans++;
	}
	cout << ans ln;
}