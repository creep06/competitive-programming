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

// ⊂ニニニニニニニニニニニニニ( ^ω^)ニニニニニニニニニニニニニ⊃

// t[k][i]: i本目の縦線からスタートして2^k回あみだくじを通るとto[k][i]本目の縦線に辿り着く
int n, m, d, a[100000], t[30][100000];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> m >> d;
	rep(i,m) {
		cin >> a[i];
		a[i]--;
	}
	
	// Dの下からi番目のビットが立っていれば2^i回阿弥陀を通る
	// 例えばD=27(11011)なら 2^4 + 2^3 + 2^1 + 2^0 回阿弥陀を通るので
	// T[4][ T[3][ T[1][ T[0][i] ] ] ]でi番目の縦線がどこに辿り着くかわかる

	// ダブリングのテーブルを作る
	rep(i,n) t[0][i] = i;
	repr(i,m-1) swap(t[0][a[i]], t[0][a[i]+1]);
	rep(k,29) {
		rep(i,n) {
			t[k+1][i] = t[k][t[k][i]];
		}
	}
	
	rep(i,n) {
		int ans = i;
		for (int k = 0; (d>>k) > 0; ++k) {
			if ((d>>k)&1) ans = t[k][ans];
		}
		cout << ans+1 ln;
	}
}