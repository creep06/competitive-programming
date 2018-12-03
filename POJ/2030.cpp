#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdio>
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

int w, h;
char m[71][71];
string dp[71][71];

string maxs(string &a, string &b) {
	if (a.size()>b.size()) return a;
	else if (a.size()<b.size()) return b;
	
	size_t l = a.size();
	for (size_t i = 0; i < l; ++i) {
		if (a[i] > b[i]) return a;
		else if (a[i] < b[i]) return b;
	}
	return a;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	// 右下から左上へmax(右のマス, 下のマス)で埋めていく
	// 別に左上から右下へ埋めていってもよかった
	while (cin >> w >> h && (w|h)) {
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> m[i][j];
				if (m[i][j]<'0' || '9'<m[i][j]) m[i][j] = '.';
			}
		}
		for (int i = 0; i < h; ++i) fill(dp[i], dp[i]+w, "");
		for (int i = h-1; i >= 0; --i) {
			for (int j = w-1; j >= 0; --j) {
				if (m[i][j]=='.') continue;
				dp[i][j] += m[i][j];
				// 右も下も数字マスの場合 大きい方を採用
				if (i+1<h && j+1<w && m[i+1][j]!='.' && m[i][j+1]!='.')
					dp[i][j] += maxs(dp[i+1][j], dp[i][j+1]);
				// 下だけ数字マスの場合
				else if (i+1<h && m[i+1][j]!='.')
					dp[i][j] += dp[i+1][j];
				// 右だけ数字マスの場合
				else if (j+1<w && m[i][j+1]!='.')
					dp[i][j] += dp[i][j+1];
			}
		}
		string ans = "";
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				while (!dp[i][j].empty() && dp[i][j][0]=='0') dp[i][j].erase(dp[i][j].begin());
				ans = maxs(ans, dp[i][j]);
			}
		}
		cout << ans ln;
	}
}