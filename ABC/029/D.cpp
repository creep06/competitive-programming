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

int n, dig;
// dp[i][j][k]: 上からi桁目までで1がj回出てきて、kはその数がnより小さいと確定しているかを表すbool
// k==true(1)ならその後の桁ではどんな数字を選んでもいい k==falseならまだnを超えないように気を使う必要がある
ll dp[10][10][2];
string N;

int main() {
	cin >> n;
	N = to_string(n);
	dig = (int)N.length();
	dp[0][0][0] = 1;
	rep(keta,dig) {
		rep(cnt,10) {
			rep(ok,2) {
				// keta桁目までで1がcnt回出てきてnより小さいかどうかがokに確定しているような数字が存在しない場合
				if (!dp[keta][cnt][ok]) continue;
				/*
				 * その後の数字の選び方に制限がない場合は0〜9全て、
				 * そうでない場合は0〜(今見ている桁の数字)の範囲それぞれに、
				 * 今までのパターン数を足してあげる それぞれの[]の中の意味は
				 * keta+1)		: 次の桁の個数に足す
				 * cnt+(d==1)	: 今までに現れた1の回数 今注目してる桁を1にする場合カウントが1増えるのでこう
				 * ok||d<lim	: (もうnより小さいと確定してる) or (今まではnより小さいと確定してなかったからまだ
				 * 				  その後の数字に気を使う必要があったけど、今注目してる桁をnのその桁より小さい値に
				 * 				  確定させるから、これからはnより小さいことが確定する)
				 * 				  どっちも当てはまらなければまだnより小さいと確定できないので0のまま
				 */
				int lim = ok ? 9 : N[keta]-'0';
				rept(d,lim) dp[keta+1][cnt + (d==1)][ok || d<lim] += dp[keta][cnt][ok];
			}
		}
	}
	int ans = 0;
	// 1がcnt個ある数字がdp[dig][cnt][1 or 0]個あるからそれにcntをかけた回数1が現れる
	reps(cnt,1,10) rep(ok,2) ans += cnt * dp[dig][cnt][ok];
	cout << ans << ln;
}