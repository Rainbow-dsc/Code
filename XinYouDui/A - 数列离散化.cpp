#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,n,a[100001],t[100001];
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			t[j]=a[j];
		}
		sort(t+1,t+n+1);
		int m=unique(t+1,t+n+1)-t+1;
		for(int k=1;k<=n;k++) a[k]=lower_bound(t+1,t+m+1,a[k])-t;
		for(int p=1;p<=n;p++) printf("%d ",a[p]);
	}
	return 0;
} 
