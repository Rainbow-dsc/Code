#include<bits/stdc++.h>
using namespace std;
int n,a[1000001];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	float sum=0;
	for(int i=2;i<=n-1;i++) sum+=a[i];
	printf("%.2lf",sum/(n-2));
	return 0;
}
