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

int sum;
string s;
vi p;

int main() {
	cin >> s;
	// 各'M'についてそれより右にある('+'の数) - ('-'の数)をメモしていく
	// 各'M'で右に動けばその数字だけ最終的な幸福度が増えることを意味するので、メモを昇順ソートし、
	// メモの前半の数字を左移動、後半を右移動に振り分ければ、幸福度を最大化しつつ最後は原点に戻れる
	repr(i,s.length()-1) {
		if (s[i]=='+') sum++;
		else if (s[i]=='-') sum--;
		else p.pb(sum);
	}
	sort(all(p));
	int ans = 0;
	rep(i,p.size()/2) ans -= p[i];
	reps(i,p.size()/2, p.size()) ans += p[i];
	cout << ans << ln;
}