#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define rept(i,n) for(ll (i)=0;(i)<=(ll)(n);(i)++)
#define reps(i,s,n) for(ll (i)=(s);(i)<(ll)(n);(i)++)
#define repst(i,s,n) for(ll (i)=(s);(i)<=(ll)(n);(i)++)
#define repr(i,n) for(ll (i)=(n);(i)>=0;(i)--)
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

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

ll n, r;
// 安全とわかりきった文字、危険かもしれない文字
bool safe[26], dang[26], def;
string s, w;

int main() {
	cin >> n;
	fill(dang, dang+26, true);
	rep(i,n-1) {
		cin >> s >> w;
		// .wのwのアルファベットは全て安全
		if (s==".") {
			rep(j,w.length()) {
				safe[w[j]-'a'] = true;
				dang[w[j]-'a'] = false;
			}
		}
		// !wのwのアルファベット以外は全て安全なことがわかる
		else if (s=="!") {
			// 危険ワードが確定してるならもう得る情報はなく明らかにショック損
			if (def) {
				r++;
				continue;
			}
			// そうでない場合は得られる情報を得る
			bool al[26] = {};
			rep(j,w.length()) {
				al[w[j]-'a'] = true;
			}
			rep(j,26) {
				if (!al[j]) {
					safe[j] = true;
					dang[j] = false;
				} else {
					if (!safe[j]) {
						dang[j] = true;
						//cout << j << "番目のアルファベットは危険かもしれない" << ln;
					}
				}
			}
		}
		// 最後の質問以外の全ての質問は間違ってるって保証されてるので答えが確定してる場合は確実に無駄な質問をしてることになる
		else {
			r += def;
			// この質問で更に狭まる可能性もある
			dang[w[0]-'a'] = false;
			safe[w[0]-'a'] = true;
		}
		if (!def && accumulate(dang, dang+26, 0)==1) def = true;
		//cout << i+1 << "番目のクエリ終了時点でr=" << r << ln;
	}
	cout << r << ln;
}