#include <bits/stdc++.h>
using namespace std;

// MLE テストセット1は通る

template<typename V> struct spa {
	private:
	vector<vector<vector<vector<V> > > > sp;
	public:
	spa(int h, int w) { sp = vector<vector<vector<vector<V> > > >(log2(h)+1, vector<vector<vector<V> > >(h, vector<vector<V> >(log2(w)+1, vector<V>(w, 1<<30))));}
	void update(int i, int j, V a) { sp[0][i][0][j] = a;}
	void build() {
		int h = sp[0].size(), w = sp[0][0][0].size(), ir, ic, jr, jc;
		for (ir=0;ir<h;ir++)
			for (jc=1;jc<=log2(w);jc++)
				for (ic=0;ic+(1<<(jc-1))<w;ic++)
					sp[0][ir][jc][ic] = min(sp[0][ir][jc-1][ic], sp[0][ir][jc-1][ic+(1<<(jc-1))]);
		for (jr=1;jr<=log2(h);jr++)
			for (ir=0;ir+(1<<(jr-1))<h;ir++)
				for (jc=0;jc<=log2(w);jc++)
					for (ic=0;ic<w;ic++)
						sp[jr][ir][jc][ic] = min(sp[jr-1][ir][jc][ic], sp[jr-1][ir+(1<<(jr-1))][jc][ic]);
	}
	V query(int xa, int ya, int xb, int yb) { // min
		int kx = log2(xb-xa+1), ky = log2(yb-ya+1);
		int min_R1 = min(sp[kx][xa][ky][ya], sp[kx][xa][ky][yb+1-(1<<ky)]);
		int min_R2 = min(sp[kx][xb+1-(1<<kx)][ky][ya], sp[kx][xb+1-(1<<kx)][ky][yb+1-(1<<ky)]);
		return min(min_R1, min_R2);
	}
};

int h, w, q, t, xa, ya, xb, yb;
spa<int> sp(1,1);

signed main() {
	while (1) {
		cin >> h >> w >> q;
		if (h==0) break;
		for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
			cin >> t;
			sp.update(i,j,t);
		}
		sp.build();
		while (q--) {
			cin >> xa >> ya >> xb >> yb;
			cout << sp.query(xa,ya,xb,yb) << endl;
		}
	}
}