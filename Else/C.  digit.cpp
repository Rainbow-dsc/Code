#include<bits/stdc++.h>
#define int __int128
#define mod __int128(1e22)
using namespace std;
int T;
char t,str[100];
int a[]= {6,6,2,6,4,4,4,8,4,6},b[]= {6,8,4,2};
inline void read(__int128 &n) {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	n=x*f;
}
inline void print(__int128 n) {
	if(n<0) {
		putchar('-');
		n*=-1;
	}
	if(n>9) print(n/10);
	putchar(n % 10 + '0');
}
signed main() {
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	read(T);
	while(T--) {
		int k,n,s=1,p=1,r=1;
		read(n);
		read(k);
		if(k==1) {
			while(n) s=s*a[n%10]*b[(n=n/5)%4]%10;
			print(s);
		} else {
			for(int i=1; i<=n; i++) {
				s=s*i;
				while(s%10==0) s/=10;
				s=s%mod;
			}
			for(int i=0; i<k; i++) {
				if(s) {
					str[i]=s%10+48;
					s/=10;
				} else str[i]='0';
			}
			for(int i=k-1; i>=0; i--) cout<<str[i];
		}
		puts("");
	}
	return 0;
}
