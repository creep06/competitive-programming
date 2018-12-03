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

int k, n, l[50], s[50];
string v[50], w[50];
bool owari;

bool chek() {
	rep(i,n) {
		int sum = 0;
		// 今仮定してるsの長さを当てはめてみる
		rep(j,v[i].length()) {
			sum += s[v[i][j]-'1'];
		}
		// 矛盾するvがあったらダメ
		if (sum!=l[i]) return false;
	}
	return true;
}

void enu(int ii, int kk) {
	if (owari) return;
	s[ii] = kk;
	// もし長さの組み合わせがこれでOKなら与えられたデータを元に答えを生成して終了フラグを立てる
	if (ii==k-1) {
		if (!chek()) return;
		string ans[k];
		rep(i,n) {
			int left = 0;
			rep(j,v[i].length()) {
				int idx = v[i][j] - '1';
				ans[idx] = w[i].substr(left, s[idx]);
				left += s[idx];
			}
		}
		rep(i,k) cout << ans[i] << ln;
		owari = true;
		return;
	}
	repst(i,1,3) enu(ii+1,i);
}

int main() {
	cin >> k >> n;
	rep(i,n) {
		cin >> v[i] >> w[i];
		l[i] = (int)w[i].length();
	}
	
	// s[i]の長さの組み合わせを全通り(最大2*10^4弱)試す
	// 長さが決まってれば与えられたテーブルから答えを出せる どっかで矛盾したらcontinue
	repst(i,1,3) enu(0,i);
}