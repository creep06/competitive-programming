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

int n;

int main() {
	cin >> n;
	pll a[n];
	rep(i,n) {
		ll tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		a[i] = mp(tmp1, tmp2);
	}
	
	int nn = n/2;
	map<ll, ll> bef;
	// 下のtmp1は左の合計-右の合計 っていう差分 左の合計の方がtmp1だけ大きい
	for (ll i = 0; i < (1<<nn); ++i) {
		ll tmp1=0;
		rep(j,nn) {
			if ((i>>j)&1) tmp1 -= a[j].se;
			else tmp1 += a[j].fi;
		}
		bef.insert(mp(tmp1, i));
	}
	// 0がred(左)で1がblue右
	
	// ↑で前半分の組み合わせを全列挙したので二分探索で-tmp1を探す 存在すれば枚数の差で答えを更新
	int nokori = n-nn;
	ll ans = 0;
	int dif = inf;
	for (int i = 0; i < (1<<nokori); ++i) {
		ll tmp1=0;
		rep(j,nn) {
			if ((i>>j)&1) tmp1 -= a[j].fi;
			else tmp1 += a[j].se;
		}
		auto itr = bef.lower_bound(-tmp1);
		if (itr!=bef.end() &&  itr->fi+tmp1==0) {
			int tdif = n - __builtin_popcountll(itr->se) - __builtin_popcountll(i);
			if (tdif<dif) {
				dif = tdif;
				ans = (itr->se<<nn)|i;
			}
		}
	}
	if (dif==inf) cout << -1 << ln;
	else {
		rep(i,n) {
			int a = (int)((ans>>i)&1);
			cout << a;
		}
		cout << ln;
	}
}