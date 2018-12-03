#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const int inf = 1145141919;

ll n, w[40], v[40], W, n_;
pair<ll,ll> ps[1<<20];

int main() {
	cin >> n;
	rep(i,n) cin >> w[i] >> v[i];
	
	// 前半を全列挙
	n_ = n/2;
	rep(i,1<<n_) {
		ll sw = 0, sv = 0;
		rep(j,n_) {
			if (i>>j&1) {
				sw += w[j];
				sv += v[j];
			}
		}
		ps[i] = make_pair(sw, sv);
	}
	
	// 無駄な要素を取り除く
	// 重さが増えるのに価値は増えないようなパターンを除外
	sort(ps, ps + (1<<n_));
	int m = 1;
	for (int i = 1; i < (1<<n_); ++i) {
		if (ps[m-1].second < ps[i].second) {
			ps[m++] = ps[i];
		}
	}
	
	ll res = 0;
	rep(i,1<<(n-n_)) {
		ll sw = 0, sv = 0;
		rep(j,n-n_) {
			if (i>>j&1) {
				sw += w[n_+j];
				sv += v[n_+j];
			}
		}
		if (sw<=W) {
			ll tv = (lower_bound(ps, ps+m, make_pair(W-sw, inf)) - 1) -> second;
			res = max(res, sv + tv);
		}
	}
	cout << res << endl;
}