#include <bits/stdc++.h>
using namespace std;

#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto &(itr):(v))
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

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
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

ll mop(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

int n, m, a, b, c, t;

// A*B
vector<vector<int> > mul(vector<vector<int> > &A, vector<vector<int> > &B) {
	vector<vector<int> > C(A.size(), vector<int>(B[0].size()));
	for (int i=0; i<A.size(); ++i)
		for (int k=0; k<B.size(); ++k)
			for (int j=0; j<B[0].size(); ++j)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) %m;
	return C;
}

// A^n
vector<vector<int> > pow(vector<vector<int> > A, long long n) {
	vector<vector<int> > B(A.size(), vector<int>(A.size()));
	for (int i=0; i<A.size(); ++i) B[i][i] = 1;
	while (n>0) {
		if (n&1) B = mul(B,A);
		A = mul(A,A);
		n >>= 1;
	}
	return B;
}

signed main() {
	while (1) {
		cin >> n >> m >> a >> b >> c >> t;
		if (n==0) break;
		vector<vector<int> > s(n, vector<int>(1));
		rep(i,n) cin >> s[i][0];
		vector<vector<int> > A(n, vector<int>(n));
		reps(i,1,n-1) A[i][i-1] = a, A[i][i] = b, A[i][i+1] = c;
		A[0][0] = b, A[0][1] = c, A[n-1][n-2] = a, A[n-1][n-1] = b;
		A = pow(A,t), A = mul(A,s);
		rep(i,n) cout << A[i][0] << bln(i,n);
	}
}