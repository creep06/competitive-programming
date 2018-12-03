#include <utility>
#include <iostream>
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

int n, cnt[4], tmp;
char alp[4] = {'i', 'x', 'c', 'm'};

int main() {
 
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;
	rep(z,n) {
		string a,b;
		cin >> a >> b;
		fill(cnt, cnt+4, 0);
		tmp = 1;
		
		each(c, a) {
			if ('0'<=c && c<='9') tmp = c-'0';
			else if (c=='i') {
				cnt[0] += tmp;
				tmp = 1;
			} else if (c=='x') {
				cnt[1] += tmp;
				tmp = 1;
			} else if (c=='c') {
				cnt[2] += tmp;
				tmp = 1;
			} else if (c=='m') {
				cnt[3] += tmp;
				tmp = 1;
			}
		}
		
		each(c, b) {
			if ('0'<=c && c<='9') tmp = c-'0';
			else if (c=='i') {
				cnt[0] += tmp;
				tmp = 1;
			} else if (c=='x') {
				cnt[1] += tmp;
				tmp = 1;
			} else if (c=='c') {
				cnt[2] += tmp;
				tmp = 1;
			} else if (c=='m') {
				cnt[3] += tmp;
				tmp = 1;
			}
		}
		
		rep(i,4) if (cnt[i]>=10) {
			cnt[i+1]++;
			cnt[i] -= 10;
		}
		repr(i,3) {
			if (cnt[i]==0) continue;
			else if (cnt[i]>=2) cout << cnt[i];
			cout << alp[i];
		}
		cout ln;
		
	}
	
}