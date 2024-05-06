#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000005];
int main() {
	scanf("%d%d",&n,&k);
	while(k--){
		int A,B;
		scanf("%d%d",&A,&B);
		for(register int i=A;i<=B;i++) a[i]++;
	}
	sort(a+1,a+n+1);
	cout<<a[n/2+1];
    return 0;
}
