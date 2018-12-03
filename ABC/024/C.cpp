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

int n, d, k, l[10000], r[10000], s[100], t[100];

int main() {
	cin >> n >> d >> k;
	rep(i,d) cin >> l[i] >> r[i];
	rep(i,k) cin >> s[i] >> t[i];
	
	rep(i,k) {
		int now = s[i];
		rep(j,d) {
			if (now<l[j] || r[j]<now) continue;
			// 行き先が今の場所より右の場合
			if (now<t[i]) {
				// ゴールに行けるなら終了して、行けないなら目一杯右に移動する
				if (t[i]<=r[j]) {
					cout << j+1 ln;
					break;
				} else {
					now = r[j];
				}
			} else {
				if (l[j]<=t[i]) {
					cout << j+1 ln;
					break;
				} else {
					now = l[j];
				}
			}
		}
	}
}