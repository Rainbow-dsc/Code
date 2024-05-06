#include<bits/stdc++.h>
using namespace std;
bool u(int x) {
	if(x<=1) return false;
	else {
		for(int i=2; i<x; i++) 
			if(x%i==0) 
				return false;
	}
	return true;
}
int L;
int main() {
	scanf("%d",&L);
	int sum=0,ans=0;
	for(int i=1;i<=L;i++){
		if(u(i)==true&&ans+i<=L) {
			ans+=i;
			printf("%d\n",i);
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}
