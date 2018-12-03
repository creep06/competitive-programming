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

int n, w, h, x, y, s, t, ans, tmp;
int map[100][100];

int main() {
 
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	while (true) {
		
		cin >> n;
		if (n==0) break;
		cin >> w >> h;
		rep(i,w) rep(j,h) map[i][j] = 0;
		rep(i,n) {
			cin >> x >> y;
			map[x-1][y-1] = 1;
		}
		cin >> s >> t;
		
		ans = 0;
		rept(xx,w-s) {
			rept(yy,h-t) {
				tmp = 0;
				reps(x,xx,xx+s) {
					reps(y,yy,yy+t) {
						tmp += map[x][y];
					}
				}
				chmax(ans, tmp);
			}
		}
		cout << ans ln;
		
	}
	
}