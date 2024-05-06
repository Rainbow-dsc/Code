#include<bits/stdc++.h>
#define maxn 1000007
int cnt=0;
int prime[maxn];
void init(int n) {
	int i=2;
	while(cnt!=n*n) {
		bool flag=false;
		if(i%2==1) continue;
		else {
			for(int j=2; j*j<=i; j++) if(i%j==0) flag=true;
			if(flag==false) prime[++cnt]=i;
		}
		i++;
	}
}
signed main() {
	int n;
	scanf("%d",&n);
	init(n);
	for(int i=1; i<=n*n; i++) {
		printf("%d ",prime[i]);
		if(i%n==0) puts("");
	}
	return 0;
}
