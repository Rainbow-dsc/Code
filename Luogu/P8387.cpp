#include <bits/stdc++.h>
using namespace std;
long long n,a[100005];
int main(){
    scanf("%d",&n);
    for(long long i=1;i<=n;i++) scanf("%d",&a[i]);
    int i=1,p=1,q=1;
    sort(a+1,a+n+1);
    int sum=0;
    long long ans=a[1]*a[2]*a[3];
    while(1){
    	if(i==n+1) break;
    	if(p==n+1){
    		i++;
    		p=0;
    		q=0;
		}
		if(q==n+1){
			p++;
			q=0;
		}
		if(a[i]*a[p]*a[q]==ans){
			q++;
			sum++;
		}
	}
	printf("%d",sum);
    return 0;
}
