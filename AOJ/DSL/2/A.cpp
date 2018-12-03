#include <bits/stdc++.h>
using namespace std;

// RMQ<int> rmq(114514);
template<typename V> struct RMQ {
	private:
	int n;
	vector<V> node;
	public:
	RMQ(int sz) {
		n=1;while(n<sz)n*=2;
		node.resize(2*n-1,(1<<31)-1);
	}
	void update(int x, V val) {
		x+=n-1,node[x]=val;
		while(x>0) x=(x-1)/2,node[x]=min(node[2*x+1],node[2*x+2]);
	}
	V q(int a, int b, int k=0, int l=0, int r=-1) {
		if(r<0) r=n;
		if(r<=a||b<=l) return INT_MAX;
		if(a<=l&&r<=b) return node[k];
		return min(q(a,b,2*k+1,l,(l+r)/2),q(a,b,2*k+2,(l+r)/2,r));
	}
};

int n, q, a, b, c;
RMQ<int> rmq(114514);

int main() {
	cin >> n >> q;
	while (q--) {
		cin >> a >> b >> c;
		if (a==0) rmq.update(b,c);
		else cout << rmq.q(b,c+1) << endl;
	}
}