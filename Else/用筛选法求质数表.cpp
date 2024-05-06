#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    a[1]=1;	
    for(int i=2;i<=1000;i++){
		if(a[i]==0)
	   	for(int j=2*i;j<=1000;j+=i)
	   		a[j]=1;
	}
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
    	if(a[i]==0)
        cout<<i<<" ";
    }
    return 0;
}

