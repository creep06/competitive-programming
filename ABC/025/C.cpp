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
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln "\n"
#define show(x) cout << #x << " = " << x ln
#define dbg(x) cout<<#x"="<<x ln

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> mat;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ⊂ニニニニニニニニニニニニニ( ^ω^)ニニニニニニニニニニニニニ⊃

int b[2][3], c[3][2], sum;
map<mat, int> memo;

void input() {
	rep(i,2)
		rep(j,3) {
			cin >> b[i][j];
			sum += b[i][j];
		}
	rep(i,3)
		rep(j,2) {
			cin >> c[i][j];
			sum += c[i][j];
		}
}

// 得点計算
int calc(mat a) {
	int res = 0;
	rep(i,2) rep(j,3) if (a[i][j]==a[i+1][j]) res += b[i][j];
	rep(i,3) rep(j,2) if (a[i][j]==a[i][j+1]) res += c[i][j];
	return res;
}

int dfs(mat a, int turn) {
	// もう置く場所がないので点数計算して終わり
	if (turn==9) return memo[a] = calc(a);
	// もうこのaの形をメモ済みだったらその値を返す
	if (memo.count(a)) return memo[a];
	
	// 直大のターン(tmp%2==0)ならスコアを最大化、直子のターンなら最小化
	int mesu = turn%2;
	int res = mesu ? inf : -1;
	// 全ての空きマス
	rep(i,3)
		rep(j,3) {
			if (a[i][j]!=-1) continue;
			mat tmp = a;
			tmp[i][j] = mesu;
			if (mesu) chmin(res, dfs(tmp, turn+1));
			else chmax(res, dfs(tmp, turn+1));
		}
	return memo[a] = res;
}

int main() {
	input();
	mat a(3, vi(3, -1));
	int ans = dfs(a, 0);
	cout << ans << ln << sum-ans << ln;
}