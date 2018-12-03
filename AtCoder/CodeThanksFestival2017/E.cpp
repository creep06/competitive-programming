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

int n, c[50], j;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;
	int need = (int)ceil((double)n/5);
	int till = 0;
	repst(i,1,need) {
		printf("%d", n);
		cout << "? ";
		rep(j,min(n,till)) {
			cout << "0";
			if (j!=n) cout << " ";
		}
		reps(j,till,min(n,till+5)) {
			int am = j%5;
			cout << (int)pow(10,am);
			if (j!=n) cout << " ";
		}
		reps(j,till+5,n) {
			cout << "0";
			if (j!=n) cout << " ";
		}
		cout ln << flush;
		
		cin >> j;
		rep(i,5) {
			int fk = j%10;
			if (fk==9) {
				c[till+i] = 1;
				j = (j-9)/10;
			} else if (fk==1) {
				c[till+i] = 1;
				j = (j-11)/10;
			} else if (fk==8) j = (j-8)/10;
			else if (fk==0) j = (j-10)/10;
			else if (fk==2) j = (j-12)/10;
		}
		till += 5;
	}
	
	cout << "! ";
	rep(i,n-1) cout << c[i] << " ";
	cout << c[n-1] ln;
	
}