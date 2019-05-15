#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <string.h>
#include <numeric>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(i,v) for(auto &(i):(v))
#define eachr(i,v) for(auto &(i)=(v).rbegin();(i)!=(v).rend();(i)++)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define ln '\n'
#define bln(i,n) (((i)==(n)-1)?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln<<flush
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ')<<flush;}}
#define zero(a) memset(a,0,sizeof(a))
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())

//typedef complex<double> P;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int> > mat;

const ll inf = (ll)1e9+10;
const ll linf = (ll)1e18+10;
const ll mod = (ll)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double eps = 1e-10;

ll mop(ll a,ll b,ll m=mod) {ll r=1;a%=m;for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r;}
bool ool(int x,int y,int h,int w) {return((x<0)||(h<=x)||(y<0)||(w<=y));}
bool deq(double a,double b) {return abs(a-b)<eps;}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;



class bigint {
private:
  static const int BASE = 100000000, LEN = 8;
  bool negative;
  std::vector<int> a;
  bigint& normalize();
public:
  bigint(int x = 0);
  bigint(const std::string& s);
  bigint& operator = (const bigint& x);
  bigint& operator = (int x);
  bigint& operator = (const std::string& s);
  const bool operator < (const bigint& x) const;
  const bool operator > (const bigint& x) const;
  const bool operator <= (const bigint& x) const;
  const bool operator >= (const bigint& x) const;
  const bool operator != (const bigint& x) const;
  const bool operator == (const bigint& x) const;
  bigint operator -() const;
  bigint& operator += (const bigint& x);
  bigint& operator -= (const bigint& x);
  bigint& operator *= (const bigint& x);
  bigint& operator /= (const bigint& x);
  bigint& operator %= (const bigint& x);
  const bigint operator + (const bigint& x) const;
  const bigint operator - (const bigint& x) const;
  const bigint operator * (const bigint& x) const;
  const bigint operator / (const bigint& x) const;
  const bigint operator % (const bigint& x) const;
  friend std::pair<bigint,bigint> divmod(const bigint& lhs, const bigint& rhs);
  friend std::istream& operator >> (std::ostream& is, bigint& x); //適当実装
  friend std::ostream& operator << (std::ostream& os, const bigint& x);
  friend const bigint abs(bigint x);
};
bigint& bigint::normalize() {
  int i = a.size()-1;
  while (i >= 0 && a[i] == 0) --i;
  a.resize(i+1);
  if (a.size() == 0) negative = false;
  return *this;
}
bigint::bigint(int x) : negative(x<0) {
  x = abs(x);
  for (; x > 0; x /= BASE) a.push_back(x % BASE);
}
bigint::bigint(const std::string& s): negative(false) {
  int p = 0;
  if (s[p] == '-') { ++p; negative = true; }
  else if (s[p] == '+') { ++p; }
  for (int i = s.size()-1, v = BASE; i >= p; --i, v*=10) {
    int x = s[i]-'0';
    if (x < 0 || 9 < x) {
      std::cerr<<"error: parse error:"<<s<<std::endl;
      exit(1);
    }
    if (v == BASE) {
      v = 1;
      a.push_back(x);
    } else a.back() += (x)*v;
  }
  normalize();
}
bigint& bigint::operator = (const bigint& x) {
  negative = x.negative;
  a = x.a;
  return *this;
}
bigint& bigint::operator = (int x) { return *this = bigint(x); }
bigint& bigint::operator = (const std::string& s) { return *this = bigint(s); }
const bool bigint::operator < (const bigint& x) const {
  if (negative != x.negative) return negative < x.negative;
  if (a.size() != x.a.size()) return (a.size() < x.a.size())^negative;
  for(int i = a.size()-1; i >= 0; --i)
    if (a[i] != x.a[i]) return (a[i] < x.a[i])^negative;
  return false;
}
const bool bigint::operator > (const bigint& x) const { return x<(*this); }
const bool bigint::operator <= (const bigint& x) const { return !(x<(*this)); }
const bool bigint::operator >= (const bigint& x) const { return !((*this)<x); }
const bool bigint::operator != (const bigint& x) const { return (*this)<x || x<(*this); }
const bool bigint::operator == (const bigint& x) const { return !((*this)<x || x<(*this)); }
bigint bigint::operator -() const {
  bigint ret(*this);
  if (a.size()) ret.negative = !ret.negative;
  return ret;
}
bigint& bigint::operator += (const bigint& x) {
  if (negative != x.negative) return *this -= -x;
  if (a.size() < x.a.size()) a.resize(x.a.size());
  int tmp = 0;
  for (int i = 0; i < a.size(); ++i) {
    a[i] += (i<x.a.size()?x.a[i]:0) + tmp;
    tmp = a[i] / BASE;
    a[i] %= BASE;
  }
  if (tmp) a.push_back(1);
  return *this;
}
bigint& bigint::operator -= (const bigint& x) {
  if (negative != x.negative) return *this += -x;
  std::vector<int> b(x.a);
  if ((*this < x) ^ negative) {
    a.swap(b);
    negative = !negative;
  }
  for (int i = 0, tmp = 0; i < a.size(); ++i) {
    a[i] += BASE - (i<b.size()?b[i]:0) + tmp;
    tmp = a[i] / BASE - 1;
    a[i] %= BASE;
  }
  return this->normalize();
}
bigint& bigint::operator *= (const bigint& x) {
  negative ^= x.negative;
  std::vector<int> c(a.size()*x.a.size()+1);
  for (int i = 0; i < a.size(); ++i) {
    long long tmp = 0;
    for (int j = 0; j < x.a.size(); ++j) {
      long long v = (long long)a[i] * x.a[j] + c[i+j] + tmp;
      tmp = v / BASE;
      c[i+j] = (int)(v % BASE);
    }
    if (tmp) c[i+x.a.size()] += (int)tmp;
  }
  a.swap(c);
  return this->normalize();
}
bigint& bigint::operator /= (const bigint& x) {
  return *this = divmod(*this,x).first;
}
bigint& bigint::operator %= (const bigint& x) {
  return *this = divmod(*this,x).second;
}
const bigint bigint::operator + (const bigint& x) const {
  bigint res(*this); return res += x;
}
const bigint bigint::operator - (const bigint& x) const {
  bigint res(*this); return res -= x;
}
const bigint bigint::operator * (const bigint& x) const {
  bigint res(*this); return res *= x;
}
const bigint bigint::operator / (const bigint& x) const {
  bigint res(*this); return res /= x;
}
const bigint bigint::operator % (const bigint& x) const {
  bigint res(*this); return res %= x;
}
std::pair<bigint,bigint> divmod(const bigint& lhs, const bigint& rhs) {
  if (!rhs.a.size()) {
    std::cerr<<"error: division by zero"<<std::endl;
    exit(1);
  }
  bigint x(abs(rhs)), q, r;
  for (int i = lhs.a.size()-1; i >= 0; --i) {
    r = r * bigint::BASE + lhs.a[i];
    int head = 0, tail = bigint::BASE;
    if (r >= x) {
      while (head + 1 < tail) {
        int mid = (head + tail) / 2;
        if (x * bigint(mid) > r) tail = mid;
        else head = mid;
      }
      r -= x * head;
    }
    q.a.push_back(head);
  }
  reverse(q.a.begin(), q.a.end());
  bool neg = lhs.negative ^ lhs.negative;
  q.negative = neg; r.negative = neg;
  return std::make_pair(q.normalize(), r.normalize());
}
std::istream& operator >> (std::istream& is, bigint& x) {
  std::string tmp; is >> tmp;
  x = bigint(tmp);
  return is;
}
std::ostream& operator << (std::ostream& os, const bigint& x) {
  if (x.negative) os << '-';
  if (!x.a.size()) os << 0;
  else os << x.a.back();
  for (int i = x.a.size()-2; i >= 0; --i) {
    os.width(bigint::LEN);
    os.fill('0');
    os << x.a[i];
  }
  return os;
}
const bigint abs(bigint x) {
  x.negative = false;
  return x;
}

int Q, m;
bigint n;

bigint gcd(bigint a, bigint b) {
	if (b==0) return a;
	return gcd(b, a%b);
}

signed main() {
	cin >> Q;
	reps(q,1,Q+1) {
		cout << "Case #" << q << ": ";
		cin >> n >> m;
		bigint a[111] = {};
		rep(i,m) cin >> a[i];
		set<bigint> s;
		bigint res[111] = {};
		rep(i,m-1) if (a[i]!=a[i+1]) res[i+1] = gcd(a[i], a[i+1]), s.insert(res[i+1]);
		rep(t,30) rep(i,m) each(j,s) if (a[i]%j==0) s.insert(a[i]/j);
		
		char c = 'A';
		map<bigint,char> con;
		each(i,s) con[i] = c++;

	}
}
