#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <string.h>
#include <numeric>
using namespace std;

#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(i,v) for(auto &(i):(v))
#define eachr(i,v) for(auto &(i)=(v).rbegin();(i)!=(v).rend();(i)++)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define bln(i,n) (((i)==(n)-1)?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln<<flush
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ')<<flush;}}
#define zero(a) memset(a,0,sizeof(a))
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())

//typedef complex<double> P;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int> > mat;

const ll inf = (ll)1e9+10;
const ll linf = (ll)1e18+10;
const ll mod = (ll)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double eps = 1e-10;

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m;for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
bool ool(int x,int y,int h,int w) {return((x<0)||(h<=x)||(y<0)||(w<=y));}
bool deq(double a,double b) {return abs(a-b)<eps;}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;



// お互いが交互に取っていく段階の前に青木がひたすら上の方を取りまくる段階がある
// この段階で青木が何枚取るかはO(1〜logN)で計算できそう？
// ↑青木と高橋が逆
// 二分探索でできそう
// k枚取ると仮定するとまず手前のk枚は消して、その中で一番小さい値をMとする
// 残ったカードのみで青木がk枚取れればok、無理ならng
// Mより1個小さい値とxの間に
//
// やっぱ「x以上のカードが全部なくなるまでのターン数」を求めることにする
//
// 後は1個飛ばしの累積和とっとけばO(1)
//
// 1個目は愚直にもとめてあとxを減らしながら↑のターン数をちょっとずつ増やして更新していけばニブタンも要らないのでは？
// しゃくとり的な

int n, q, a[100100], res[100100], sum[100100], sum0[100100], k = 1, base;
pair<int,int> x[100100];
bool t[100100];

signed main() {
	cin >> n >> q;
	rep(i,n) cin >> a[i];
	sort(a,a+n);
	rep(i,n) {
		sum[i] += a[i], sum[i+1] += sum[i];
		sum0[i] += a[i], sum0[i+2] += sum0[i];
	}
	rep(i,q) {
		cin >> x[i].first;
		x[i].second = i;
	}
	sort(x,x+q), reverse(x,x+q);
//	reps(j,1,100100) {
//		// 高橋
//		if (t[ta]) break;
//		k = j;
//		t[ta] = 1;
//		// 青木
//		if (l<0) {
//			if (t[r]) break;
//			else {
//				t[r++] = 1;
//				continue;
//			}
//		} else if (t[r]) {
//			t[l--] = 1;
//			continue;
//		}
//		int xd = abs(tx-a[l]), yd = abs(tx-a[r]);
//		if (xd<=yd) t[l--] = 1;
//		else t[r++] = 1;
//	}

	// 2人が奪い合うことになるまでにkターンかかることは確定 もっとかかる可能性もある
	// 最後に高橋が取ったカードの値(M)よりxから遠いカードを青木が2枚以上取ることになったら矛盾してる
	// 小さい方を優先して取るってのが引っかかってる？矛盾条件で
	// 例えば34 678でx=5のときk=3はngだけど↓だとアリになっちゃう
	// 矛盾条件がちょっと違うっぽい
	// k=2で完全にくっつく場合はそこで中断するようにすればいい？
	// 完全にくっつく判定がムズイ?
	rep(i,q) {
		reps(j,k+1,100100) {
			if (j>(n+1)/2) break;
			int m = a[n-j], md = abs(x[i].first-m);
			int xd = abs(x[i].first-a[max(n-j*2,0ll)]), yd = abs(x[i].first-a[max(n-j*2,0ll)+1]);
			if (xd>md && yd>md) break;
			k = j;
			int zd = abs(x[i].first-a[n-j-1]), ad = abs(x[i].first-a[max(n-j*2-1,0ll)]);
			if (ad>zd) break;
		}
		//cout << i << ' ' << k << endl;
		res[x[i].second] = sum[n-1] - (k==n ? 0 : sum[n-k-1]) + (k*2==n ? 0 : sum0[n-k*2-1]);
	}
	rep(i,q) cout << res[i] << endl;
}
