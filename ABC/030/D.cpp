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
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln "\n"
#define show(x) cout << #x << " = " << x ln
#define dbg(x) cout<<#x"="<<x ln

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> mat;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ⊂ニニニニニニニニニニニニニ( ^ω^)ニニニニニニニニニニニニニ⊃

int n, a, b[100000];
bool u[100000];
vi l;
string k;

int main() {
	cin >> n >> a >> k;
	a--;
	u[a] = true;
	l.pb(a);
	rep(i,n) {
		cin >> b[i];
		b[i]--;
	}
	
	// k<10^6なら閉路とか周期を考えるまでもなくシミュレートする
	// ここに引っかからなかった場合は必ずn <= 10^5 < kなので閉路に到達する
	if (k.length()<=6) {
		int kk = stoi(k);
		rep(i,kk) a = b[a];
		cout << a+1 <<ln;
		return 0;
	}
	
	// 閉路の長さcycと閉路に突入するまでの長さpreをシミュレートで求める
	// lに通った点を順番に詰めて行き、uでその数字が過去に出てきたかをチェックする
	// u[a]がtrueになってたら"lの最初にaが現れるインデックス(l[pre])からlの末尾(l[pre+cyc-1])まで"が閉路1周を表す
	int cyc = 0;
	while (true) {
		a = b[a];
		cyc++;
		if (u[a]) break;
		u[a] = true;
		l.pb(a);
 	}
	int pre = 0;
	rep(i,l.size()) {
		if (l[i]==a) {
			cyc -= i;
			pre = i;
			break;
		}
	}
	/* デバッグ
	rep(i,pre) cout << l[i]+1 << " ";
	cout << "という" << pre << "個の前置きの後、" << pre << "ステップ目から周期" << cyc << "で" << ln;
	rep(i,cyc) cout << l[pre+i]+1 << " ";
	cout << "\nを繰り返す" << ln;
	*/
	
	// kのmodはkを(kのL-1桁目まで)*10 + (kのL桁目)と分離したときのそれぞれのmodの和と変わらないことを利用
	// これを一番大きい桁から繰り返すテクニック
	int kmodc = 0;
	rep(i,k.length()) kmodc = (kmodc*10 + (k[i]-'0'))%cyc;
	while (kmodc<pre) kmodc += cyc;
	kmodc = (kmodc-pre)%cyc;
	cout << l[pre+kmodc]+1 << ln;
}