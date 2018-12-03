#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(ll)(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) reps(i,0,((n)+1))
#define repst(i,s,n) reps(i,s,((n)+1))
#define reprt(i,n,t) for(ll (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vld;
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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// 現在のSの部分集合S'全てから max( max(S')-mean(S') ) を見つけて出力
// S'がn要素のとき、Sから小さい順にn-1個選んだ和をp、最大値をqとすると
// max(S')-mean(S') = q-(p+q)/n = q(n-1)/n - p/n
// とqについての1次式になる よってSに要素を追加する度に1次式x*(n-1)/n - p/nを追加し、xに対する最大値を求められるようにする

template<typename V> struct cht {
	deque<pair<V,V>> Q;
	int cmptype=0; // 0-max 1-min
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		return cmptype^((B.second-C.second)*(B.first-A.first)<=(A.second-B.second)*(C.first-B.first));
	}
	void add(V a, V b) { // add ax+b
		Q.push_back({a,b});
		int v;
		while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
			Q[v-2]=Q[v-1], Q.pop_back();
	}
	void add(vector<pair<V,V>> v) {
		sort(v.begin(),v.end());
		if(cmptype==1) reverse(v.begin(),v.end());
		for(auto r=v.begin();r!=v.end();r++) add(r->first,r->second);
	}
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			(cmptype^((calc(Q[M],x)<=calc(Q[M+1],x)))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};

cht<double> ch;
int Q, q, x, n;
ll s;

signed main() {
	cin >> Q;
	while (Q--) {
		cin >> q;
		if (q==1) {
			cin >> x;
			if (n) ch.add(n/(n+1.0), -1.*s/(n+1));
			n++;
			s += x;
		} else {
			if (n==1) printf("0\n");
			else printf("%.14lf\n",ch.query(x));
		}
	}
}