// what is matter? never mind.
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long
#define ull unsigned long long
//#define int __int128
#define int long long
using namespace std;
inline int read() {
	char c=getchar();
	int x=0;
	bool f=0;
	for(; !isdigit(c); c=getchar())f^=!(c^45);
	for(; isdigit(c); c=getchar())x=(x<<1)+(x<<3)+(c^48);
	if(f)x=-x;
	return x;
}

#define mod 998244353
struct modint {
	int x;
	modint(int o=0) {
		x=o;
	}
	modint &operator = (int o) {
		return x=o,*this;
	}
	modint &operator +=(modint o) {
		return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;
	}
	modint &operator -=(modint o) {
		return x=x-o.x<0?x-o.x+mod:x-o.x,*this;
	}
	modint &operator *=(modint o) {
		return x=1ll*x*o.x%mod,*this;
	}
	modint &operator ^=(int b) {
		modint a=*this,c=1;
		for(; b; b>>=1,a*=a)if(b&1)c*=a;
		return x=c.x,*this;
	}
	modint &operator /=(modint o) {
		return *this *=o^=mod-2;
	}
	friend modint operator +(modint a,modint b) {
		return a+=b;
	}
	friend modint operator -(modint a,modint b) {
		return a-=b;
	}
	friend modint operator *(modint a,modint b) {
		return a*=b;
	}
	friend modint operator /(modint a,modint b) {
		return a/=b;
	}
	friend modint operator ^(modint a,int b) {
		return a^=b;
	}
	friend bool operator ==(modint a,int b) {
		return a.x==b;
	}
	friend bool operator !=(modint a,int b) {
		return a.x!=b;
	}
	bool operator ! () {
		return !x;
	}
	modint operator - () {
		return x?mod-x:0;
	}
	bool operator <(const modint&b)const {
		return x<b.x;
	}
};
inline modint qpow(modint x,int y) {
	return x^y;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 1000005
#define inf 0x3f3f3f3f

int n,m,V;
int a[maxn],b[maxn],a2[maxn],b2[maxn];
int c[maxn];

struct bit {
	vector<int>tr;
	int n;
	void init(int N) {
		n=N,tr=vector<int>(N+1,0);
	}
	void add(int x,int y) {
		for(; x; x-=x&-x)tr[x]+=y;
	}
	int ask(int x) {
		int s=0;
		for(; x<=n; x+=x&-x)s+=tr[x];
		return s;
	}
} tr;

signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read(),V=read();
	For(i,1,n) a[i] = read(), b[i] = read();
	For(i,1,m) a2[i] = read(), b2[i] = read();
	tr.init(300005);
	int sum=0,k=0;
	For(i,1,m) {
		if(i == 1 || a2[i] != a2[i - 1]) {
			sum=0;
			for(int j = 1; j <= V; j += a2[i]) sum+=tr.ask(j);
		}
		while(sum < b2[i] && k < n) {
			++k;
			sum+=(b[k] + a2[i] - 1) / a2[i] * a[k];
			tr.add(b[k],a[k]);
		}
		if(sum >= b2[i]) cout << k << "\n";
		else cout << -1 << "\n";
	}
	return 0;
}
