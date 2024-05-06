#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
struct aa{
	int d,s;
}a[105];
bool cmp(aa x,aa y) {
	return x.d<y.d;
}
signed main() {
	scanf("%lld",&t);
	while(t--) {
		int maxd=0,maxi=0,k;
		bool flag=false;
		int n;
		scanf("%lld",&n);
		for(int i=1; i<=n; i++)  {
			scanf("%lld%lld",&a[i].d,&a[i].s);
		}
		sort(a+1,a+n+1,cmp);
		if(a[n].s>=2) k=a[n].d+a[n].s/2;
		else k=a[n].d+a[n].s/2-1;
		int i=1;
		while(k>=1) {
			while(i<=n) {
				if(k>a[i].d+a[i].s/2-1) {
					k--;
					flag=true;
					i=1;
				} else i++;
			}
			if(flag==false) {
				printf("%lld\n",k);
				break;
			}
		}
	}
	return 0;
}

