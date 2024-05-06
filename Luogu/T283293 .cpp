#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000001],b[10000001];
long long sum=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&a[i],&b[i]);
		sum+=a[i];
		sum+=b[i]; 
	} 
	cout<<sum;
	return 0;
}
