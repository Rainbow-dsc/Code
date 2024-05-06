#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		int sum=0;
		for(int j=1;j<i;j++) if(a[j]<a[i]) sum++;
		printf("%d ",sum);
	}
	return 0;
}
