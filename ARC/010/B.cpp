#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rept(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(int)(n);(i)++)
#define repst(i,s,n) for(int (i)=(s);(i)<=(int)(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define each(itr,v) for(auto (itr):(v))
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define dbg(x) cout<<#x" = "<<(x)<<ln

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > mat;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
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

bool isvacation[366];

int MandD_Day(int m,int d,bool uruu){
	int cnt[12]={31,28+uruu,31,30,31,30,31,31,30,31,30,31};
	int ret=0;
	for(int i=0;i<m-1;i++)ret+=cnt[i];
	return ret+d;
}

int main(){
	for(int i=0;i<366;i++) isvacation[i] = false;
	for(int i=0;i<366;i+=7){
		if(i)isvacation[i-1]=true;
		isvacation[i]=true;
	}
	int n;
	cin>>n;
	rep(i,n) {
		int a,b;char z;
		cin>>a>>z>>b;
		int tmp=MandD_Day(a,b,true)-1;
		while(true){
			if(!isvacation[tmp]){
				isvacation[tmp]=true;
				break;
			}
			tmp++;
			if(tmp==366)break;
		}
	}
	int ans=0,cnt=0;
	for(int i=0;i<366;i++){
		if(isvacation[i]){
			cnt++;
		}
		else{
			ans=max(ans,cnt);
			cnt=0;
		}
	}
	ans = max(ans,cnt);
	cout<<ans<<endl;
	return 0;
}