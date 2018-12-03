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

// f[i]		i番目のサプリの種類
// dp[i]	i番目までのサプリを食う組み合わせの個数
// S[i]		Σdp[k] (k=0..i)
// used[i]	しゃくとりの範囲にi種類目のサプリが含まれているかどうか
int n, m, f[100000], dp[100001], S[100001];
bool used[100001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> m;
	rep(i,n) cin >> f[i];
	dp[0] = 1;
	S[0] = 1;
	int k = -1;
	
	rep(i,n) {
		// f[i]が既に使用済みのサプリだった場合前回のそのサプリまで始点を進める
		// その途中で通った点(サプリ)も全て使用済みリストから除外していく
		if (used[f[i]]) {
			while (f[++k] != f[i]) used[f[k]] = false;
		}
		used[f[i]] = true;
		
		if (k==-1) dp[i+1] = S[i];
		else dp[i+1] = (S[i] + mod - S[k]) % mod;
		S[i+1] = (S[i] + dp[i+1]) % mod;
	}
	
	cout << dp[n] ln;
	rept(i,n) cout << dp[i] << "  ";
}