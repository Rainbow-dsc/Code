#include<bits/stdc++.h>
#define int long long
#define maxn 1000007
int cnt=0;
int prime[maxn];
void init(int n) {
	for(int i=3;i<=n;i++) {
		bool flag=false;
		for(int j=2;j*j<=n;j++) {
			if(i%j==0) flag=true;
		}
		if(flag==false&&i%2==1) prime[++cnt]=i;
	}
}
signed main(){
	int n;
    scanf("%lld",&n);
    init(n);
    for(int i=1;i<=n*n;i++) {
    	printf("%lld ",prime[i]);
    	if(i%n==0) puts("");
	}
    return 0;
}
