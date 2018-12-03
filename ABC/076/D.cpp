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
typedef vector<vector<int> > mat;
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

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

int n, t[111], v[111];

int main() {
	cin >> n;
	cin >> t[0];
	reps(i,1,n) {
		cin >> t[i];
		t[i] += t[i-1];
	}
	rep(i,n) cin >> v[i];
	// 考えやすいように制限速度0のn番目の点を設置
	v[n] = 0;
	
	// 0.5秒刻みでシミュレート (1秒じゃなく0.5秒なのは入力例4みたいに奇数秒の区域の真ん中で速度が変わるパターンがあるから)
	// 各t[i]では速度をv[i]にしないといけないっていう制約がn個ある
	// 各iでそれより右にある全ての点の制約を守る範囲でなるべく加速したい
	
	// x座標が現在地以上で最も現在地に近い点の番号
	int ct = 0;
	// 答え、i秒目に出せる最高の速度、i-0.5秒目に出した速度
	double ans = 0, cv = 0, pre = 0;
	for (double i = 0.5; i <= t[n-1]; i += 0.5) {
		// 0.5秒で加速できる最大値 とりあえずこれだけ加速すると仮定しといて下の条件チェックで狭めていく
		cv += 0.5;
		// 点ctを追い越したら次は点ct+1を目指す
		if (t[ct]<i) ct++;
		// 満たさないといけない条件を全て確認
		// v[j+1]: j番目の点にたどり着いた瞬間次の制限速度がこれになる ∴ 時刻t[j]までにこの速度以下になってないといけない
		// t[j]-i: 今からj番目の点に辿り着くまでにかかる時間
		// 点jの制約はiがこれらの和以下であるってこと
		// 仮に今これらの和の速度を出すとすると、今後0.5秒ごとに0.5ずつ減速すればちょうど時刻t[j]に速度がv[j+1]になるとも言える
		// 点j全てから傾き-1の直線を引いて、直線x=iと交わる点それぞれのy座標がこれに対応する たぶん 思い出したら図書いて確認したい
		// 交点の中で一番y座標小さい点が今出せる速度の上限
		reps(j,ct,n) chmin(cv, v[j+1]+t[j]-i);
		// ⇡で次の点以降の速度制限については考えた 今いる範囲の速度制限もチェック
		chmin(cv, 1.*v[ct]);
		// 直前の速度を上底、今の速度を下底とする台形の面積を答えに+
		ans += 0.25 * (pre + cv);
		pre = cv;
	}
	printf("%.6lf\n", ans);
}