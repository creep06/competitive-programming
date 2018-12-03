#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto &(itr):(v))
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
#define bln(i,n) (i==n-1?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ');}}

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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

// 開始位置がA内のものについて、開始位置がB内の文字全てについてのLCPの最大値がPだとすると、

struct SuffixArray {
	int N; vector<int> rank,lcp,sa,rsa; string S;
	SuffixArray(string S) : S(S){
		int i,h=0; vector<int> tmp;
		N = S.size(); rank.resize(N+1); sa.resize(N+1); tmp.resize(N+1);
		for (i = 0; i < N+1; ++i) sa[i] = i, rank[i] = (i==N ? -1 : S[i]);
		for (int k = 1; k <= N; k<<=1) {
			auto pred2 = [k,this](int& a, int &b)->bool{ return (((a+k<=N) ? rank[a+k] : -1) < ((b+k<=N) ? rank[b+k] : -1));};
			auto pred = [pred2,k,this](int& a, int &b)->bool{ return (rank[a]!=rank[b]) ? (rank[a] < rank[b]) : pred2(a,b);};
			int x = 0;
			if (k!=1) for (i = 1; i < N+1; ++i) if (rank[sa[i]]!=rank[sa[x]]) sort(sa.begin()+x,sa.begin()+i,pred2), x = i;
			sort(sa.begin()+x,sa.end(),pred);
			for (i = 0; i < N+1; ++i) tmp[sa[i]] = (i==0 ? 0 : tmp[sa[i-1]] + pred(sa[i-1],sa[i]));
			swap(rank,tmp);
		}
		lcp.resize(N+1); rsa.resize(N+1);
		for (i = 0; i < N+1; ++i) rsa[sa[i]] = i;
		for (i = 0; i < N; ++i) {
			int j = sa[rsa[i]-1];
			for(h = max(h-1,0); i+h < N && j+h < N; h++) if (S[j+h]!=S[i+h]) break;
			lcp[rsa[i]-1] = h;
		}
	}
};

string a, b, s;
int na, nb, smb[200200];
ll ans;

signed main() {
	cin >> a >> b;
	na = a.size(), nb = b.size();
	s = a + "$" + b;
	SuffixArray sf(s);
	
	int pre = 0;
	repst(i,1,na+nb+1) {
		if (sf.sa[i]>na) pre = na+nb+1 - sf.sa[i];
		else chmin(pre,sf.lcp[i-1]), smb[i] = max(pre,sf.lcp[i-1]);
	}
	pre = 0;
	reprt(i,na+nb+1,1) {
		if (sf.sa[i]>na) pre = na+nb+1 - sf.sa[i];
		else {
			chmin(pre,sf.lcp[i]);
			chmax(smb[i],pre);
			ans += na - sf.sa[i] - smb[i];
		}
	}
	cout << ans << ln;
}