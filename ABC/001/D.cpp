#include <bits/stdc++.h>
using namespace std;

#define inf 1e9
#define linf 1e18
#define mod (1e9+7)
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
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

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

//--------------------------------------------------

int main() {
 
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n;
	int imo[1450] = {0};
	cin >> n;
	rep(i,n) {
		int f, t;
		scanf("%d-%d", &f, &t);
		f = f/100*60 + f%100;
		t = t/100*60 + t%100;
		f -= f%5;
		if (t%5!=0) t += 5 - t%5;
		imo[f]++;
		imo[t+1]--;
	}
	
	bool r = false;
	cout << setfill('0');
	rep(i,1445) {
		imo[i+1] += imo[i];
		if (!r && imo[i]>0) {
			printf("%02d%02d-", i/60, i%60);
			r = true;
		}
		if (r && imo[i]==0) {
			printf("%02d%02d\n", (i-1)/60, (i-1)%60);
			r = false;
		}
	}
	
}