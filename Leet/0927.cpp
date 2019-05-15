#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <string.h>
#include <numeric>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(i,v) for(auto &(i):(v))
#define eachr(i,v) for(auto &(i)=(v).rbegin();(i)!=(v).rend();(i)++)
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

//typedef complex<double> P;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
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

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m;for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
bool ool(int x,int y,int h,int w) {return((x<0)||(h<=x)||(y<0)||(w<=y));}
bool deq(double a,double b) {return abs(a-b)<eps;}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;



class Solution {
public:
	// 文字列SとS[i,|S|-1]の最長共通接頭辞の長さの配列をO(|S|)で構築
	vector<int> zal(const string &s) {
		int n = s.size();
		vector<int> a(n);
		a[0] = n;
		int i = 1, j = 0;
		while (i<n) {
			while (i+j<n && s[j]==s[i+j]) ++j;
			a[i] = j;
			if (j==0) {++i; continue;}
			int k = 1;
			while (i+k<n && k+a[k]<j) a[i+k] =a[k], ++k;
			i += k, j -= k;
		}
		return a;
	}

    vector<int> threeEqualParts(vector<int>& a) {
		string s;
		int lz = 0;
		bool ok = 0;
		each(i,a) {
			if (!ok) {
				if (i==0) lz++;
				else ok = 1;
			}
			if (ok) s.push_back(i==0 ? '0' : '1');
		}
		if (s.empty()) {
			vector<int> res;
			res.push_back(0), res.push_back(2);
			return res;
		}
		int n = s.size(), resl = -1, resr = -1, c0[30030] = {};
		rep(i,30030) c0[i] = 1<<30;
		repr(i,n-1) {
			chmin(c0[i], c0[i+1]);
			if (s[i]=='1') c0[i] = i;
		}
		vector<int> z = zal(s);

		reps(i,1,n) {
			int id = c0[i];
			if (id==(1<<30)) continue;
			int len = z[id];
			if (len<i) continue;
			int id2 = c0[id+i];
			if (id2==(1<<30)) continue;
			if (z[id2]==i && i==n-id2) resl = i-1, resr = id+i;
		}
		vector<int> res;
		if (resl==-1) res.push_back(-1), res.push_back(-1);
		else res.push_back(resl+lz), res.push_back(resr+lz);
		return res;
    }
};
