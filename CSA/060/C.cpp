#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rept(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
#define repst(i,s,n) for(int (i)=(s);(i)<=(int)(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
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

int n, k, mn, t;

int main() {
	cin >> n >> k >> mn;
	// 0〜k-1の数字のみで構成されたm桁の数字がn個ある
	// size==Kの順列pを求める 条件↓
	// 全ての数字のd桁目をp[d]に置き換えた時、一つの数字も先頭に0を含まず,
	// 数字たちの列が完全な単調増加になるような順列pを1個求める(なければ-1を出力)
	
	// ギチギチに詰めるやり方でやる
	int ans[k];
	fill(ans, ans+k, inf);
	bool used0 = false;
	bool used1 = false;
	int to = 1;
	rep(i,n) {
		rep(j,mn) {
			cin >> t;
			
		}
	}
}