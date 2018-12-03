#include <utility>
#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>

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
typedef pair<int,int> P;
typedef pair<int,P> PP;
struct edge {
	int to,cost;
	edge(int t, int c):to(t),cost(c) {}
};

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

//--------------------------------------------------

// 素直に全列挙するとTLEになるけどランキング見ると0msの人がいるから違う解き方があるっぽい
struct fixed_string
{ size_t len;
  char s[80];
  char *begin() { return s; }
  char *end() { return s + len; }
  bool operator<(const fixed_string& that) const
  {
    return strcmp(s, that.s) < 0;
  }
};

int main() {
 
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int m;
	cin >> m;
	rep(z,m) {
		fixed_string w;
		cin >> w.s;
		w.len = strlen(w.s);
		set<fixed_string> p;
		
		reps(i,1,w.len) {
			p.insert(w);
			reverse(w.begin(), w.begin()+i);
			p.insert(w);
			reverse(w.begin()+i, w.end());
			p.insert(w);
			reverse(w.begin(), w.begin()+i);
			p.insert(w);
			reverse(w.begin(), w.end());
			p.insert(w);
			reverse(w.begin()+w.len-i, w.end());
			p.insert(w);
			reverse(w.begin(), w.begin()+w.len-i);
			p.insert(w);
			reverse(w.begin()+w.len-i, w.end());
			p.insert(w);
			reverse(w.begin(), w.end());
		}
		cout << p.size() ln;
	}
	
}