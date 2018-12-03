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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ⊂ニニニニニニニニニニニニニ( ^ω^)ニニニニニニニニニニニニニ⊃

int n;
ll low, high, mid, height, h[100000], s[100000];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	rep(i,n) cin >> h[i] >> s[i];
	
	// 風船iが高さXまで昇るのにかかる時間は(X-H[i])/S[i]秒
	// この制限時間が厳しいものから順に貪欲に撃ち落として、
	// 全ての風船の"撃ち落としたときの高度"の最大値がX以下なら高さXはクリアできる
	// Xを最初は適当に決めてから二分探索で洗練していけば答えが求められる
	
	low = 0;
	high = (ll)1e15;
	pll sor[n];
	while (high - low > 1) {
		//cout << low << " - " << high ln;
		mid = (high + low) / 2;
		// 上で言った制限時間でソート
		rep(i,n) sor[i] = mp((mid-h[i])/s[i], i);
		sort(sor, sor+n);
		// 順番に撃ち落としていき高度の最大値を記録
		height = 0;
		rep(i,n) chmax(height, h[sor[i].se] + s[sor[i].se] * i);
		if (height <= mid) high = mid;
		else low = mid;
	}
	cout << high ln;
}