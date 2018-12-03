#include <bits/stdc++.h>
using namespace std;

//#define int long long
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
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln

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
const double eps = 1e-10;

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

int n, nm, om;
string pre, pos;

signed main() {
	cin >> n;
	// nは99999 = 1e5、クエリは20回、2^20 = 1048576 = 1e6
	// 空席は3個,5個、と奇数個なら1個じゃないかもしれない
	// もし空席が1個だけなら、iとi+2mの席に座っている人の性別が異なれば間に空席があることがわかる！ ->わからない！
	// 空席を挟んで男女男女・・から女男女男・・に並びが変わる可能性がある そうなってた場合全く逆のことが成り立つ
	// まとめると？
	// iとjの性別が同じ	-> (j-i)が偶数	-> i-j間じゃなくi-0-j間で↓が成り立つからそっち側に必ず空席が存在する
	// 					-> (j-i)が奇数	-> 間に少なくとも1個空席がある(空席を挟まず同じグループに属するなら絶対に性別は異なるはず)
	// iとjの性別が異なる	-> (j-i)が偶数	-> 間に少なくとも1個空席がある(〃)
	// 					-> (j-i)が奇数	-> i-j間じゃなくi-0-j間で〜
	// iとjの性別がわかるとi-j間とその反対のi-0-(n-1)-j間の情報が同時に得られる
	cout << 0 << ln << flush;
	cin >> pre;
	if (pre=="Vacant") return 0;
	int l = 0, r = n;
	rep(T,18) {
		// 虱潰しにやったほうが早い場合
		if (r-l+1<=(19-T)) {
			repst(i,l,r) {
				cout << i << ln << flush;
				cin >> pos;
				if (pos=="Vacant") return 0;
			}
		}
		
		nm = (r+l)/2;
		cout << nm << ln << flush;
		cin >> pos;
		if (pos=="Vacant") return 0;
		if (pre==pos) {
			// omとnmの間に答えがある
			if (abs(om-nm)%2==1) (om==l ? r : l) = nm;
			// その反対側に答えがある
			else (om==l ? l : r) = nm;
		} else {
			// ⇡の反対
			if (abs(om-nm)%2==0) (om==l ? r : l) = nm;
			else (om==l ? l : r) = nm;
		}
		pre = pos;
		om = nm;
		// preがどっちに対応してるのか記録しないと
	}
	cout << r << ln;
	return 0;
}