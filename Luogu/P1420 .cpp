#include<bits/stdc++.h>
using namespace std;
int n,a[100001],sum[10000001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int k=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]==1) sum[k]++;
		else k++;
	}
	sort(sum+1,sum+k+1);
	cout<<sum[k]+1;
	return 0;
}
