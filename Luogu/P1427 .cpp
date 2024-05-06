#include<bits/stdc++.h>
using namespace std;
int n,a[1000001];
int main(){
	int i=1;
	while(1){
		scanf("%d",&a[i]);
		if(a[i]==0) break;
		i++;
	}
	for(int j=i-1;j>=1;j--) printf("%d ",a[j]);
	return 0;
}
