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

unsigned long long a, b, c, R, C, pR[30], pC[30], gR = 1, gC = 1;

int main() {
	cin >> a >> b >> c;
	
	/*
	 * r+c = kとおくと
	 * a = kCc			= k! / c!(k-c)!
	 * b = (k+1)Cc		= (k+1)! / c!(k+1-c)!
	 * c = (k+1)C(c+1)	= (k+1)! / (c+1)!(k-c)!
	 *
	 * これらをいい感じに変形していくとCを下のC/pC[0]って形で表せることがわかる
	 * 変形はこんな感じ↓ 別にこの流れじゃなくてもとにかくK消してC=の形作ればいいだけ
	 * https://drive.google.com/open?id=1fMwjqFWHoLeyzFxbUE2Qqdg-_ph_h4Id
	 * あとはフェルマーの小定理X^-1 = X^P-2 (modP, P=1e9+7) と繰り返し2乗法でpR[0], gC[0]の逆元を求めて掛け算する
	 */
	
	R = (b*c%mod + mod - a*c%mod) % mod;
	C = (b*c%mod + mod - a*b%mod) % mod;
	pR[0] = (a*b%mod + mod - b*c%mod + a*c%mod) % mod;
	pC[0] = (a*c%mod + mod - b*c%mod + a*b%mod) % mod;
	
	// pR[k]: pR[0]を2^k乗して%=modしたもの 繰り返し2乗法
	reps(k,1,30) {
		pR[k] = (pR[k-1] * pR[k-1]) % mod;
		pC[k] = (pC[k-1] * pC[k-1]) % mod;
	}
	
	// ↑のテーブルから逆元を求める
	rep(k,30) {
		if (((mod-2)>>k)&1) {
			gR = (gR * pR[k]) % mod;
			gC = (gC * pC[k]) % mod;
		}
	}
	
	R = (R * gR) % mod;
	C = (C * gC) % mod;
	cout << R << " " << C ln;
}